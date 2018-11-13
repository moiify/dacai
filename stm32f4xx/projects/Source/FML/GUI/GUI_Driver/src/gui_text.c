/**
 **************************************************************************************************
 * @file        gui_text.c
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
#include "gui_text.h"

/**
 * @addtogroup    XXX 
 * @{  
 */

/**
 * @addtogroup    gui_text_Modules 
 * @{  
 */

/**
 * @defgroup      gui_text_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_text_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_text_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_text_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_text_Private_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_text_Public_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_text_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_text_Functions 
 * @brief         
 * @{  
 */
/*! 
*  \brief     �����ı�ֵ
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  str �ı�ֵ
*/
void GUI_TEXT_SetText(uint16_t screen_id,uint16_t control_id,uint8_t *str)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x10);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendStrings(str);
    GUI_SendEndCMD();
}
/*! 
*  \brief     ��ȡ�ı�ֵ
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*/
void GUI_TEXT_GetValue(uint16_t screen_id,uint16_t control_id)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x11);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    GUI_SendEndCMD();
}
/*! 
*  \brief     �����ı�Ϊ����ֵ��Ҫ��FIRMWARE_VER>=908
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  value �ı���ֵ
*  \param  sign 0-�޷��ţ�1-�з���
*  \param  fill_zero ����λ��������ʱ��ಹ��
*/
void GUI_TEXT_SetInt32(uint16_t screen_id,uint16_t control_id,uint32_t value,uint8_t sign,uint8_t fill_zero)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x07);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_WriteByte(sign?0X01:0X00);
    BSP_LCD_WriteByte((fill_zero&0x0f)|0x80);
    BSP_LCD_SendUint32(value);
    GUI_SendEndCMD();
}
/*! 
*  \brief     �����ı������ȸ���ֵ��Ҫ��FIRMWARE_VER>=908
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  value �ı���ֵ
*  \param  precision С��λ��
*  \param  show_zeros Ϊ1ʱ����ʾĩβ0
*/
void GUI_TEXT_SetFloat(uint16_t screen_id,uint16_t control_id,float value,uint8_t precision,uint8_t show_zeros)
{
    uint8_t i = 0;

    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x07);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_WriteByte(0x02);
    BSP_LCD_WriteByte((precision&0x0f)|(show_zeros?0x80:0x00));

    for (i=0;i<4;++i)
    {
        BSP_LCD_WriteByte(((uint8_t *)&value)[i]);
    }

    GUI_SendEndCMD();
}
/*! 
*  \brief  �������ּ��
*  \param  x_w ������
*  \param  y_w ������
*/
void GUI_TEXT_SetSpace(uint8_t x_w, uint8_t y_w)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x43);
    BSP_LCD_WriteByte(x_w);
    BSP_LCD_WriteByte(y_w);
    GUI_SendEndCMD();
}
/*! 
*  \brief  ����������ʾ����
*  \param  enable �Ƿ���������
*  \param  width ���
*  \param  height �߶�
*/
void GUI_TEXT_SetFontRegion(uint8_t enable,uint16_t width,uint16_t height)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x45);
    BSP_LCD_WriteByte(enable);
    BSP_LCD_SendUint16(width);
    BSP_LCD_SendUint16(height);
    GUI_SendEndCMD();
}
/*! 
*  \brief  ���ù���ɫ
*  \param  fillcolor_dwon ��ɫ�½�
*  \param  fillcolor_up ��ɫ�Ͻ�
*/
void GUI_TEXT_SetFilterColor(uint16_t fillcolor_dwon, uint16_t fillcolor_up)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x44);
    BSP_LCD_SendUint16(fillcolor_dwon);
    BSP_LCD_SendUint16(fillcolor_up);
    GUI_SendEndCMD();
}

/*! 
*  \brief  ���ù���ɫ
*  \param  x λ��X����
*  \param  y λ��Y����
*  \param  back ��ɫ�Ͻ�
*  \param  font ����
*  \param  strings �ַ�������
*/
void GUI_TEXT_DisFilter(uint16_t x, uint16_t y,uint8_t back,uint8_t font,uint8_t *strings )
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x20);
    BSP_LCD_SendUint16(x);
    BSP_LCD_SendUint16(y);
    BSP_LCD_WriteByte(back);
    BSP_LCD_WriteByte(font);
    BSP_LCD_SendStrings(strings);
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

