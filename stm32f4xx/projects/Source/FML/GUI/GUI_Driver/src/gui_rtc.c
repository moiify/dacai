/**
 **************************************************************************************************
 * @file        gui_rtc.c
 * @author
 * @version   v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#include "gui_conf.h"
#include "gui_rtc.h"

/**
 * @addtogroup    XXX 
 * @{  
 */

/**
 * @addtogroup    gui_rtc_Modules 
 * @{  
 */

/**
 * @defgroup      gui_rtc_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_rtc_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_rtc_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_rtc_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_rtc_Private_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_rtc_Public_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_rtc_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_rtc_Functions 
 * @brief         
 * @{  
 */
/*! 
*  \brief     读取屏幕RTC时间
*/
void GUI_ReadRTC(void)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x82);
    GUI_SendEndCMD();
}
/*! 
*  \brief     显示RTC时间
*/
void GUI_GUI_DispRTC(uint8_t enable,uint8_t mode,uint8_t font,uint16_t color,uint16_t x,uint16_t y)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x85);
    BSP_LCD_WriteByte(enable);
    BSP_LCD_WriteByte(mode);
    BSP_LCD_WriteByte(font);
    BSP_LCD_SendUint16(color);
    BSP_LCD_SendUint16(x);
    BSP_LCD_SendUint16(y);
    GUI_SendEndCMD();
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

