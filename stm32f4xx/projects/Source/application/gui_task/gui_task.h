/**
 **************************************************************************************************
 * @file        gui_task.h
 * @author
 * @version    v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#ifndef _GUI_TASK_H_
#define _GUI_TASK_H_

/**
 * @addtogroup    XXX 
 * @{ 
 */

/**
 * @addtogroup    gui_task_Modules 
 * @{  
 */
#include "osal.h"
/**
 * @defgroup      gui_task_Exported_Macros 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_task_Exported_Constants
 * @{  
 */
#define GUI_TASK_KEY_PROCESS_EVENT     0x0001
#define GUI_TASK_LOOP_EVENT            0x0002
#define GUI_TASK_SHELL_EVENT           0x0004
#define GUI_TASK_OPEN_CMD_EVENT        0x0008
#define GUI_TASK_CLOSE_CMD_EVENT       0x0010
/**
 * @}
 */

/**
 * @defgroup      gui_task_Exported_Types 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_task_Exported_Variables 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_task_Exported_Functions 
 * @{  
 */
void GuiTask_Init(uint8_t taskId);
osal_event_t GuiTask_Process(uint8_t taskid,osal_event_t events);
void GuiTask_Send_Event(osal_event_t events);
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
