/**
 **************************************************************************************************
 * @file        gui_base.h
 * @author
 * @version    v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#ifndef _GUI_BASE_H_
#define _GUI_BASE_H_

/**
 * @addtogroup    XXX 
 * @{ 
 */

/**
 * @addtogroup    gui_base_Modules 
 * @{  
 */
#include "gui_conf.h"
/**
 * @defgroup      gui_base_Exported_Macros 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_base_Exported_Constants
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_base_Exported_Types 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_base_Exported_Variables 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_base_Exported_Functions 
 * @{  
 */
void BSP_LCD_SendStrings(uint8_t *str);
void BSP_LCD_SendUint8(uint8_t value);
void BSP_LCD_SendUint16(uint16_t value);
void BSP_LCD_SendUint32(uint32_t value);
void BSP_LCD_SendUint16N(uint16_t *pData,uint16_t count);
void BSP_LCD_SendUint8N(uint8_t *pData,uint16_t count);
void GUI_SendHeadCMD();
void GUI_SendEndCMD();

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
