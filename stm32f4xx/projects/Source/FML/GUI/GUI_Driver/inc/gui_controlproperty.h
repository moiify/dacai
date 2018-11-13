/**
 **************************************************************************************************
 * @file        gui_controlproperty.h
 * @author
 * @version    v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#ifndef _GUI_CONTROLPROPERTY_H_
#define _GUI_CONTROLPROPERTY_H_

/**
 * @addtogroup    XXX 
 * @{ 
 */

/**
 * @addtogroup    gui_controlproperty_Modules 
 * @{  
 */

/**
 * @defgroup      gui_controlproperty_Exported_Macros 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_controlproperty_Exported_Constants
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_controlproperty_Exported_Types 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_controlproperty_Exported_Variables 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_controlproperty_Exported_Functions 
 * @{  
 */

/**
 * @}
 */
void GUI_SetFocus(uint16_t screen_id,uint16_t control_id,uint8_t focus);
void GUI_SetVisiable(uint16_t screen_id,uint16_t control_id,uint8_t visible);
void GUI_SetControlEnable(uint16_t screen_id,uint16_t control_id,uint8_t enable);
void GUI_SetControlBackColor(uint16_t screen_id,uint16_t control_id,uint16_t color);
void GUI_SetControlForeColor(uint16_t screen_id,uint16_t control_id,uint16_t color);
void GUI_ShowPopupMenu(uint16_t screen_id,uint16_t control_id,uint8_t show,uint16_t focus_control_id);
void GUI_ShowKeyboard(uint8_t show,uint16_t x,uint16_t y,uint8_t type,uint8_t option,uint8_t max_len);
void GUI_SetLanguage(uint8_t ui_lang,uint8_t sys_lang);
/**
 * @}
 */

/**
 * @}
 */
#endif
