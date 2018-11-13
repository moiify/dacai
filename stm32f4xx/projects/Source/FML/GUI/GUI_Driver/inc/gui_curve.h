/**
 **************************************************************************************************
 * @file        gui_curve.h
 * @author
 * @version    v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#ifndef _GUI_CURVE_H_
#define _GUI_CURVE_H_

/**
 * @addtogroup    XXX 
 * @{ 
 */

/**
 * @addtogroup    gui_curve_Modules 
 * @{  
 */

/**
 * @defgroup      gui_curve_Exported_Macros 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_curve_Exported_Constants
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_curve_Exported_Types 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_curve_Exported_Variables 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_curve_Exported_Functions 
 * @{  
 */
void GUI_GraphChannel_Add(uint16_t screen_id,uint16_t control_id,uint8_t channel,uint16_t color);
void GUI_GraphChannel_Del(uint16_t screen_id,uint16_t control_id,uint8_t channel);
void GUI_GraphChannel_DataAdd(uint16_t screen_id,uint16_t control_id,uint8_t channel,uint8_t *pData,uint16_t nDataLen);
void GUI_GraphChannel_DataClear(uint16_t screen_id,uint16_t control_id,uint8_t channel);
void GUI_GraphSetViewport(uint16_t screen_id,uint16_t control_id,short int x_offset,uint16_t x_mul,short int y_offset,uint16_t y_mul);
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
