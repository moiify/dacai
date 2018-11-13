/**
 **************************************************************************************************
 * @file        gui_button.c
 * @author
 * @version   v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#include "gui_conf.h"
#include "gui_button.h"


/**
 * @addtogroup    XXX 
 * @{  
 */

/**
 * @addtogroup    gui_button_Modules 
 * @{  
 */

/**
 * @defgroup      gui_button_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_button_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_button_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_button_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_button_Private_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_button_Public_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_button_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_button_Functions 
 * @brief         
 * @{  
 */
/*! 
*  \brief     ÉèÖÃ°´Å¥×´Ì¬
*  \param  screen_id »­ÃæID
*  \param  control_id ¿Ø¼þID
*  \param  value °´Å¥×´Ì¬
*/
void GUI_BUTTON_SetState(uint16_t screen_id,uint16_t control_id,uint8_t state)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x10);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_WriteByte(state);
    GUI_SendEndCMD();
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

