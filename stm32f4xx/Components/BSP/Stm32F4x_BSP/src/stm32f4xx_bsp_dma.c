/**
**************************************************************************************************
* @file        stm32f4xx_bsp_dma.c
* @author
* @version   v0.1.0
* @date        
* @brief
**************************************************************************************************
* @attention
*
**************************************************************************************************
*/
#include "stm32f4xx_bsp_dma.h"
#include "stm32_bsp_conf.h"
/**
* @addtogroup    XXX 
* @{  
*/

/**
* @addtogroup    stm32f4xx_bsp_dma_Modules 
* @{  
*/

/**
* @defgroup      stm32f4xx_bsp_dma_IO_Defines 
* @brief         
* @{  
*/

/**
* @}
*/

/**
* @defgroup      stm32f4xx_bsp_dma_Macros_Defines 
* @brief         
* @{  
*/

/**
* @}
*/
/**
* @defgroup      stm32f4xx_bsp_dma_Constants_Defines 
* @brief         
* @{  
*/
/**
* @}
*/

/**
* @defgroup      stm32f4xx_bsp_dma_Private_Types
* @brief         
* @{  
*/

/**
* @}
*/

/**
* @defgroup      stm32f4xx_bsp_dma_Private_Variables 
* @brief         
* @{  
*/

/**
* @}
*/

/**
* @defgroup      stm32f4xx_bsp_dma_Public_Variables 
* @brief         
* @{  
*/

/**
* @}
*/

/**
* @defgroup      stm32f4xx_bsp_dma_Private_FunctionPrototypes 
* @brief         
* @{  
*/

/**
* @}
*/

/**
* @defgroup      stm32f4xx_bsp_dma_Functions 
* @brief         
* @{  
*/
void  BSP_DMA_USART_StructInit(uint8_t BSP_USARTx,BSP_DMA_Config_t * config )
{   
    //uint8_t s_address[1];
    
    DMA_InitTypeDef DMA_InitStructure;
    
    if(BSP_USARTx==BSP_USART1)
    {

    }
    if(BSP_USARTx==BSP_USART2)
    {
        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE);
        DMA_DeInit(DMA1_Stream5);
        DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable ;
        DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_1QuarterFull ;
        DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single ;
        DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
        DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
        DMA_InitStructure.DMA_PeripheralBaseAddr =(uint32_t) (&(USART2->DR)) ;
        DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
        DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
        DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
        DMA_InitStructure.DMA_Priority = DMA_Priority_High;
//        /* Configure TX DMA */
//        DMA_InitStructure.DMA_BufferSize = 0;
//        DMA_InitStructure.DMA_Channel = USARTx_TX_DMA_CHANNEL ;
//        DMA_InitStructure.DMA_DIR = DMA_DIR_MemoryToPeripheral ;
//        DMA_InitStructure.DMA_Memory0BaseAddr =(uint32_t)s_address ;
//        DMA_Init(USARTx_TX_DMA_STREAM,&DMA_InitStructure);
        /* Configure RX DMA */
        DMA_InitStructure.DMA_BufferSize = BSP_USART2_RXBUF_SIZE;
        DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
        DMA_InitStructure.DMA_Channel = DMA_Channel_4 ;
        DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory ;
        DMA_InitStructure.DMA_Memory0BaseAddr =(uint32_t)config->USART2_RX_MemAddr; 
        DMA_Init(DMA1_Stream5,&DMA_InitStructure);
		DMA_Cmd(DMA1_Stream5, ENABLE);
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

