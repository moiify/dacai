/**
 **************************************************************************************************
 * @file        gui_progress.h
 * @author
 * @version    v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#ifndef _GUI_PROGRESS_H_
#define _GUI_PROGRESS_H_

/**
 * @addtogroup    XXX 
 * @{ 
 */

/**
 * @addtogroup    gui_progress_Modules 
 * @{  
 */

/**
 * @defgroup      gui_progress_Exported_Macros 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_progress_Exported_Constants
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_progress_Exported_Types 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_progress_Exported_Variables 
 * @{  
 */
extern void (*GUI_PROGRESS_CallBack)(uint16_t screen_id,uint16_t control_id,uint32_t value);
/**
 * @}
 */

/**
 * @defgroup      gui_progress_Exported_Functions 
 * @{  
 */
void GUI_PROGRESS_SetValue(uint16_t screen_id,uint16_t control_id,uint32_t value);
void GUI_SetProgressCallback(void (*recv)(uint16_t screen_id,uint16_t control_id,uint32_t value));
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
