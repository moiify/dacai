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
#include "gui_base.h"
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
void (*GUI_TEXT_CallBack)(uint16_t screen_id, uint16_t control_id, uint8_t *str);
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

void GUI_SetTextCallback(void (*recv)(uint16_t screen_id, uint16_t control_id, uint8_t *str))
{
    GUI_TEXT_CallBack=recv;
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

