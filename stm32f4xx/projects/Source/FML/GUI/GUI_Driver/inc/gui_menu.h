/**
 **************************************************************************************************
 * @file        gui_menu.h
 * @author
 * @version    v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#ifndef _GUI_MENU_H_
#define _GUI_MENU_H_

/**
 * @addtogroup    XXX 
 * @{ 
 */

/**
 * @addtogroup    gui_menu_Modules 
 * @{  
 */

/**
 * @defgroup      gui_menu_Exported_Macros 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_menu_Exported_Constants
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_menu_Exported_Types 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_menu_Exported_Variables 
 * @{  
 */
extern void (*GUI_MENU_CallBack)(uint16_t screen_id, uint16_t control_id, uint8_t item, uint8_t state);
/**
 * @}
 */

/**
 * @defgroup      gui_menu_Exported_Functions 
 * @{  
 */
void GUI_SetMenuCallback(void (*recv)(uint16_t screen_id, uint16_t control_id, uint8_t item, uint8_t state));
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
