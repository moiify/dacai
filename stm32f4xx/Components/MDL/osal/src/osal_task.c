/**
 **************************************************************************************************
 * @file        osal_task.c
 * @author
 * @version     V1.0.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#include "osal.h"
#include "osal_cpu.h"
#include "osal_cfg.h"
#include "osal_core.h"
#include "user_task.h"
#include "gui_task.h"
#include "finger_task.h"
#include "osal_task.h"
/**
 * @addtogroup    XXX 
 * @{  
 */

/**
 * @addtogroup    osal_task_Modules 
 * @{  
 */

/**
 * @defgroup      osal_task_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup       osal_task_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      osal_task_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup       osal_task_Private_Types
 * @brief         
 * @{  
 */
const pTaskEventHandlerFn g_TasksFnArr[OSAL_TASK_COUNT] =
{
    UserTask_Process,
    FingerTask_Process,
    GuiTask_Process,
};

uint32_t g_TasksEvents[OSAL_TASK_COUNT];
/**
 * @}
 */

/**
 * @defgroup      osal_task_Private_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      osal_task_Public_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      osal_task_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      osal_task_Functions 
 * @brief         
 * @{  
 */
void OS_Task_Init(void)
{
    uint8_t task_id = 0;
    UserTask_Init(task_id++);
    FingerTask_Init(task_id++);
    GuiTask_Init(task_id++);
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

