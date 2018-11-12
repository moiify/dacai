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
void GUI_Queue_Reset(void);
void GUI_Queue_Push(uint8_t data);
uint16_t GUI_Queue_Find_Cmd(uint8_t *cmd,uint16_t buf_len);
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
