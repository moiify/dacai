/**
 **************************************************************************************************
 * @file        stm32f4xx_bsp_usart.c
 * @author
 * @version   v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#include "self_def.h"
#include "gui_cmd_queue.h"
#include "finger_task.h"
#include "stm32_bsp_conf.h"


//#include "stm32f4xx_bsp_usart.h"
/**
 * @addtogroup    XXX 
 * @{  
 */

/**
 * @addtogroup    stm32f4xx_bsp_usart_Modules 
 * @{  
 */

/**
 * @defgroup      stm32f4xx_bsp_usart_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      stm32f4xx_bsp_usart_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      stm32f4xx_bsp_usart_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      stm32f4xx_bsp_usart_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      stm32f4xx_bsp_usart_Private_Variables 
 * @brief         
 * @{  
 */
//static uint8_t USART1_Tx_Buf[BSP_USART1_TXBUF_SIZE];
static uint8_t USART1_Rx_Buf[BSP_USART1_RXBUF_SIZE];
static uint8_t USART2_Rx_Buf[BSP_USART2_RXBUF_SIZE];
static USART_Buf_t USART1_ReceiveCache =
{
	.pData = USART1_Rx_Buf,
	.In = 0,
	.Out = 0,
	.Count = 0,
	.Size = BSP_USART1_RXBUF_SIZE,
};
static BSP_DMA_Config_t BSP_DMA_Config =
{
	.USART1_RX_MemAddr = (uint32_t)USART1_Rx_Buf,
	.USART2_RX_MemAddr = (uint32_t)USART2_Rx_Buf,
};
Finger_Queue_Cache_t Finger_Queue_Cache =
{
	.In = 0,
	.Out = 0,
	.Count = 0,
	.Size = sizeof(Finger_Queue_Cache.Buf) / sizeof(Finger_Queue_Cache.Buf[0]),
};
/**
 * @}
 */

/**
 * @defgroup      stm32f4xx_bsp_usart_Public_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      stm32f4xx_bsp_usart_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */
static void BSP_USART_ReadBytesDMA(uint8_t BSP_USARTx);
static void BSP_USART_ReadBytesIRQISR(uint8_t BSP_USARTx);

/**
 * @}
 */

/**
 * @defgroup      stm32f4xx_bsp_usart_Functions 
 * @brief         
 * @{  
 */

/**
 * @brief    ���ô���
 * @param    BSP_USARTx:uint8_t ���ںź궨��
 */

