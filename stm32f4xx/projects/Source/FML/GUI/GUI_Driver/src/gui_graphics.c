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
*  \brief      ����
*  \param  x λ��X����
*  \param  y λ��Y����
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
*  \brief      ����
*  \param  x0 ��ʼλ��X����
*  \param  y0 ��ʼλ��Y����
*  \param  x1 ����λ��X����
*  \param  y1 ����λ��Y����
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
*  \brief   x����Ⱦ�ʹ��ǰ��ɫ����
*  \param  x ������
*  \param  x_space ����
*  \param  dot_y  һ����������
*  \param  dot_cnt  ���������
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
*  \brief   ��������ƫ������ǰ��ɫ����
*  \param  x ������
*  \param  y �ݾ���
*  \param  dot_offset  ƫ����
*  \param  dot_cnt  ƫ��������
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
*  \brief   ��������ƫ�����ñ���ɫ����
*  \param  x ������
*  \param  y �ݾ���
*  \param  dot_offset  ƫ����
*  \param  dot_cnt  ƫ��������
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
*  \brief  �Զ����ڱ�������
*  \param  enable ʹ��
*  \param  bl_off_level ��������
*  \param  bl_on_level  ��������
*  \param  bl_on_time  ƫ��������
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
*  \brief  ���ƶ��Ķ���������ǰ��ɫ��������
*  \param  dot  �����
*  \param  dot_cnt  ƫ��������
*/
void GUI_Draw_FcolorConDots(uint16_t *dot,uint16_t dot_cnt)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x68);
    BSP_LCD_SendUint16N(dot,dot_cnt*2);
    GUI_SendEndCMD();
}
/*! 
*  \brief  ���ƶ��Ķ��������ñ���ɫ��������
*  \param  dot  �����
*  \param  dot_cnt  ƫ��������
*/
void GUI_Draw_BcolorConDots(uint16_t *dot,uint16_t dot_cnt)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x69);
    BSP_LCD_SendUint16N(dot,dot_cnt*2);
    GUI_SendEndCMD();
}
/*! 
*  \brief     ������Բ
*  \param  x0 Բ��λ��X����
*  \param  y0 Բ��λ��Y����
*  \param  r �뾶
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
*  \brief      ��ʵ��Բ
*  \param  x0 Բ��λ��X����
*  \param  y0 Բ��λ��Y����
*  \param  r �뾶
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
*  \brief      ������
*  \param  x0 Բ��λ��X����
*  \param  y0 Բ��λ��Y����
*  \param  r �뾶
*  \param  sa ��ʼ�Ƕ�
*  \param  ea ��ֹ�Ƕ�
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
*  \brief      �����ľ���
*  \param  x0 ��ʼλ��X����
*  \param  y0 ��ʼλ��Y����
*  \param  x1 ����λ��X����
*  \param  y1 ����λ��Y����
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
*  \brief      ��ʵ�ľ���
*  \param  x0 ��ʼλ��X����
*  \param  y0 ��ʼλ��Y����
*  \param  x1 ����λ��X����
*  \param  y1 ����λ��Y����
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
*  \brief      ��������Բ
*  \param  x0 ��ʼλ��X����
*  \param  y0 ��ʼλ��Y����
*  \param  x1 ����λ��X����
*  \param  y1 ����λ��Y����
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
*  \brief      ��ʵ����Բ
*  \param  x0 ��ʼλ��X����
*  \param  y0 ��ʼλ��Y����
*  \param  x1 ����λ��X����
*  \param  y1 ����λ��Y����
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
*  \brief      ���õ�ǰд��ͼ��
*  \details  һ������ʵ��˫����Ч��(��ͼʱ������˸)��
*  \details  uint8_t layer = 0;
*  \details  WriteLayer(layer);   ����д���
*  \details  ClearLayer(layer);   ʹͼ���͸��
*  \details  ���һϵ�л�ͼָ��
*  \details  DisText(100,100,0,4,"hello hmi!!!");
*  \details  DisplyLayer(layer);  �л���ʾ��
*  \details  layer = (layer+1)%2; ˫�����л�
*  \see DisplyLayer
*  \see ClearLayer
*  \param  layer ͼ����
*/
void GUI_WriteLayer(uint8_t layer)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xA1);
    BSP_LCD_WriteByte(layer);
    GUI_SendEndCMD();
}
/*! 
*  \brief      ���õ�ǰ��ʾͼ��
*  \param  layer ͼ����
*/
void GUI_DisplyLayer(uint8_t layer)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xA2);
    BSP_LCD_WriteByte(layer);
    GUI_SendEndCMD();
}
/*! 
*  \brief      ����ͼ��
*  \param  src_layer ԭʼͼ��
*  \param  dest_layer Ŀ��ͼ��
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
*  \brief      ���ͼ�㣬ʹͼ����͸��
*  \param  layer ͼ����
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

