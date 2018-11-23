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
#include "fingerprint_process.h"
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
    Finger_SetState(FPState_HandShake_Req);
    OS_Timer_Start(g_FingerTask_Id, FINGER_TASK_INIT_EVENT, 500);
   // OS_Timer_Start(g_FingerTask_Id, FINGER_TASK_ADD_EVENT, 100); //≤‚ ‘”√
}

osal_event_t FingerTask_Process(uint8_t taskid,osal_event_t events)
{
    if (events & FINGER_TASK_INIT_EVENT)
    {   
        Finger_Init_Process();
        return events ^ FINGER_TASK_INIT_EVENT;
    }
    if (events & FINGER_TASK_ACK_EVENT)
    {   
		Finger_ACK_Process();
        return events ^ FINGER_TASK_ACK_EVENT;
    }
    if (events & FINGER_TASK_ADD_EVENT)
    {  	
		Finger_AddPrint_Process();    
        return events ^ FINGER_TASK_ADD_EVENT;
    }    
    if (events & FINGER_TASK_SWIP_EVENT)
    {   
        Finger_SwipPrint_Process();
        return events ^ FINGER_TASK_SWIP_EVENT;
    }

    if (events & FINGER_TASK_DELETE_EVENT)
    {   
        Finger_DeletePrint_Process();
        return events ^ FINGER_TASK_DELETE_EVENT;
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