void BSP_USART_Open(uint8_t BSP_USARTx)
{
	switch (BSP_USARTx)
	{
		case BSP_USART1:
			{
				GPIO_InitTypeDef GPIO_InitStructure;
				USART_InitTypeDef USART_InitStructure;
				NVIC_InitTypeDef NVIC_InitStructure;
				/* Enable GPIO clock */
				RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
				/* Enable USART clock */
				RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
				/* Connect USART pins to AF7 */
				GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);
				GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);

				/* Configure USART Tx and Rx as alternate function push-pull */
				GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
				GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
				GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
				GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
				GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
				GPIO_Init(GPIOA, &GPIO_InitStructure);
				GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
				GPIO_Init(GPIOA, &GPIO_InitStructure);

				/* USART configuration */
				USART_DeInit(USART1);
				USART_InitStructure.USART_BaudRate = 115200;
				USART_InitStructure.USART_WordLength = USART_WordLength_8b;
				USART_InitStructure.USART_StopBits = USART_StopBits_1;
				USART_InitStructure.USART_Parity = USART_Parity_No;
				USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
				USART_InitStructure.USART_Mode =   USART_Mode_Tx | USART_Mode_Rx;
				USART_Init(USART1, &USART_InitStructure);
                
				/* Enable USART Interrupt */
                NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
				NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
				NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =1;
				NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
                NVIC_InitStructure.NVIC_IRQChannelCmd =ENABLE;
				NVIC_Init(&NVIC_InitStructure);
				USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);

				/* Enable USART */
				USART_Cmd(USART1, ENABLE);
				break;
			}
		case BSP_USART2 :
			{
				GPIO_InitTypeDef GPIO_InitStructure;
				USART_InitTypeDef USART_InitStructure;
				NVIC_InitTypeDef NVIC_InitStructure;
				/* Enable GPIO clock */
				RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
				/* Enable USART clock */
				RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
				/* Connect USART pins to AF7 */
				GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);
				GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);

				/* Configure USART Tx and Rx as alternate function push-pull */
				GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
				GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
				GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
				GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
				GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
				GPIO_Init(GPIOA, &GPIO_InitStructure);
				GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
				GPIO_Init(GPIOA, &GPIO_InitStructure);

				/* USART configuration */
				USART_DeInit(USART2);
				USART_InitStructure.USART_BaudRate = 57600;
				USART_InitStructure.USART_WordLength = USART_WordLength_8b;
				USART_InitStructure.USART_StopBits = USART_StopBits_1;
				USART_InitStructure.USART_Parity = USART_Parity_No;
				USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
				USART_InitStructure.USART_Mode =   USART_Mode_Tx | USART_Mode_Rx;
				USART_Init(USART2, &USART_InitStructure);
                
				/* Enable USART Interrupt */
				NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
				NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
				NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
				NVIC_InitStructure.NVIC_IRQChannelSubPriority = 4;
                NVIC_InitStructure.NVIC_IRQChannelCmd =ENABLE;
				NVIC_Init(&NVIC_InitStructure);
				USART_ITConfig(USART2,USART_IT_IDLE, ENABLE);
                
				/* DMA config */
				BSP_DMA_USART_StructInit(BSP_USART2, &BSP_DMA_Config);
				USART_DMACmd(USART2, USART_DMAReq_Rx, ENABLE);
				//		/* check (or wait until) the DMA Stream is effectively enabled */
				//		while (DMA_GetFlagStatus(USARTx_RX_DMA_STREAM, DMA_FLAG_TCIF2) == RESET);
				//		DMA_ClearFlag(USARTx_RX_DMA_STREAM, USARTx_RX_DMA_FLAG_TCIF);
                
				/* Enable USART */
				USART_Cmd(USART2, ENABLE);
                USART_GetFlagStatus(USART2, USART_FLAG_TC);    //
                break;
			}
	}
}
/**
 * @brief    ����д�ֽ�
 * @param    BSP_USARTx:uint8_t ���ں�
 * @param    pBuf:uint8_t* �����ֽ�
 * @param    length:uint16_t �ֽڳ���
 */

void  BSP_USART_WriteBytes(uint8_t BSP_USARTx, uint8_t *pBuf, uint16_t length)
{
	switch (BSP_USARTx)
	{
		case BSP_USART1:
			{
				uint16_t i = 0;
				while (i < length)
				{
					BSP_USART_WriteByte(BSP_USART1, *(pBuf + (i++)));
				}
				break;
			}
		case BSP_USART2:
			{   
                uint16_t i = 0;
				while (i < length)
				{
					BSP_USART_WriteByte(BSP_USART2, *(pBuf + (i++)));
				}
				break;
			}
	}
}
/**
 * @brief    ����д�����ֽ�
 * @param    BSP_USARTx:uint8_t ���ں�
 * @param    c:uint8_t �ֽ�����
 */

void  BSP_USART_WriteByte(uint8_t BSP_USARTx, uint8_t c)
{
	switch (BSP_USARTx)
	{
		case BSP_USART1:
        {
            USART_SendData(USART1, c);
            while ((USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET)); //wait for transmit complete
            break;
        }
        case BSP_USART2:
        {   
            USART_SendData(USART2,c);
            while((USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET));//wait for transmit complete
            break;
        }
        
	}
}

