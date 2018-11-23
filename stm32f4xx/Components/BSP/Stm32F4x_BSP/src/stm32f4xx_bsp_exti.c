/**
 **************************************************************************************************
 * @file        stm32f4xx_bsp_exti.c
 * @author
 * @version   v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#include "stm32_bsp_conf.h"
#include "clog.h"
#include "fingerprint_process.h"
/**
 * @addtogroup    XXX 
 * @{  
 */

/**
 * @addtogroup    stm32f4xx_bsp_exti_Modules 
 * @{  
 */

/**
 * @defgroup      stm32f4xx_bsp_exti_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      stm32f4xx_bsp_exti_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      stm32f4xx_bsp_exti_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      stm32f4xx_bsp_exti_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      stm32f4xx_bsp_exti_Private_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      stm32f4xx_bsp_exti_Public_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      stm32f4xx_bsp_exti_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      stm32f4xx_bsp_exti_Functions 
 * @brief         
 * @{  
 */
void BSP_EXTI_Open(uint8_t BSP_EXTIx)
{
	EXTI_InitTypeDef   EXTI_InitStructure;
	GPIO_InitTypeDef   GPIO_InitStructure;
	NVIC_InitTypeDef   NVIC_InitStructure;
    switch(BSP_EXTIx)
    {
        case BSP_EXTI0:
        {
            
            /* Enable GPIOA clock */
            RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
            /* Enable SYSCFG clock */
            RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
            
            /* Configure PA0 pin as input floating */
            GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
            GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
            GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
            GPIO_Init(GPIOA, &GPIO_InitStructure);
            
            /* Connect EXTI Line0 to PA0 pin */
            SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);
            
            /* Configure EXTI Line0 */
            EXTI_InitStructure.EXTI_Line = EXTI_Line0;
            EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
            EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
            EXTI_InitStructure.EXTI_LineCmd = ENABLE;
            EXTI_Init(&EXTI_InitStructure);
            
            /* Enable and set EXTI Line0 Interrupt to the lowest priority */
            NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
            NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x0F;
            NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0F;
            NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
            NVIC_Init(&NVIC_InitStructure);
        }
        default :
        {
            break;
        }
    }
}
void BSP_EXTI_IRQHandler(uint8_t BSP_EXTIx)
{
    switch (BSP_EXTIx)
    {
        case BSP_EXTI0:
        {   
            EXTI_ClearITPendingBit(EXTI_Line0);
            Finger_Compare_Print();
            DEBUG("Finger press detected!\r\n");
            break;
        }
        default:
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

