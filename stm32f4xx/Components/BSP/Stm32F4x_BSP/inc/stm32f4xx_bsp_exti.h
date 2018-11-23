/**
 **************************************************************************************************
 * @file        stm32f4xx_bsp_exti.h
 * @author
 * @version    v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#ifndef _STM32F4XX_BSP_EXTI_H_
#define _STM32F4XX_BSP_EXTI_H_

/**
 * @addtogroup    XXX 
 * @{ 
 */

/**
 * @addtogroup    stm32f4xx_bsp_exti_Modules 
 * @{  
 */

/**
 * @defgroup      stm32f4xx_bsp_exti_Exported_Macros 
 * @{  
 */
#define BSP_EXTI0   0
/**
 * @}
 */

/**
 * @defgroup      stm32f4xx_bsp_exti_Exported_Constants
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      stm32f4xx_bsp_exti_Exported_Types 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      stm32f4xx_bsp_exti_Exported_Variables 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      stm32f4xx_bsp_exti_Exported_Functions 
 * @{  
 */
void BSP_EXTI_Open(uint8_t BSP_EXTIx);
void BSP_EXTI_IRQHandler(uint8_t BSP_EXTIx);
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
