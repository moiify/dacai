/**
 **************************************************************************************************
 * @file        gui_image.c
 * @author
 * @version   v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#include "gui_base.h"
#include "gui_image.h"

/**
 * @addtogroup    XXX 
 * @{  
 */

/**
 * @addtogroup    gui_image_Modules 
 * @{  
 */

/**
 * @defgroup      gui_image_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_image_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_image_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_image_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_image_Private_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_image_Public_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_image_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_image_Functions 
 * @brief         
 * @{  
 */
/*! 
*  \brief      显示全屏图片
*  \param  image_id 图片索引
*  \param  masken 是否启用透明掩码
*/
void GUI_IMAGE_ShowFull(uint16_t image_id,uint8_t masken)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x31);
    BSP_LCD_SendUint16(image_id);
    BSP_LCD_WriteByte(masken);
    GUI_SendEndCMD();
}
/*! 
*  \brief      指定位置显示图片
*  \param  x 位置X坐标
*  \param  y 位置Y坐标
*  \param  image_id 图片索引
*  \param  masken 是否启用透明掩码
*/
void GUI_IMAGE_Show(uint16_t x,uint16_t y,uint16_t image_id,uint8_t masken)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x32);
    BSP_LCD_SendUint16(x);
    BSP_LCD_SendUint16(y);
    BSP_LCD_SendUint16(image_id);
    BSP_LCD_WriteByte(masken);
    GUI_SendEndCMD();
}
/*! 
*  \brief      显示裁剪图片
*  \param  x 位置X坐标
*  \param  y 位置Y坐标
*  \param  image_id 图片索引
*  \param  image_x 图片裁剪位置X坐标
*  \param  image_y 图片裁剪位置Y坐标
*  \param  image_l 图片裁剪长度
*  \param  image_w 图片裁剪高度
*  \param  masken 是否启用透明掩码
*/
void GUI_IMAGE_CutShow(uint16_t x,uint16_t y,uint16_t image_id,uint16_t image_x,uint16_t image_y,uint16_t image_l, uint16_t image_w,uint8_t masken)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x33);
    BSP_LCD_SendUint16(x);
    BSP_LCD_SendUint16(y);
    BSP_LCD_SendUint16(image_id);
    BSP_LCD_SendUint16(image_x);
    BSP_LCD_SendUint16(image_y);
    BSP_LCD_SendUint16(image_l);
    BSP_LCD_SendUint16(image_w);
    BSP_LCD_WriteByte(masken);
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

