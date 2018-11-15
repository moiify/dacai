/**
 **************************************************************************************************
 * @file        gui_cmd_queue.h
 * @author
 * @version    v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#ifndef _GUI_CMD_QUEUE
#define _GUI_CMD_QUEUE
#include "self_def.h"

/**
 * @addtogroup    XXX 
 * @{ 
 */

/**
 * @addtogroup    gui_cmd_queue_Modules 
 * @{  
 */

/**
 * @defgroup      gui_cmd_queue_Exported_Macros 
 * @{  
 */
#define GUI_CMD_LEN_MAX  100
/**
 * @}
 */

/**
 * @defgroup      gui_cmd_queue_Exported_Constants
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_cmd_queue_Exported_Types 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_cmd_queue_Exported_Variables 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_cmd_queue_Exported_Functions 
 * @{  
 */

uint8_t  Gui_CMD_Queue_Pop(uint8_t *dst);
void     Gui_CMD_Queue_Push(void);
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
