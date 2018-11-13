/**
 **************************************************************************************************
 * @file        gui_controlproperty.c
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
#include "gui_controlproperty.h"

/**
 * @addtogroup    XXX 
 * @{  
 */

/**
 * @addtogroup    gui_controlproperty_Modules 
 * @{  
 */

/**
 * @defgroup      gui_controlproperty_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_controlproperty_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_controlproperty_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_controlproperty_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_controlproperty_Private_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_controlproperty_Public_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_controlproperty_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_controlproperty_Functions 
 * @brief         
 * @{  
 */
/*! 
*  \brief     ���ÿؼ����뽹��
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  focus �Ƿ�������뽹��
*/
void GUI_SetFocus(uint16_t screen_id,uint16_t control_id,uint8_t focus)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x02);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_WriteByte(focus);
    GUI_SendEndCMD();
}
/*! 
*  \brief     ��ʾ\���ؿؼ�
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  visible �Ƿ���ʾ
*/
void GUI_SetVisiable(uint16_t screen_id,uint16_t control_id,uint8_t visible)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x03);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_WriteByte(visible);
    GUI_SendEndCMD();
}
/*! 
*  \brief     ���ô����ؼ�ʹ��
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  enable �ؼ��Ƿ�ʹ��
*/
void GUI_SetControlEnable(uint16_t screen_id,uint16_t control_id,uint8_t enable)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x04);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_WriteByte(enable);
    GUI_SendEndCMD();
}
/*! 
*  \brief     ���ÿؼ�����ɫ
*  \details  ֧�ֿؼ������������ı�
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  color ����ɫ
*/
void GUI_SetControlBackColor(uint16_t screen_id,uint16_t control_id,uint16_t color)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x18);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16(color);
    GUI_SendEndCMD();
}
/*! 
*  \brief     ���ÿؼ�ǰ��ɫ
* \details  ֧�ֿؼ���������
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  color ǰ��ɫ
*/
void GUI_SetControlForeColor(uint16_t screen_id,uint16_t control_id,uint16_t color)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x19);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16(color);
    GUI_SendEndCMD();
}
/*! 
*  \brief     ��ʾ\���ص����˵��ؼ�
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  show �Ƿ���ʾ��Ϊ0ʱfocus_control_id��Ч
*  \param  focus_control_id �������ı��ؼ�(�˵��ؼ�������������ı��ؼ�)
*/
void GUI_ShowPopupMenu(uint16_t screen_id,uint16_t control_id,uint8_t show,uint16_t focus_control_id)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x13);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_WriteByte(show);
    BSP_LCD_SendUint16(focus_control_id);
    GUI_SendEndCMD();
}
/*! 
*  \brief     ��ʾ\����ϵͳ����
*  \param  show 0���أ�1��ʾ
*  \param  x ������ʾλ��X����
*  \param  y ������ʾλ��Y����
*  \param  type 0С���̣�1ȫ����
*  \param  option 0�����ַ���1���룬2ʱ������
*  \param  max_len ����¼���ַ���������
*/
void GUI_ShowKeyboard(uint8_t show,uint16_t x,uint16_t y,uint8_t type,uint8_t option,uint8_t max_len)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x86);
    BSP_LCD_WriteByte(show);
    BSP_LCD_SendUint16(x);
    BSP_LCD_SendUint16(y);
    BSP_LCD_WriteByte(type);
    BSP_LCD_WriteByte(option);
    BSP_LCD_WriteByte(max_len);
    GUI_SendEndCMD();
}
/*! 
*  \brief     ����������
*  \param  ui_lang �û���������0~9
*  \param  sys_lang ϵͳ��������-0���ģ�1Ӣ��
*/
void GUI_SetLanguage(uint8_t ui_lang,uint8_t sys_lang)
{
    uint8_t lang = ui_lang;
    if(sys_lang)    lang |= 0x80;

    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xC1);
    BSP_LCD_WriteByte(lang);
    BSP_LCD_WriteByte(0xC1+lang);//У�飬��ֹ�����޸�����
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

