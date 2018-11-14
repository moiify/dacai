/**
 **************************************************************************************************
 * @file        gui_meter.c
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
#include "gui_meter.h"

/**
 * @addtogroup    XXX 
 * @{  
 */

/**
 * @addtogroup    gui_meter_Modules 
 * @{  
 */

/**
 * @defgroup      gui_meter_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_meter_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_meter_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_meter_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_meter_Private_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_meter_Public_Variables 
 * @brief         
 * @{  
 */
void (*GUI_METER_CallBack)(uint16_t screen_id,uint16_t control_id,uint32_t value);
/**
 * @}
 */

/**
 * @defgroup      gui_meter_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_meter_Functions 
 * @brief         
 * @{  
 */
/*! 
*  \brief     �����Ǳ�ֵ
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  value ��ֵ
*/
void GUI_Meter_Value(uint16_t screen_id,uint16_t control_id,uint32_t value)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x10);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint32(value);
    GUI_SendEndCMD();
}
void GUI_SetMeterCallback(void (*recv)(uint16_t screen_id,uint16_t control_id,uint32_t value))
{
    GUI_METER_CallBack=recv;
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

