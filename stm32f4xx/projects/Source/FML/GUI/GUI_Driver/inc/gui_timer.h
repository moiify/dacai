/**
 **************************************************************************************************
 * @file        gui_timer.h
 * @author
 * @version    v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#ifndef _GUI_TIMER_H_
#define _GUI_TIMER_H_

/**
 * @addtogroup    XXX 
 * @{ 
 */

/**
 * @addtogroup    gui_timer_Modules 
 * @{  
 */

/**
 * @defgroup      gui_timer_Exported_Macros 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_timer_Exported_Constants
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_timer_Exported_Types 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_timer_Exported_Variables 
 * @{  
 */
extern void (*GUI_TIMER_CallBack)(uint16_t screen_id, uint16_t control_id);
/**
 * @}
 */

/**
 * @defgroup      gui_timer_Exported_Functions 
 * @{  
 */
void GUI_Timer_Set(uint16_t screen_id,uint16_t control_id,uint32_t timeout);
void GUI_Timer_Start(uint16_t screen_id,uint16_t control_id);
void GUI_Timer_Stop(uint16_t screen_id,uint16_t control_id);
void GUI_Timer_Pause(uint16_t screen_id,uint16_t control_id);
void GUI_SetTimerCallback(void (*recv)(uint16_t screen_id, uint16_t control_id));
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
