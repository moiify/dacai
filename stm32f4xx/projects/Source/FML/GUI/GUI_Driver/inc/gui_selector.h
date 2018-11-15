/**
 **************************************************************************************************
 * @file        gui_selector.h
 * @author
 * @version    v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#ifndef _GUI_SELECTOR_H_
#define _GUI_SELECTOR_H_

/**
 * @addtogroup    XXX 
 * @{ 
 */

/**
 * @addtogroup    gui_selector_Modules 
 * @{  
 */

/**
 * @defgroup      gui_selector_Exported_Macros 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_selector_Exported_Constants
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_selector_Exported_Types 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_selector_Exported_Variables 
 * @{  
 */
extern void (*GUI_SELECTOR_CallBack)(uint16_t screen_id, uint16_t control_id, uint8_t  item);
/**
 * @}
 */

/**
 * @defgroup      gui_selector_Exported_Functions 
 * @{  
 */

/**
 * @}
 */
void GUI_SetSelectorCallback(void (*recv)(uint16_t screen_id, uint16_t control_id, uint8_t  item));
/**
 * @}
 */

/**
 * @}
 */
#endif
