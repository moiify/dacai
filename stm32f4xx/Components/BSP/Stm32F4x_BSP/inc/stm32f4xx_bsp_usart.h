/**
 **************************************************************************************************
 * @file        stm32f4xx_bsp_usart.h
 * @author
 * @version    v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#ifndef _STM32F4XX_BSP_USART_H_
#define _STM32F4XX_BSP_USART_H_
#include "self_def.h"
/**
 * @addtogroup    XXX 
 * @{ 
 */

/**
 * @addtogroup    stm32f4xx_bsp_usart_Modules 
 * @{  
 */

/**
 * @defgroup      stm32f4xx_bsp_usart_Exported_Macros 
 * @{  
 */
#define BSP_USART1      0
#define BSP_USART2      1
/**
 * @}
 */

/**
 * @defgroup      stm32f4xx_bsp_usart_Exported_Constants
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      stm32f4xx_bsp_usart_Exported_Types 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      stm32f4xx_bsp_usart_Exported_Variables 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      stm32f4xx_bsp_usart_Exported_Functions 
 * @{  
 */
void BSP_USART_Open(uint8_t BSP_USARTx);
void BSP_USART_IRQHandler(uint8_t BSP_USARTx);
void  BSP_USART_WriteBytes(uint8_t BSP_USARTx,uint8_t* pBuf,uint16_t length);
void  BSP_USART_WriteByte(uint8_t BSP_USARTx,uint8_t c);
/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */
#endif
