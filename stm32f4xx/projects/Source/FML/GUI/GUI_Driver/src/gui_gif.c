/**
 **************************************************************************************************
 * @file        gui_gif.c
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
#include "gui_gif.h"

/**
 * @addtogroup    XXX 
 * @{  
 */

/**
 * @addtogroup    gui_gif_Modules 
 * @{  
 */

/**
 * @defgroup      gui_gif_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_gif_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_gif_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_gif_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_gif_Private_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_gif_Public_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_gif_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_gif_Functions 
 * @brief         
 * @{  
 */
/*! 
*  \brief      显示GIF动画
*  \param  x 位置X坐标
*  \param  y 位置Y坐标
*  \param  flashimage_id 图片索引
*  \param  enable 是否显示
*  \param  playnum 播放次数
*/
void GUI_GIF_Show(uint16_t x,uint16_t y,uint16_t flashimage_id,uint8_t enable,uint8_t playnum)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x80);
    BSP_LCD_SendUint16(x);
    BSP_LCD_SendUint16(y);
    BSP_LCD_SendUint16(flashimage_id);
    BSP_LCD_WriteByte(enable);
    BSP_LCD_WriteByte(playnum);
    GUI_SendEndCMD();
}
/*! 
*  \brief      开始播放动画
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*/
void GUI_GIF_Start(uint16_t screen_id,uint16_t control_id)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x20);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    GUI_SendEndCMD();
}

/*! 
*  \brief      停止播放动画
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*/
void GUI_GIF_Stop(uint16_t screen_id,uint16_t control_id)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x21);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    GUI_SendEndCMD();
}
/*! 
*  \brief      暂停播放动画
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*/
void GUI_GIF_Pause(uint16_t screen_id,uint16_t control_id)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x22);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
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

