/**
 **************************************************************************************************
 * @file        gui_general.h
 * @author
 * @version    v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#ifndef _GUI_GENERAL_H_
#define _GUI_GENERAL_H_

/**
 * @addtogroup    XXX 
 * @{ 
 */

/**
 * @addtogroup    gui_general_Modules 
 * @{  
 */

/**
 * @defgroup      gui_general_Exported_Macros 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_general_Exported_Constants
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_general_Exported_Types 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_general_Exported_Variables 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_general_Exported_Functions 
 * @{  
 */
void GUI_HandShake();
void GUI_SetBackLight(uint8_t light_level);
void GUI_SetBuzzer(uint8_t time);
void GUI_SetFtColor(uint16_t color);
void GUI_SetBkColor(uint16_t color);
void GUI_PickColor(uint8_t mode, uint16_t x,uint16_t y);
void GUI_CleanScreen();
void GUI_GetScreen(uint16_t screen_id);
void GUI_SetScreen(uint16_t screen_id);
void GUI_SetUpdateEnable(uint8_t enable);
void GUI_DisCursor(uint8_t enable,uint16_t x, uint16_t y,uint8_t width,uint8_t height );
void GUI_SetTouchPaneOption(uint8_t enbale,uint8_t beep_on,uint8_t work_mode,uint8_t press_calibration);
void GUI_CalibrateTouchPane();
void GUI_TestTouchPane();
void GUI_LockDeviceConfig(void);
void GUI_UnlockDeviceConfig(void);
void GUI_SetCommBps(uint8_t option);
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
