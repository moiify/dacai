/**
 **************************************************************************************************
 * @file        gui_menu.c
 * @author
 * @version   v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#include "gui_base.h"
#include "gui_menu.h"

/**
 * @addtogroup    XXX 
 * @{  
 */

/**
 * @addtogroup    gui_menu_Modules 
 * @{  
 */

/**
 * @defgroup      gui_menu_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_menu_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_menu_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_menu_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_menu_Private_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_menu_Public_Variables 
 * @brief         
 * @{  
 */
void (*GUI_MENU_CallBack)(uint16_t screen_id, uint16_t control_id, uint8_t item, uint8_t state);
/**
 * @}
 */

/**
 * @defgroup      gui_menu_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_menu_Functions 
 * @brief         
 * @{  
 */
void GUI_SetMenuCallback(void (*recv)(uint16_t screen_id, uint16_t control_id, uint8_t item, uint8_t state))
{
    GUI_MENU_CallBack=recv;
}
/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

