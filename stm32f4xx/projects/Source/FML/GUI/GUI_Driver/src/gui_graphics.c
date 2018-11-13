/**
 **************************************************************************************************
 * @file        gui_graphics.c
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
#include "gui_graphics.h"

/**
 * @addtogroup    XXX 
 * @{  
 */

/**
 * @addtogroup    gui_graphics_Modules 
 * @{  
 */

/**
 * @defgroup      gui_graphics_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_graphics_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_graphics_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_graphics_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_graphics_Private_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_graphics_Public_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_graphics_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_graphics_Functions 
 * @brief         
 * @{  
 */
/*! 
*  \brief      画点
*  \param  x 位置X坐标
*  \param  y 位置Y坐标
*/

void GUI_DrawPoint(uint16_t x,uint16_t y)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x50);
    BSP_LCD_SendUint16(x);
    BSP_LCD_SendUint16(y);
    GUI_SendEndCMD();
}
/*! 
*  \brief      画线
*  \param  x0 起始位置X坐标
*  \param  y0 起始位置Y坐标
*  \param  x1 结束位置X坐标
*  \param  y1 结束位置Y坐标
*/
void GUI_DrawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x51);
    BSP_LCD_SendUint16(x0);
    BSP_LCD_SendUint16(y0);
    BSP_LCD_SendUint16(x1);
    BSP_LCD_SendUint16(y1);
    GUI_SendEndCMD();
}
/*! 
*  \brief   x坐标等距使用前景色连线
*  \param  x 横坐标
*  \param  x_space 距离
*  \param  dot_y  一组纵轴坐标
*  \param  dot_cnt  纵坐标个数
*/
void GUI_GUI_ConSpaceDots(uint16_t x,uint16_t x_space,uint16_t *dot_y,uint16_t dot_cnt)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x59);
    BSP_LCD_SendUint16(x);
    BSP_LCD_SendUint16(x_space);
    BSP_LCD_SendUint16N(dot_y,dot_cnt);
    GUI_SendEndCMD();
}
/*! 
*  \brief   按照坐标偏移量用前景色连线
*  \param  x 横坐标
*  \param  y 纵距离
*  \param  dot_offset  偏移量
*  \param  dot_cnt  偏移量个数
*/
void GUI_GUI_FcolorConOffsetDots(uint16_t x,uint16_t y,uint16_t *dot_offset,uint16_t dot_cnt)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x75);
    BSP_LCD_SendUint16(x);
    BSP_LCD_SendUint16(y);
    BSP_LCD_SendUint16N(dot_offset,dot_cnt);
    GUI_SendEndCMD();
}
/*! 
*  \brief   按照坐标偏移量用背景色连线
*  \param  x 横坐标
*  \param  y 纵距离
*  \param  dot_offset  偏移量
*  \param  dot_cnt  偏移量个数
*/
void GUI_GUI_BcolorConOffsetDots(uint16_t x,uint16_t y,uint8_t *dot_offset,uint16_t dot_cnt)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x76);
    BSP_LCD_SendUint16(x);
    BSP_LCD_SendUint16(y);
    BSP_LCD_SendUint8N(dot_offset,dot_cnt);
    GUI_SendEndCMD();
}
/*! 
*  \brief  自动调节背光亮度
*  \param  enable 使能
*  \param  bl_off_level 待机亮度
*  \param  bl_on_level  激活亮度
*  \param  bl_on_time  偏移量个数
*/
void GUI_SetPowerSaving(uint8_t enable, uint8_t bl_off_level, uint8_t bl_on_level, uint8_t  bl_on_time)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x77);
    BSP_LCD_WriteByte(enable);
    BSP_LCD_WriteByte(bl_off_level);
    BSP_LCD_WriteByte(bl_on_level);
    BSP_LCD_WriteByte(bl_on_time);
    GUI_SendEndCMD();
}
/*! 
*  \brief  将制定的多个坐标点用前景色连接起来
*  \param  dot  坐标点
*  \param  dot_cnt  偏移量个数
*/
void GUI_Draw_FcolorConDots(uint16_t *dot,uint16_t dot_cnt)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x68);
    BSP_LCD_SendUint16N(dot,dot_cnt*2);
    GUI_SendEndCMD();
}
/*! 
*  \brief  将制定的多个坐标点用背景色连接起来
*  \param  dot  坐标点
*  \param  dot_cnt  偏移量个数
*/
void GUI_Draw_BcolorConDots(uint16_t *dot,uint16_t dot_cnt)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x69);
    BSP_LCD_SendUint16N(dot,dot_cnt*2);
    GUI_SendEndCMD();
}
/*! 
*  \brief     画空心圆
*  \param  x0 圆心位置X坐标
*  \param  y0 圆心位置Y坐标
*  \param  r 半径
*/
void GUI_Draw_Circle(uint16_t x, uint16_t y, uint16_t r)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x52);
    BSP_LCD_SendUint16(x);
    BSP_LCD_SendUint16(y);
    BSP_LCD_SendUint16(r);
    GUI_SendEndCMD();
}
/*! 
*  \brief      画实心圆
*  \param  x0 圆心位置X坐标
*  \param  y0 圆心位置Y坐标
*  \param  r 半径
*/
void GUI_Draw_CircleFill(uint16_t x, uint16_t y, uint16_t r)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x53);
    BSP_LCD_SendUint16(x);
    BSP_LCD_SendUint16(y);
    BSP_LCD_SendUint16(r);
    GUI_SendEndCMD();
}
/*! 
*  \brief      画弧线
*  \param  x0 圆心位置X坐标
*  \param  y0 圆心位置Y坐标
*  \param  r 半径
*  \param  sa 起始角度
*  \param  ea 终止角度
*/
void GUI_Draw_Arc(uint16_t x,uint16_t y, uint16_t r,uint16_t sa, uint16_t ea)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x67);
    BSP_LCD_SendUint16(x);
    BSP_LCD_SendUint16(y);
    BSP_LCD_SendUint16(r);
    BSP_LCD_SendUint16(sa);
    BSP_LCD_SendUint16(ea);
    GUI_SendEndCMD();
}
/*! 
*  \brief      画空心矩形
*  \param  x0 起始位置X坐标
*  \param  y0 起始位置Y坐标
*  \param  x1 结束位置X坐标
*  \param  y1 结束位置Y坐标
*/
void GUI_Draw_Rectangle(uint16_t x0, uint16_t y0, uint16_t x1,uint16_t y1 )
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x54);
    BSP_LCD_SendUint16(x0);
    BSP_LCD_SendUint16(y0);
    BSP_LCD_SendUint16(x1);
    BSP_LCD_SendUint16(y1);
    GUI_SendEndCMD();
}
/*! 
*  \brief      画实心矩形
*  \param  x0 起始位置X坐标
*  \param  y0 起始位置Y坐标
*  \param  x1 结束位置X坐标
*  \param  y1 结束位置Y坐标
*/
void GUI_Draw_RectangleFill(uint16_t x0, uint16_t y0, uint16_t x1,uint16_t y1 )
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x55);
    BSP_LCD_SendUint16(x0);
    BSP_LCD_SendUint16(y0);
    BSP_LCD_SendUint16(x1);
    BSP_LCD_SendUint16(y1);
    GUI_SendEndCMD();
}
/*! 
*  \brief      画空心椭圆
*  \param  x0 起始位置X坐标
*  \param  y0 起始位置Y坐标
*  \param  x1 结束位置X坐标
*  \param  y1 结束位置Y坐标
*/
void GUI_Draw_Ellipse(uint16_t x0, uint16_t y0, uint16_t x1,uint16_t y1 )
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x56);
    BSP_LCD_SendUint16(x0);
    BSP_LCD_SendUint16(y0);
    BSP_LCD_SendUint16(x1);
    BSP_LCD_SendUint16(y1);
    GUI_SendEndCMD();
}
/*! 
*  \brief      画实心椭圆
*  \param  x0 起始位置X坐标
*  \param  y0 起始位置Y坐标
*  \param  x1 结束位置X坐标
*  \param  y1 结束位置Y坐标
*/
void GUI_Draw_EllipseFill(uint16_t x0, uint16_t y0, uint16_t x1,uint16_t y1 )
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x57);
    BSP_LCD_SendUint16(x0);
    BSP_LCD_SendUint16(y0);
    BSP_LCD_SendUint16(x1);
    BSP_LCD_SendUint16(y1);
    GUI_SendEndCMD();
}
/*! 
*  \brief      设置当前写入图层
*  \details  一般用于实现双缓存效果(绘图时避免闪烁)：
*  \details  uint8_t layer = 0;
*  \details  WriteLayer(layer);   设置写入层
*  \details  ClearLayer(layer);   使图层变透明
*  \details  添加一系列绘图指令
*  \details  DisText(100,100,0,4,"hello hmi!!!");
*  \details  DisplyLayer(layer);  切换显示层
*  \details  layer = (layer+1)%2; 双缓存切换
*  \see DisplyLayer
*  \see ClearLayer
*  \param  layer 图层编号
*/
void GUI_WriteLayer(uint8_t layer)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xA1);
    BSP_LCD_WriteByte(layer);
    GUI_SendEndCMD();
}
/*! 
*  \brief      设置当前显示图层
*  \param  layer 图层编号
*/
void GUI_DisplyLayer(uint8_t layer)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xA2);
    BSP_LCD_WriteByte(layer);
    GUI_SendEndCMD();
}
/*! 
*  \brief      拷贝图层
*  \param  src_layer 原始图层
*  \param  dest_layer 目标图层
*/
void GUI_CopyLayer(uint8_t src_layer,uint8_t dest_layer)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xA4);
    BSP_LCD_WriteByte(src_layer);
    BSP_LCD_WriteByte(dest_layer);
    GUI_SendEndCMD();
}
/*! 
*  \brief      清除图层，使图层变成透明
*  \param  layer 图层编号
*/
void GUI_ClearLayer(uint8_t layer)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x05);
    BSP_LCD_WriteByte(layer);
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

