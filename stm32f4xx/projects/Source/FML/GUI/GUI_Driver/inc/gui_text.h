/**
 **************************************************************************************************
 * @file        gui_text.h
 * @author
 * @version    v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#ifndef _GUI_TEXT_H_
#define _GUI_TEXT_H_

/**
 * @addtogroup    XXX 
 * @{ 
 */

/**
 * @addtogroup    gui_text_Modules 
 * @{  
 */

/**
 * @defgroup      gui_text_Exported_Macros 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_text_Exported_Constants
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_text_Exported_Types 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_text_Exported_Variables 
 * @{  
 */
extern void (*GUI_TEXT_StringUpdate_CallBack)(uint16_t screen_id, uint16_t control_id, uint8_t *str);
/**
 * @}
 */

/**
 * @defgroup      gui_text_Exported_Functions 
 * @{  
 */
void GUI_TEXT_SetText(uint16_t screen_id,uint16_t control_id,uint8_t *str);
void GUI_TEXT_GetValue(uint16_t screen_id,uint16_t control_id);
void GUI_TEXT_SetInt32(uint16_t screen_id,uint16_t control_id,uint32_t value,uint8_t sign,uint8_t fill_zero);
void GUI_TEXT_SetFloat(uint16_t screen_id,uint16_t control_id,float value,uint8_t precision,uint8_t show_zeros);
void GUI_SetTextCallback(void (*recv)(uint16_t screen_id, uint16_t control_id, uint8_t *str));
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
