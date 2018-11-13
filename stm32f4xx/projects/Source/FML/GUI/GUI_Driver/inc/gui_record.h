/**
 **************************************************************************************************
 * @file        gui_datarecord.h
 * @author
 * @version    v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#ifndef _GUI_DATARECORD_H_
#define _GUI_DATARECORD_H_

/**
 * @addtogroup    XXX 
 * @{ 
 */

/**
 * @addtogroup    gui_datarecord_Modules 
 * @{  
 */

/**
 * @defgroup      gui_datarecord_Exported_Macros 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_datarecord_Exported_Constants
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_datarecord_Exported_Types 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_datarecord_Exported_Variables 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_datarecord_Exported_Functions 
 * @{  
 */
void GUI_Record_SetEvent(uint16_t screen_id,uint16_t control_id,uint16_t value,uint8_t *time);
void GUI_Record_ResetEvent(uint16_t screen_id,uint16_t control_id,uint16_t value,uint8_t *time);
void GUI_Record_Add(uint16_t screen_id,uint16_t control_id,uint8_t *record);
void GUI_Record_Clear(uint16_t screen_id,uint16_t control_id);
void GUI_Record_SetOffset(uint16_t screen_id,uint16_t control_id,uint16_t offset);
void GUI_Record_GetCount(uint16_t screen_id,uint16_t control_id);
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
