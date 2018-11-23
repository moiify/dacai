/**
 **************************************************************************************************
 * @file        stm32f4xx_bsp_flash.h
 * @author
 * @version    v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#ifndef _STM32F4XX_BSP_FLASH_H_
#define _STM32F4XX_BSP_FLASH_H_

/**
 * @addtogroup    XXX 
 * @{ 
 */

/**
 * @addtogroup    stm32f4xx_bsp_flash_Modules 
 * @{  
 */

/**
 * @defgroup      stm32f4xx_bsp_flash_Exported_Macros 
 * @{  
 */
#define FLASH_START_ADDR    0x8000000
/**
 * @}
 */

/**
 * @defgroup      stm32f4xx_bsp_flash_Exported_Constants
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      stm32f4xx_bsp_flash_Exported_Types 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      stm32f4xx_bsp_flash_Exported_Variables 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      stm32f4xx_bsp_flash_Exported_Functions 
 * @{  
 */
void BSP_FLASH_ReadBytes(uint32_t addr,uint8_t *pBuf,uint16_t count);
void BSP_FLASH_WriteBytes(uint32_t addr,uint8_t *pBuf,uint16_t count);
void BSP_FLASH_EraseSector(uint16_t FLASH_Sector_x);
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
