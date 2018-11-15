/**
 **************************************************************************************************
 * @file        finger_task.h
 * @author
 * @version    v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#ifndef _FINGER_TASK_H_
#define _FINGER_TASK_H_

/**
 * @addtogroup    XXX 
 * @{ 
 */

/**
 * @addtogroup    finger_task_Modules 
 * @{  
 */
#include "osal.h"
/**
 * @defgroup      finger_task_Exported_Macros 
 * @{  
 */
#define FINGER_TASK_KEY_PROCESS_EVENT     0x0001
#define FINGER_TASK_LOOP_EVENT            0x0002
#define FINGER_TASK_SHELL_EVENT           0x0004
#define FINGER_TASK_OPEN_CMD_EVENT        0x0008
#define FINGER_TASK_CLOSE_CMD_EVENT       0x0010
/**
 * @}
 */

/**
 * @defgroup      finger_task_Exported_Constants
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      finger_task_Exported_Types 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      finger_task_Exported_Variables 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      finger_task_Exported_Functions 
 * @{  
 */
void FingerTask_Init(uint8_t taskId);
osal_event_t FingerTask_Process(uint8_t taskid,osal_event_t events);
void FingerTask_Send_Event(osal_event_t events);
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