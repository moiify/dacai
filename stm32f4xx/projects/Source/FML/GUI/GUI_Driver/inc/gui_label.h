/**
 **************************************************************************************************
 * @file        gui_label.h
 * @author
 * @version    v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#ifndef _GUI_LABEL_H_
#define _GUI_LABEL_H_

/**
 * @addtogroup    XXX 
 * @{ 
 */

/**
 * @addtogroup    gui_label_Modules 
 * @{  
 */

/**
 * @defgroup      gui_label_Exported_Macros 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_label_Exported_Constants
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_label_Exported_Types 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_label_Exported_Variables 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_label_Exported_Functions 
 * @{  
 */
void GUI_LABEL_SetSpace(uint8_t x_w, uint8_t y_w);
void GUI_LABEL_SetFontRegion(uint8_t enable,uint16_t width,uint16_t height);
void GUI_LABEL_SetFilterColor(uint16_t fillcolor_dwon, uint16_t fillcolor_up);
void GUI_LABEL_DisFilter(uint16_t x, uint16_t y,uint8_t back,uint8_t font,uint8_t *strings );
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
