/**
 **************************************************************************************************
 * @file        gui_selector.c
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
#include "gui_selector.h"

/**
 * @addtogroup    XXX 
 * @{  
 */

/**
 * @addtogroup    gui_selector_Modules 
 * @{  
 */

/**
 * @defgroup      gui_selector_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_selector_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_selector_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_selector_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_selector_Private_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_selector_Public_Variables 
 * @brief         
 * @{  
 */
void (*GUI_SELECTOR_CallBack)(uint16_t screen_id, uint16_t control_id, uint8_t  item);
/**
 * @}
 */

/**
 * @defgroup      gui_selector_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_selector_Functions 
 * @brief         
 * @{  
 */
void GUI_SetSelectorCallback(void (*recv)(uint16_t screen_id, uint16_t control_id, uint8_t  item))
{
    GUI_SELECTOR_CallBack=recv;
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

