/**
 **************************************************************************************************
 * @file        gui_rtc.h
 * @author
 * @version    v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#ifndef _GUI_RTC_H_
#define _GUI_RTC_H_

/**
 * @addtogroup    XXX 
 * @{ 
 */

/**
 * @addtogroup    gui_rtc_Modules 
 * @{  
 */

/**
 * @defgroup      gui_rtc_Exported_Macros 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_rtc_Exported_Constants
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_rtc_Exported_Types 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_rtc_Exported_Variables 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_rtc_Exported_Functions 
 * @{  
 */
void GUI_ReadRTC(void);
void GUI_GUI_DispRTC(uint8_t enable,uint8_t mode,uint8_t font,uint16_t color,uint16_t x,uint16_t y);
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