/**
 * @brief    ���ڶ�����
 * @param    BSP_USARTx:uint8_t ���ں�
 * @param    pBuf:uint8_t* ���ݴ���������ַ
 * @param    count:uint16_t Ҫ��ȡ�ĳ���
 * @retval   uint16_t: ʵ�ʶ�ȡ�ĳ���
 */

uint16_t BSP_USART_ReadBytes(uint8_t BSP_USARTx, uint8_t *pBuf, uint16_t count)
{
	uint16_t read_count = 0;
	uint8_t *p = pBuf;
	if (BSP_USARTx == BSP_USART1)
	{
		while (count--)
		{
			if (USART1_ReceiveCache.Out == USART1_ReceiveCache.In)
			{
				return read_count;
			}
			*p++ = USART1_ReceiveCache.pData[USART1_ReceiveCache.Out++];
			USART1_ReceiveCache.Out %= USART1_ReceiveCache.Size;
			read_count++;
		}
	}
	return read_count;
}
/**
 * @brief    �����жϴ�����
 * @param    BSP_USARTx:uint8_t ���ں�
 */

void  BSP_USART_IRQHandler(uint8_t BSP_USARTx)
{   
    
	if (USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) //����1�����ж�
	{
		BSP_USART_ReadBytesIRQISR(BSP_USARTx);
	}
	if (USART_GetITStatus(USART1, USART_IT_ORE_RX) != RESET) // ��� ORE ��־
	{
		//USART_ClearFlag(USART1,USART_FLAG_ORE);
	    USART_ReceiveData(USART1);
	}
	if (USART_GetITStatus(USART2, USART_IT_IDLE) != RESET) //����2�����ж�
	{   
		BSP_USART_ReadBytesDMA(BSP_USARTx);
	}
}
/**
 * @brief    ���ڽ����жϽ��մ�����
 * @param    BSP_USARTx:uint8_t ���ں�
 */

static void BSP_USART_ReadBytesIRQISR(uint8_t BSP_USARTx)
{
	if (BSP_USARTx == BSP_USART1)
	{
//		if (USART1_ReceiveCache.Count < USART1_ReceiveCache.Size)
//		{
			USART1_ReceiveCache.pData[USART1_ReceiveCache.In++] = USART_ReceiveData(USART1);
			USART1_ReceiveCache.In %= USART1_ReceiveCache.Size;
//			USART1_ReceiveCache.Count++;
//		}
        
	}
}
/**
 * @brief    DMA������ �������� ����д��
 * @param    BSP_USARTx:uint8_t ���ں�
 */

static void BSP_USART_ReadBytesDMA(uint8_t BSP_USARTx)
{
	switch (BSP_USARTx)
	{   
		case BSP_USART2:
        {
            uint16_t len = 0;
            len=USART2->SR;
            len=USART2->DR;   //ͨ�����Ĵ������idle�жϱ�־λ��len��ʱ������
            if (Finger_Queue_Cache.Count < Finger_Queue_Cache.Size)
            {
                len = BSP_USART2_RXBUF_SIZE - DMA_GetCurrDataCounter(DMA1_Stream5);
                if(len>0)
                {
                    memcpy(Finger_Queue_Cache.Buf[Finger_Queue_Cache.In].buf,USART2_Rx_Buf,len);
                    Finger_Queue_Cache.Buf[Finger_Queue_Cache.In].len=len;
                    Finger_Queue_Cache.In++;
                    Finger_Queue_Cache.In %= Finger_Queue_Cache.Size;
                    Finger_Queue_Cache.Count++;
                    FingerTask_Send_Event(FINGER_TASK_ACK_EVENT);
                }
            } 
            DMA_Cmd(DMA1_Stream5, DISABLE);//��ʧ�� ����������쳣
            DMA1_Stream5->M0AR =  (uint32_t)USART2_Rx_Buf;  //���� 
            DMA1_Stream5->NDTR = BSP_USART2_RXBUF_SIZE;
            DMA_Cmd(DMA1_Stream5, ENABLE);
            break;
        }
        default :
        {
            break;
        }
	}
}                
/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

