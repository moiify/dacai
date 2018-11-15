/**
 **************************************************************************************************
 * @file        finger_task.c
 * @author
 * @version   v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#include "self_def.h"
#include "stm32_bsp_conf.h"
#include "osal.h"
#include "clog.h"
#include "cshell.h"
#include "system_info.h"
#include "finger_task.h"
/**
 * @addtogroup    XXX 
 * @{  
 */

/**
 * @addtogroup    finger_task_Modules 
 * @{  
 */

/**
 * @defgroup      finger_task_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      finger_task_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      finger_task_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      finger_task_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      finger_task_Private_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      finger_task_Public_Variables 
 * @brief         
 * @{  
 */
uint8_t g_FingerTask_Id = 0;
/**
 * @}
 */

/**
 * @defgroup      finger_task_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      finger_task_Functions 
 * @brief         
 * @{  
 */
void FingerTask_Init(uint8_t taskId)
{
    g_FingerTask_Id = taskId;

}

osal_event_t FingerTask_Process(uint8_t taskid,osal_event_t events)
{
    if (events & FINGER_TASK_KEY_PROCESS_EVENT)
    {       
        return events ^ FINGER_TASK_KEY_PROCESS_EVENT;
    }
    if (events & FINGER_TASK_LOOP_EVENT)
    {   

        return events ^ FINGER_TASK_LOOP_EVENT;
    }
    if (events & FINGER_TASK_SHELL_EVENT)
    {   
        return events ^ FINGER_TASK_SHELL_EVENT;
    }

    if (events & FINGER_TASK_OPEN_CMD_EVENT)
    {   
        return events ^ FINGER_TASK_OPEN_CMD_EVENT;
    }

    if (events & FINGER_TASK_CLOSE_CMD_EVENT)
    {
        return events ^ FINGER_TASK_CLOSE_CMD_EVENT;
    }
    return 0;
}

void FingerTask_Send_Event(osal_event_t events)
{
    OS_Events_Set(g_FingerTask_Id,events);
}

void FingerTask_Clear_Event(osal_event_t events)
{

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

