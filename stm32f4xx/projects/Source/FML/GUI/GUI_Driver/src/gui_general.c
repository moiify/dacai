/**
 **************************************************************************************************
 * @file        gui_general.c
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
#include "gui_general.h"
/**
 * @addtogroup    XXX 
 * @{  
 */

/**
 * @addtogroup    gui_general_Modules 
 * @{  
 */

/**
 * @defgroup      gui_general_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_general_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_general_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_general_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_general_Private_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_general_Public_Variables 
 * @brief         
 * @{  
 */
void (*GUI_TOUCH_CallBack)(uint8_t press,uint16_t x,uint16_t y);
void (*GUI_HANDSHAKE_CallBack)();
void (*GUI_SCREEN_CallBack)(uint16_t screen_id);
/**
 * @}
 */

/**
 * @defgroup      gui_general_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_general_Functions 
 * @brief         
 * @{  
 */
/* ������������*/
void GUI_HandShake()
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x04);
    GUI_SendEndCMD();
}

/* ���ñ���  levle 0-255*/
void GUI_SetBackLight(uint8_t light_level)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x60);
    BSP_LCD_WriteByte(light_level);
    GUI_SendEndCMD();      
}
/*����������   time ����ʱ��(���뵥λ)*/
void GUI_SetBuzzer(uint8_t time)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x61);
    BSP_LCD_WriteByte(time);
    GUI_SendEndCMD();    
}
/*! 
*  \brief  ����ǰ��ɫ
*  \param  color ǰ��ɫ
*/
void GUI_SetFtColor(uint16_t color)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x41);
    BSP_LCD_SendUint16(color);
    GUI_SendEndCMD();
}
/*! 
*  \brief  ���ñ���ɫ
*  \param  color ����ɫ
*/
void GUI_SetBkColor(uint16_t color)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x42);
    BSP_LCD_SendUint16(color);
    GUI_SendEndCMD();
}
/*! 
*  \brief ��ȡ��ɫ
*  \param  color ����ɫ
*/
void GUI_PickColor(uint8_t mode, uint16_t x,uint16_t y)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xA3);
    BSP_LCD_WriteByte(mode);
    BSP_LCD_SendUint16(x);
    BSP_LCD_SendUint16(y);
    GUI_SendEndCMD();
}
/*! 
*  \brief  �������
*/
void GUI_CleanScreen()
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x01);
    GUI_SendEndCMD();
}
/*! 
*  \brief      ��ȡ��ǰ����
*/
void GUI_GetScreen(uint16_t screen_id)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x01);
    GUI_SendEndCMD();
}
/*! 
*  \brief      ���õ�ǰ����
*  \param  screen_id ����ID
*/
void GUI_SetScreen(uint16_t screen_id)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x00);
    BSP_LCD_SendUint16(screen_id);
    GUI_SendEndCMD();
}
/*! 
*  \brief     ����\���û������
*  \details ����\����һ��ɶ�ʹ�ã����ڱ�����˸�����ˢ���ٶ�
*  \details �÷���
*   \details SetScreenUpdateEnable(0);//��ֹ����
*   \details һϵ�и��»����ָ��
*   \details SetScreenUpdateEnable(1);//��������
*  \param  enable 0���ã�1����
*/
void GUI_SetUpdateEnable(uint8_t enable)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB3);
    BSP_LCD_WriteByte(enable);
    GUI_SendEndCMD();
}
/*! 
*  \brief    ��ʾ���
*  \param  enable �Ƿ���ʾ
*  \param  x λ��X����
*  \param  y λ��Y����
*  \param  width ���
*  \param  height �߶�
*/
void GUI_DisCursor(uint8_t enable,uint16_t x, uint16_t y,uint8_t width,uint8_t height )
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x21);
    BSP_LCD_WriteByte(enable);
    BSP_LCD_SendUint16(x);
    BSP_LCD_SendUint16(y);
    BSP_LCD_WriteByte(width);
    BSP_LCD_WriteByte(height);
    GUI_SendEndCMD();
}
/*! 
*  \brief   ����������
*  \param enable ����ʹ��
*  \param beep_on ����������
*  \param work_mode ��������ģʽ��0���¾��ϴ���1�ɿ����ϴ���2�����ϴ�����ֵ��3���º��ɿ����ϴ�����
*  \param press_calibration �������������20��У׼��������0���ã�1����
*/
void GUI_SetTouchPaneOption(uint8_t enbale,uint8_t beep_on,uint8_t work_mode,uint8_t press_calibration)
{
    uint8_t options = 0;

    if(enbale)
        options |= 0x01;
    if(beep_on)
        options |= 0x02;
    if(work_mode)
        options |= (work_mode<<2);
    if(press_calibration)
        options |= (press_calibration<<5);

    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x70);
    BSP_LCD_WriteByte(options);
    GUI_SendEndCMD();
}
/*! 
*  \brief   У׼������
*/
void GUI_CalibrateTouchPane()
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x72);
    GUI_SendEndCMD();
}
/*! 
*  \brief  ����������
*/
void GUI_TestTouchPane()
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x73);
    GUI_SendEndCMD();
}

/*! 
*  \brief  �����豸���ã�����֮����Ҫ�����������޸Ĳ����ʡ���������������������ʽ
*/
void GUI_LockDeviceConfig(void)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x09);
    BSP_LCD_WriteByte(0xDE);
    BSP_LCD_WriteByte(0xED);
    BSP_LCD_WriteByte(0x13);
    BSP_LCD_WriteByte(0x31);
    GUI_SendEndCMD();
}

/*! 
*  \brief  �����豸����
*/
void GUI_UnlockDeviceConfig(void)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x08);
    BSP_LCD_WriteByte(0xA5);
    BSP_LCD_WriteByte(0x5A);
    BSP_LCD_WriteByte(0x5F);
    BSP_LCD_WriteByte(0xF5);
    GUI_SendEndCMD();
}
/*! 
*  \brief    �޸Ĵ������Ĳ�����
*  \details  ������ѡ�Χ[0~14]����Ӧʵ�ʲ�����
{1200,2400,4800,9600,19200,38400,57600,115200,1000000,2000000,218750,437500,875000,921800,2500000}
*  \param  option ������ѡ��
*/
void GUI_SetCommBps(uint8_t option)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xA0);
    BSP_LCD_WriteByte(option);
    GUI_SendEndCMD();
}

void GUI_SetTouchCallback(void (*recv)(uint8_t press,uint16_t x,uint16_t y))
{
    GUI_TOUCH_CallBack=recv;
}
void GUI_SetHandShakeCallback(void (*recv)())
{
    GUI_HANDSHAKE_CallBack=recv;
}
void GUI_SetScreenCallback(void (*recv)(uint16_t screen_id))
{
    GUI_SCREEN_CallBack=recv;
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

