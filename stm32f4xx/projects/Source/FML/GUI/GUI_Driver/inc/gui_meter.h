/**
 **************************************************************************************************
 * @file        gui_meter.h
 * @author
 * @version    v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#ifndef _GUI_METER_H_
#define _GUI_METER_H_

/**
 * @addtogroup    XXX 
 * @{ 
 */

/**
 * @addtogroup    gui_meter_Modules 
 * @{  
 */

/**
 * @defgroup      gui_meter_Exported_Macros 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_meter_Exported_Constants
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_meter_Exported_Types 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_meter_Exported_Variables 
 * @{  
 */
extern void (*GUI_METER_CallBack)(uint16_t screen_id,uint16_t control_id,uint32_t value);
/**
 * @}
 */

/**
 * @defgroup      gui_meter_Exported_Functions 
 * @{  
 */
void GUI_Meter_Value(uint16_t screen_id,uint16_t control_id,uint32_t value);
void GUI_SetMeterCallback(void (*recv)(uint16_t screen_id,uint16_t control_id,uint32_t value));
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
