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
void GUI_TEXT_SetSpace(uint8_t x_w, uint8_t y_w);
void GUI_TEXT_SetFontRegion(uint8_t enable,uint16_t width,uint16_t height);
void GUI_TEXT_SetFilterColor(uint16_t fillcolor_dwon, uint16_t fillcolor_up);
void GUI_TEXT_DisFilter(uint16_t x, uint16_t y,uint8_t back,uint8_t font,uint8_t *strings );
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
