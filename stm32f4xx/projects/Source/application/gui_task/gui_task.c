/**
 **************************************************************************************************
 * @file        gui_task.c
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
#include "gui_fun.h"
#include "gui_process.h"
#include "gui_task.h"
/**
 * @addtogroup    XXX 
 * @{  
 */

/**
 * @addtogroup    gui_task_Modules 
 * @{  
 */

/**
 * @defgroup      gui_task_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_task_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_task_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_task_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_task_Private_Variables 
 * @brief         
 * @{  
 */
uint8_t g_GuiTask_Id = 0;
/**
 * @}
 */

/**
 * @defgroup      gui_task_Public_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_task_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_task_Functions 
 * @brief         
 * @{  
 */
void GuiTask_Init(uint8_t taskId)
{
    g_GuiTask_Id = taskId;
    GUI_CON_SetCallBack();
    OS_Timer_Start(g_GuiTask_Id, GUI_TASK_KEY_PROCESS_EVENT,300);
    OS_Timer_Start(g_GuiTask_Id, GUI_TASK_LOOP_EVENT,500);
}

osal_event_t GuiTask_Process(uint8_t taskid,osal_event_t events)
{
    if (events & GUI_TASK_KEY_PROCESS_EVENT)
    {   
        GUI_Update();   
       OS_Timer_Start(g_GuiTask_Id, GUI_TASK_KEY_PROCESS_EVENT,100);
        return events ^ GUI_TASK_KEY_PROCESS_EVENT;
    }
    if (events & GUI_TASK_LOOP_EVENT)
    {  
        Gui_CheckCMD_Loop_Process();
        OS_Timer_Start(g_GuiTask_Id, GUI_TASK_LOOP_EVENT,100);
        return events ^ GUI_TASK_LOOP_EVENT;
    }
    if (events & GUI_TASK_SHELL_EVENT)
    {   
        return events ^ GUI_TASK_SHELL_EVENT;
    }

    if (events & GUI_TASK_OPEN_CMD_EVENT)
    {   
        return events ^ GUI_TASK_OPEN_CMD_EVENT;
    }

    if (events & GUI_TASK_CLOSE_CMD_EVENT)
    {
        return events ^ GUI_TASK_CLOSE_CMD_EVENT;
    }
    return 0;
}

void GuiTask_Send_Event(osal_event_t events)
{
    OS_Events_Set(g_GuiTask_Id,events);
}

void GuiTask_Clear_Event(osal_event_t events)
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

