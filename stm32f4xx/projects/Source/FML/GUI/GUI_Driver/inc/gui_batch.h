/**
 **************************************************************************************************
 * @file        gui_batch.h
 * @author
 * @version    v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#ifndef _GUI_BATCH_H_
#define _GUI_BATCH_H_

/**
 * @addtogroup    XXX 
 * @{ 
 */

/**
 * @addtogroup    gui_batch_Modules 
 * @{  
 */

/**
 * @defgroup      gui_batch_Exported_Macros 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_batch_Exported_Constants
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_batch_Exported_Types 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_batch_Exported_Variables 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_batch_Exported_Functions 
 * @{  
 */
void GUI_BatchBegin(uint16_t screen_id);
void GUI_BatchSetButtonValue(uint16_t control_id,uint8_t state);
void GUI_BatchSetProgressValue(uint16_t control_id,uint32_t value);
void GUI_BatchSetSliderValue(uint16_t control_id,uint32_t value);
void GUI_BatchSetMeterValue(uint16_t control_id,uint32_t value);
void GUI_BatchSetText(uint16_t control_id,uint8_t *strings);
void GUI_BatchSetFrame(uint16_t control_id,uint16_t frame_id);
void GUI_BatchSetVisible(uint16_t control_id,uint8_t visible);
void GUI_BatchSetEnable(uint16_t control_id,uint8_t enable);
void GUI_BatchEnd();
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
