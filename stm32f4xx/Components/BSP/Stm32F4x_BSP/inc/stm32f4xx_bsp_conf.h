/**
 **************************************************************************************************
 * @file        stm32f4xx_bsp_conf.h
 * @author
 * @version     V2.0.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#ifndef _STM32F4XX_BSP_CONF_H_
#define _STM32F4XX_BSP_CONF_H_
#include "stm32f4xx.h"
#include "stdio.h"

/**
 * @addtogroup    XXX 
 * @{ 
 */

/**
 * @addtogroup    stm32f4xx_bsp_conf_Modules 
 * @{  
 */

/**
 * @defgroup      stm32f4xx_bsp_conf_Exported_Macros 
 * @{  
 */
#define BSP_GPIO_MODULE_ENABLE          1
#define BSP_NVIC_MODULE_ENABLE          0
#define BSP_DMA_MODULE_ENABLE           0
#define BSP_SYSTICK_MODULE_ENABLE       1
#define BSP_USART_MODULE_ENABLE         1
#define BSP_EXTI_MODULE_ENABLE          0
#define BSP_FLASH_MODULE_ENABLE         0
#define BSP_SPI_MODULE_ENABLE           0
#define BSP_ADC_MODULE_ENABLE           0
#define BSP_RTC_MODULE_ENABLE           0
#define BSP_WDG_MODULE_ENABLE           0
#define BSP_TIM_MODULE_ENABLE           0
#define BSP_PWM_MODULE_ENABLE           0
#define BSP_I2CSW_MODULE_ENABLE         0

#if BSP_GPIO_MODULE_ENABLE == 1
#include "stm32f4xx_bsp_gpio.h"
#endif

#if BSP_NVIC_MODULE_ENABLE == 1
#include "stm32f4xx_bsp_nvic.h"
#endif

#if BSP_DMA_MODULE_ENABLE == 1
#include "stm32f4xx_bsp_dma.h"
#endif

#if BSP_USART_MODULE_ENABLE == 1
#include "stm32f4xx_bsp_usart.h"

#endif

#if BSP_SYSTICK_MODULE_ENABLE == 1
#include "stm32f4xx_bsp_systick.h"
#endif

#if BSP_EXTI_MODULE_ENABLE == 1
#include "stm32f4xx_bsp_exti.h"
#endif

#if BSP_FLASH_MODULE_ENABLE == 1
#include "stm32f4xx_bsp_flash.h"
#endif

#if BSP_SPI_MODULE_ENABLE == 1
#include "stm32f4xx_bsp_spi.h"
#endif

#if BSP_TIM_MODULE_ENABLE == 1
#include "stm32f4xx_bsp_timer.h"
#endif

#if BSP_ADC_MODULE_ENABLE == 1
#include "stm32f4xx_bsp_adc.h"
#endif

#if BSP_RTC_MODULE_ENABLE == 1
#include "stm32f4xx_bsp_rtc.h"
#endif

#if BSP_WDG_MODULE_ENABLE == 1
#include "stm32f4xx_bsp_wdg.h"
#endif

#if BSP_I2CSW_MODULE_ENABLE == 1
#include "stm32f4xx_bsp_i2c_sw.h"
#endif

#if BSP_PWM_MODULE_ENABLE == 1
#include "stm32f4xx_bsp_pwm.h"
#endif
/**
 * @}
 */

/**
 * @defgroup      stm32f4xx_bsp_conf_Exported_Constants
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      stm32f4xx_bsp_conf_Exported_Types 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      stm32f4xx_bsp_conf_Exported_Variables 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      stm32f4xx_bsp_conf_Exported_Functions 
 * @{  
 */

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
