/**
 **************************************************************************************************
 * @file        gui_historicalcurve.h
 * @author
 * @version    v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#ifndef _GUI_HISTORICALCURVE_H_
#define _GUI_HISTORICALCURVE_H_

/**
 * @addtogroup    XXX 
 * @{ 
 */

/**
 * @addtogroup    gui_historicalcurve_Modules 
 * @{  
 */

/**
 * @defgroup      gui_historicalcurve_Exported_Macros 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_historicalcurve_Exported_Constants
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_historicalcurve_Exported_Types 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_historicalcurve_Exported_Variables 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_historicalcurve_Exported_Functions 
 * @{  
 */
void GUI_HistoryGraph_SetValueInt8(uint16_t screen_id,uint16_t control_id,uint8_t *value,uint8_t channel);
void GUI_HistoryGraph_SetValueInt16(uint16_t screen_id,uint16_t control_id,uint16_t *value,uint8_t channel);
void GUI_HistoryGraph_SetValueInt32(uint16_t screen_id,uint16_t control_id,uint32_t *value,uint8_t channel);
void GUI_HistoryGraph_SetValueFloat(uint16_t screen_id,uint16_t control_id,float *value,uint8_t channel);
void GUI_HistoryGraph_EnableSampling(uint16_t screen_id,uint16_t control_id,uint8_t enable);
void GUI_HistoryGraph_ShowChannel(uint16_t screen_id,uint16_t control_id,uint8_t channel,uint8_t show);
void GUI_HistoryGraph_SetTimeLength(uint16_t screen_id,uint16_t control_id,uint16_t sample_count);
void GUI_HistoryGraph_SetTimeFullScreen(uint16_t screen_id,uint16_t control_id);
void GUI_HistoryGraph_SetTimeZoom(uint16_t screen_id,uint16_t control_id,uint16_t zoom,uint16_t max_zoom,uint16_t min_zoom);
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
