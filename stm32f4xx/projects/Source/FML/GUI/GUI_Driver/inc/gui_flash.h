/**
 **************************************************************************************************
 * @file        gui_flash.h
 * @author
 * @version    v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#ifndef _GUI_FLASH_H_
#define _GUI_FLASH_H_

/**
 * @addtogroup    XXX 
 * @{ 
 */

/**
 * @addtogroup    gui_flash_Modules 
 * @{  
 */

/**
 * @defgroup      gui_flash_Exported_Macros 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_flash_Exported_Constants
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_flash_Exported_Types 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_flash_Exported_Variables 
 * @{  
 */
extern void (*GUI_FLASHW_CallBack)(uint8_t status);
extern void (*GUI_FLASHR_CallBack)(uint8_t status,uint8_t *data,uint16_t length);
/**
 * @}
 */

/**
 * @defgroup      gui_flash_Exported_Functions 
 * @{  
 */
void GUI_Flash_BeginSaveControl(uint32_t version,uint32_t address);
void GUI_Flash_SaveControl(uint16_t screen_id,uint16_t control_id);
void GUI_Flas_hEndSaveControl();
void GUI_Flash_RestoreControl(uint32_t version,uint32_t address);
void GUI_WriteUserFlash(uint32_t startAddress,uint16_t length,uint8_t *_data);
void GUI_ReadUserFlash(uint32_t startAddress,uint16_t length);
void GUI_SetFlashWCallback(void (*recv)(uint8_t status));
void GUI_SetFlashRCallback(void (*recv)(uint8_t status,uint8_t *data,uint16_t length));
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
