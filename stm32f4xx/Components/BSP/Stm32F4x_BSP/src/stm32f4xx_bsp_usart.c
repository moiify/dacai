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

/**
 * @}
 */

/**
 * @defgroup      stm32f4xx_bsp_usart_Functions 
 * @brief         
 * @{  
 */
void BSP_USART_Open(uint8_t BSP_USARTx)
{   
    if(BSP_USARTx==BSP_USART1)
    {
        GPIO_InitTypeDef GPIO_InitStructure;
        USART_InitTypeDef USART_InitStructure;
        NVIC_InitTypeDef NVIC_InitStructure;
        /* Enable GPIO clock */
        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA , ENABLE);
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
        USART_InitStructure.USART_Mode =   USART_Mode_Tx|USART_Mode_Rx;
        USART_Init(USART1, &USART_InitStructure);
        
        NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
        /* Enable USART Interrupt */
        NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
        NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
        NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
        NVIC_Init(&NVIC_InitStructure);
        USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);            
        
        /* Enable USART */
        USART_Cmd(USART1, ENABLE);
    }
}
void  BSP_USART_WriteBytes(uint8_t BSP_USARTx,uint8_t* pBuf,uint16_t length)
{   
    uint16_t i=0;
    while(i<length)
    {
        BSP_USART_WriteByte(BSP_USARTx,*(pBuf+(i++)));
    }
    
}
void  BSP_USART_WriteByte(uint8_t BSP_USARTx,uint8_t c )
{   
    if(BSP_USARTx==BSP_USART1)
    {
        USART_SendData(USART1,c);
//        while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
        while((USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET));//wait for transmit complete  
    }
}
void  BSP_USART_IRQHandler(uint8_t BSP_USARTx)
{
    if (USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
    {
        uint8_t data = USART_ReceiveData(USART1);
        GUI_Queue_Push(data);
    }
    if(USART_GetITStatus(USART1,USART_IT_ORE_RX)!= RESET) // ¼ì²é ORE ±êÖ¾
    {
        //USART_ClearFlag(USART1,USART_FLAG_ORE);
        USART_ReceiveData(USART1);
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

