/**
 **************************************************************************************************
 * @file        gui_sdcard.h
 * @author
 * @version    v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#ifndef _GUI_SDCARD_H_
#define _GUI_SDCARD_H_

/**
 * @addtogroup    XXX 
 * @{ 
 */

/**
 * @addtogroup    gui_sdcard_Modules 
 * @{  
 */

/**
 * @defgroup      gui_sdcard_Exported_Macros 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_sdcard_Exported_Constants
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_sdcard_Exported_Types 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_sdcard_Exported_Variables 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_sdcard_Exported_Functions 
 * @{  
 */
void GUI_SD_IsInsert(void);
void GUI_SD_CreateFile(uint8_t *filename,uint8_t mode);
void GUI_SD_CreateFileByTime(uint8_t *ext);
void GUI_SD_WriteFile(uint8_t *buffer,uint16_t dlc);
void GUI_SD_ReadFile(uint32_t offset,uint16_t dlc);
void GUI_SD_GetFileSize();
void GUI_SD_CloseFile();
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
