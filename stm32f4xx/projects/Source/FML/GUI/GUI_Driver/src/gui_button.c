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
#include "gui_base.h"
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
void (*GUI_BUTTON_State_CallBack)(uint16_t screen_id, uint16_t control_id, uint8_t  state);
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

/**
 * @brief    设置按钮状态
 * @param    screen_id:uint16_t 画面ID
 * @param    control_id:uint16_t 控件ID
 * @param    state:uint8_t 按钮状态	0表示弹起 1表示按下
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
void GUI_SetButtonCallback(void (*recv)(uint16_t screen_id, uint16_t control_id, uint8_t  state))
{   
    GUI_BUTTON_State_CallBack=recv;
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

