/**
 **************************************************************************************************
 * @file        gui_dev_api.c
 * @author
 * @version   v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#include "self_def.h"
#include "gui_dev_api.h"
#include "bsp_lcd.h"

/**
 * @addtogroup    XXX 
 * @{  
 */

/**
 * @addtogroup    gui_dev_api_Modules 
 * @{  
 */

/**
 * @defgroup      gui_dev_api_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_dev_api_Macros_Defines 
 * @brief         
 * @{  
 */
#if(CRC16_ENABLE)

#else

static void gui_SendHeadCMD()
{   
    BSP_LCD_WriteByte(0XEE);
}
static void gui_SendEndCMD()
{   
    uint8_t buf[]={0xff,0xfc,0xff,0xff};
    BSP_LCD_WriteBytes(buf,4);
}

#endif
/**
 * @}
 */

/**
 * @defgroup      gui_dev_api_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_dev_api_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_dev_api_Private_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_dev_api_Public_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_dev_api_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_dev_api_Functions 
 * @brief         
 * @{  
 */
/* ������������*/
void GUI_HandShake()
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x04);
    gui_SendEndCMD();
}

/* ���ñ���  levle 0-255*/
void GUI_SetBackLight(uint8_t light_level)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x60);
    BSP_LCD_WriteByte(light_level);
    gui_SendEndCMD();      
}
/*����������   time ����ʱ��(���뵥λ)*/
void GUI_SetBuzzer(uint8_t time)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x61);
    BSP_LCD_WriteByte(time);
    gui_SendEndCMD();    
}
/*! 
*  \brief  ����ǰ��ɫ
*  \param  color ǰ��ɫ
*/
void GUI_SetFtColor(uint16_t color)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x41);
    BSP_LCD_SendUint16(color);
    gui_SendEndCMD();
}
/*! 
*  \brief  ���ñ���ɫ
*  \param  color ����ɫ
*/
void GUI_SetBkColor(uint16_t color)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x42);
    BSP_LCD_SendUint16(color);
    gui_SendEndCMD();
}
/*! 
*  \brief  �������
*/
void GUI_CleanScreen()
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x01);
    gui_SendEndCMD();
}

/*! 
*  \brief      ��ʾȫ��ͼƬ
*  \param  image_id ͼƬ����
*  \param  masken �Ƿ�����͸������
*/
void GUI_IMAGE_ShowFull(uint16_t image_id,uint8_t masken)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x31);
    BSP_LCD_SendUint16(image_id);
    BSP_LCD_WriteByte(masken);
    gui_SendEndCMD();
}
/*! 
*  \brief      ָ��λ����ʾͼƬ
*  \param  x λ��X����
*  \param  y λ��Y����
*  \param  image_id ͼƬ����
*  \param  masken �Ƿ�����͸������
*/
void GUI_IMAGE_Show(uint16_t x,uint16_t y,uint16_t image_id,uint8_t masken)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x32);
    BSP_LCD_SendUint16(x);
    BSP_LCD_SendUint16(y);
    BSP_LCD_SendUint16(image_id);
    BSP_LCD_WriteByte(masken);
    gui_SendEndCMD();
}
/*! 
*  \brief      ��ʾ�ü�ͼƬ
*  \param  x λ��X����
*  \param  y λ��Y����
*  \param  image_id ͼƬ����
*  \param  image_x ͼƬ�ü�λ��X����
*  \param  image_y ͼƬ�ü�λ��Y����
*  \param  image_l ͼƬ�ü�����
*  \param  image_w ͼƬ�ü��߶�
*  \param  masken �Ƿ�����͸������
*/
void GUI_IMAGE_CutShow(uint16_t x,uint16_t y,uint16_t image_id,uint16_t image_x,uint16_t image_y,uint16_t image_l, uint16_t image_w,uint8_t masken)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x33);
    BSP_LCD_SendUint16(x);
    BSP_LCD_SendUint16(y);
    BSP_LCD_SendUint16(image_id);
    BSP_LCD_SendUint16(image_x);
    BSP_LCD_SendUint16(image_y);
    BSP_LCD_SendUint16(image_l);
    BSP_LCD_SendUint16(image_w);
    BSP_LCD_WriteByte(masken);
    gui_SendEndCMD();
}
/*! 
*  \brief      ��ʾGIF����
*  \param  x λ��X����
*  \param  y λ��Y����
*  \param  flashimage_id ͼƬ����
*  \param  enable �Ƿ���ʾ
*  \param  playnum ���Ŵ���
*/
void GUI_GIF_Show(uint16_t x,uint16_t y,uint16_t flashimage_id,uint8_t enable,uint8_t playnum)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x80);
    BSP_LCD_SendUint16(x);
    BSP_LCD_SendUint16(y);
    BSP_LCD_SendUint16(flashimage_id);
    BSP_LCD_WriteByte(enable);
    BSP_LCD_WriteByte(playnum);
    gui_SendEndCMD();
}
/*! 
*  \brief      ����
*  \param  x λ��X����
*  \param  y λ��Y����
*/
void GUI_DrawPoint(uint16_t x,uint16_t y)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x50);
    BSP_LCD_SendUint16(x);
    BSP_LCD_SendUint16(y);
    gui_SendEndCMD();
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
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x51);
    BSP_LCD_SendUint16(x0);
    BSP_LCD_SendUint16(y0);
    BSP_LCD_SendUint16(x1);
    BSP_LCD_SendUint16(y1);
    gui_SendEndCMD();
}


/*! 
*  \brief      ��ȡ��ǰ����
*/
void GUI_GetScreen(uint16_t screen_id)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x01);
    gui_SendEndCMD();
}
/*! 
*  \brief      ���õ�ǰ����
*  \param  screen_id ����ID
*/
void GUI_SetScreen(uint16_t screen_id)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x00);
    BSP_LCD_SendUint16(screen_id);
    gui_SendEndCMD();
}
/*! 
*  \brief     ����\���û������
*  \details ����\����һ��ɶ�ʹ�ã����ڱ�����˸�����ˢ���ٶ�
*  \details �÷���
*	\details SetScreenUpdateEnable(0);//��ֹ����
*	\details һϵ�и��»����ָ��
*	\details SetScreenUpdateEnable(1);//��������
*  \param  enable 0���ã�1����
*/
void GUI_SetUpdateEnable(uint8_t enable)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB3);
    BSP_LCD_WriteByte(enable);
    gui_SendEndCMD();
}
/*! 
*  \brief     ���ÿؼ����뽹��
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  focus �Ƿ�������뽹��
*/
void GUI_SetFocus(uint16_t screen_id,uint16_t control_id,uint8_t focus)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x02);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_WriteByte(focus);
    gui_SendEndCMD();
}
/*! 
*  \brief     ��ʾ\���ؿؼ�
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  visible �Ƿ���ʾ
*/
void GUI_SetVisiable(uint16_t screen_id,uint16_t control_id,uint8_t visible)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x03);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_WriteByte(visible);
    gui_SendEndCMD();
}
/*! 
*  \brief     ���ô����ؼ�ʹ��
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  enable �ؼ��Ƿ�ʹ��
*/
void GUI_SetControlEnable(uint16_t screen_id,uint16_t control_id,uint8_t enable)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x04);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_WriteByte(enable);
    gui_SendEndCMD();
}
/*! 
*  \brief     ���ð�ť״̬
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  value ��ť״̬
*/
void GUI_BUTTON_SetState(uint16_t screen_id,uint16_t control_id,uint8_t state)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x10);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_WriteByte(state);
    gui_SendEndCMD();
}
/*! 
*  \brief     �����ı�ֵ
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  str �ı�ֵ
*/
void GUI_TEXT_SetText(uint16_t screen_id,uint16_t control_id,uint8_t *str)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x10);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendStrings(str);
    gui_SendEndCMD();
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
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x07);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_WriteByte(sign?0X01:0X00);
    BSP_LCD_WriteByte((fill_zero&0x0f)|0x80);
    BSP_LCD_SendUint32(value);
    gui_SendEndCMD();
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

    gui_SendHeadCMD();
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

    gui_SendEndCMD();
}
/*! 
*  \brief      ��ʼ���Ŷ���
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*/
void GUI_GIF_Start(uint16_t screen_id,uint16_t control_id)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x20);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    gui_SendEndCMD();
}

/*! 
*  \brief      ֹͣ���Ŷ���
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*/
void GUI_GIF_Stop(uint16_t screen_id,uint16_t control_id)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x21);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    gui_SendEndCMD();
}
/*! 
*  \brief      ��ͣ���Ŷ���
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*/
void GUI_GIF_Pause(uint16_t screen_id,uint16_t control_id)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x22);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    gui_SendEndCMD();
}
/*! 
*  \brief     �����ƶ�֡
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  frame_id ֡ID
*/
void GUI_Animation_PlayFrame(uint16_t screen_id,uint16_t control_id,uint8_t frame_id)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x23);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_WriteByte(frame_id);
    gui_SendEndCMD();
}
/*! 
*  \brief     ������һ֡
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*/
void GUI_Animation_PlayPrev(uint16_t screen_id,uint16_t control_id)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x24);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    gui_SendEndCMD();
}
/*! 
*  \brief     ������һ֡
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*/
void GUI_Animation_PlayNext(uint16_t screen_id,uint16_t control_id)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x25);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    gui_SendEndCMD();
}
/*! 
*  \brief     ���߿ؼ�-���ͨ��
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  channel ͨ����
*  \param  color ��ɫ
*/
void GUI_GraphChannel_Add(uint16_t screen_id,uint16_t control_id,uint8_t channel,uint16_t color)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x30);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_WriteByte(channel);
    BSP_LCD_SendUint16(color);
    gui_SendEndCMD();
}
/*! 
*  \brief     ���߿ؼ�-ɾ��ͨ��
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  channel ͨ����
*/
void GUI_GraphChannel_Del(uint16_t screen_id,uint16_t control_id,uint8_t channel)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x31);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_WriteByte(channel);
    gui_SendEndCMD();
}
/*! 
*  \brief     ���߿ؼ�-�������
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  channel ͨ����
*  \param  pData ��������
*  \param  nDataLen ���ݸ���
*/
void GUI_GraphChannel_DataAdd(uint16_t screen_id,uint16_t control_id,uint8_t channel,uint8_t *pData,uint16_t nDataLen)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x32);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_WriteByte(channel);
    BSP_LCD_SendUint16(nDataLen);
    BSP_LCD_SendUint8N(pData,nDataLen);
    gui_SendEndCMD();
}
/*! 
*  \brief     ���߿ؼ�-�������
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  channel ͨ���� 
*/
void GUI_GraphChannel_DataClear(uint16_t screen_id,uint16_t control_id,uint8_t channel)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x33);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_WriteByte(channel);
    gui_SendEndCMD();
}
/*! 
*  \brief     ���߿ؼ�-������ͼ����
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  x_offset ˮƽƫ��
*  \param  x_mul ˮƽ����ϵ��
*  \param  y_offset ��ֱƫ��
*  \param  y_mul ��ֱ����ϵ��
*/
void GUI_GraphSetViewport(uint16_t screen_id,uint16_t control_id,short int x_offset,uint16_t x_mul,short int y_offset,uint16_t y_mul)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x34);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16(x_offset);
    BSP_LCD_SendUint16(x_mul);
    BSP_LCD_SendUint16(y_offset);
    BSP_LCD_SendUint16(y_mul);
    gui_SendEndCMD();
}
/*! 
*  \brief     ��ʼ��������
*  \param  screen_id ����ID
*/
void GUI_BatchBegin(uint16_t screen_id)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x12);
    BSP_LCD_SendUint16(screen_id);
}
/*! 
*  \brief     �������°�ť�ؼ�
*  \param  control_id �ؼ�ID
*  \param  value ��ֵ
*/
void GUI_BatchSetButtonValue(uint16_t control_id,uint8_t state)
{
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16(1);
    BSP_LCD_WriteByte(state);
}
/*! 
*  \brief     �������½������ؼ�
*  \param  control_id �ؼ�ID
*  \param  value ��ֵ
*/
void GUI_BatchSetProgressValue(uint16_t control_id,uint32_t value)
{
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16(4);
    BSP_LCD_SendUint32(value);
}

/*! 
*  \brief     �������»������ؼ�
*  \param  control_id �ؼ�ID
*  \param  value ��ֵ
*/
void GUI_BatchSetSliderValue(uint16_t control_id,uint32_t value)
{
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16(4);
    BSP_LCD_SendUint32(value);
}
/*! 
*  \brief     ���������Ǳ�ؼ�
*  \param  control_id �ؼ�ID
*  \param  value ��ֵ
*/
void GUI_BatchSetMeterValue(uint16_t control_id,uint32_t value)
{
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16(4);
    BSP_LCD_SendUint32(value);
}
/*! 
*  \brief      �����ַ�������
*/
uint32_t GetStringLen(uint8_t *str)
{
    uint8_t *p = str;
    while(*str)
    {
        str++;
    }

    return (str-p);
} 
/*! 
*  \brief  ���������ı��ؼ�
*  \param  control_id �ؼ�ID
*  \param  strings �ַ���
*/
void GUI_BatchSetText(uint16_t control_id,uint8_t *strings)
{
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16(GetStringLen(strings));
    BSP_LCD_SendStrings(strings);
}
/*! 
*  \brief     �������¶���\ͼ��ؼ�
*  \param  control_id �ؼ�ID
*  \param  frame_id ֡ID
*/
void GUI_BatchSetFrame(uint16_t control_id,uint16_t frame_id)
{
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16(2);
    BSP_LCD_SendUint16(frame_id);
}

#if FIRMWARE_VER>=908

/*! 
*  \brief     �������ÿؼ��ɼ�
*  \param  control_id �ؼ�ID
*  \param  visible ֡ID
*/
void GUI_BatchSetVisible(uint16_t control_id,uint8_t visible)
{
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_WriteByte(1);
    BSP_LCD_WriteByte(visible);
}
/*! 
*  \brief     �������ÿؼ�ʹ��
*  \param  control_id �ؼ�ID
*  \param  enable ֡ID
*/
void GUI_BatchSetEnable(uint16_t control_id,uint8_t enable)
{
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_WriteByte(2);
    BSP_LCD_WriteByte(enable);
}

#endif
/*! 
*  \brief    ������������
*/
void GUI_BatchEnd()
{
    gui_SendEndCMD();
}
/*! 
*  \brief     ���õ���ʱ�ؼ�
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  timeout ����ʱ(��)
*/
void GUI_SeTimer(uint16_t screen_id,uint16_t control_id,uint32_t timeout)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x40);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint32(timeout);
    gui_SendEndCMD();
}
/*! 
*  \brief     ��������ʱ�ؼ�
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*/
void GUI_StartTimer(uint16_t screen_id,uint16_t control_id)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x41);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    gui_SendEndCMD();
}
/*! 
*  \brief     ֹͣ����ʱ�ؼ�
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*/
void GUI_StopTimer(uint16_t screen_id,uint16_t control_id)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x42);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    gui_SendEndCMD();
}
/*! 
*  \brief     ��ͣ����ʱ�ؼ�
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*/
void GUI_PauseTimer(uint16_t screen_id,uint16_t control_id)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x44);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    gui_SendEndCMD();
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
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x18);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16(color);
    gui_SendEndCMD();
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
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x19);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16(color);
    gui_SendEndCMD();
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
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x13);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_WriteByte(show);
    BSP_LCD_SendUint16(focus_control_id);
    gui_SendEndCMD();
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
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x86);
    BSP_LCD_WriteByte(show);
    BSP_LCD_SendUint16(x);
    BSP_LCD_SendUint16(y);
    BSP_LCD_WriteByte(type);
    BSP_LCD_WriteByte(option);
    BSP_LCD_WriteByte(max_len);
    gui_SendEndCMD();
}

#if FIRMWARE_VER>=921
/*! 
*  \brief     ����������
*  \param  ui_lang �û���������0~9
*  \param  sys_lang ϵͳ��������-0���ģ�1Ӣ��
*/
void GUI_SetLanguage(uint8_t ui_lang,uint8_t sys_lang)
{
    uint8_t lang = ui_lang;
    if(sys_lang)    lang |= 0x80;

    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xC1);
    BSP_LCD_WriteByte(lang);
    BSP_LCD_WriteByte(0xC1+lang);//У�飬��ֹ�����޸�����
    gui_SendEndCMD();
}
#endif


#if FIRMWARE_VER>=921
/*! 
*  \brief     ��ʼ����ؼ���ֵ��FLASH
*  \param  version ���ݰ汾�ţ�������ָ������16λΪ���汾�ţ���16λΪ�ΰ汾��
*  \param  address �������û��洢���Ĵ�ŵ�ַ��ע���ֹ��ַ�ص�����ͻ
*/
void GUI_FlashBeginSaveControl(uint32_t version,uint32_t address)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0xAA);
    BSP_LCD_SendUint32(version);
    BSP_LCD_SendUint32(address);
}

/*! 
*  \brief     ����ĳ���ؼ�����ֵ��FLASH
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*/
void GUI_FlashSaveControl(uint16_t screen_id,uint16_t control_id)
{
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
}
/*! 
*  \brief     ����ĳ���ؼ�����ֵ��FLASH
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*/
void GUI_FlashEndSaveControl()
{
    gui_SendEndCMD();
}
/*! 
*  \brief     ��FLASH�лָ��ؼ�����
*  \param  version ���ݰ汾�ţ����汾�ű�����洢ʱһ�£���������ʧ��
*  \param  address �������û��洢���Ĵ�ŵ�ַ
*/
void GUI_FlashRestoreControl(uint32_t version,uint32_t address)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0xAB);
    BSP_LCD_SendUint32(version);
    BSP_LCD_SendUint32(address);
    gui_SendEndCMD();
}

#endif

#if FIRMWARE_VER>=921
/*! 
*  \brief     ������ʷ���߲�������ֵ(���ֽڣ�uint8_t��int8)
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  value ����������
*  \param  channel ͨ����
*/
void GUI_HistoryGraph_SetValueInt8(uint16_t screen_id,uint16_t control_id,uint8_t *value,uint8_t channel)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x60);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint8N(value,channel);
    gui_SendEndCMD();
}
/*! 
*  \brief     ������ʷ���߲�������ֵ(˫�ֽڣ�uint16_t��int16)
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  value ����������
*  \param  channel ͨ����
*/
void GUI_HistoryGraph_SetValueInt16(uint16_t screen_id,uint16_t control_id,uint16_t *value,uint8_t channel)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x60);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16N(value,channel);
    gui_SendEndCMD();
}
/*! 
*  \brief     ������ʷ���߲�������ֵ(���ֽڣ�uint32_t��int32)
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  value ����������
*  \param  channel ͨ����
*/
void GUI_HistoryGraph_SetValueInt32(uint16_t screen_id,uint16_t control_id,uint32_t *value,uint8_t channel)
{
    uint8_t i = 0;

    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x60);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);

    for (;i<channel;++i)
    {
        BSP_LCD_SendUint32(value[i]);
    }

    gui_SendEndCMD();
}
/*! 
*  \brief     ������ʷ���߲�������ֵ(�����ȸ�����)
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  value ����������
*  \param  channel ͨ����
*/
void GUI_HistoryGraph_SetValueFloat(uint16_t screen_id,uint16_t control_id,float *value,uint8_t channel)
{
    uint8_t i = 0;
    uint32_t tmp = 0;

    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x60);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);

    for (;i<channel;++i)
    {
        tmp = *(uint32_t *)(value+i);
        BSP_LCD_SendUint32(tmp);
    }

    gui_SendEndCMD();
}
/*! 
*  \brief     ������ֹ��ʷ���߲���
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  enable 0-��ֹ��1-����
*/
void GUI_HistoryGraph_EnableSampling(uint16_t screen_id,uint16_t control_id,uint8_t enable)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x61);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_WriteByte(enable);
    gui_SendEndCMD();
}
/*! 
*  \brief     ��ʾ��������ʷ����ͨ��
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  channel ͨ�����
*  \param  show 0-���أ�1-��ʾ
*/
void GUI_HistoryGraph_ShowChannel(uint16_t screen_id,uint16_t control_id,uint8_t channel,uint8_t show)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x62);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_WriteByte(channel);
    BSP_LCD_WriteByte(show);
    gui_SendEndCMD();
}
/*! 
*  \brief     ������ʷ����ʱ�䳤��(����������)
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  sample_count һ����ʾ�Ĳ�������
*/
void GUI_HistoryGraph_SetTimeLength(uint16_t screen_id,uint16_t control_id,uint16_t sample_count)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x63);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_WriteByte(0x00);
    BSP_LCD_SendUint16(sample_count);
    gui_SendEndCMD();
}

/*! 
*  \brief     ��ʷ�������ŵ�ȫ��
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*/
void GUI_HistoryGraph_SetTimeFullScreen(uint16_t screen_id,uint16_t control_id)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x63);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_WriteByte(0x01);
    gui_SendEndCMD();
}
/*! 
*  \brief     ������ʷ�������ű���ϵ��
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  zoom ���Űٷֱ�(zoom>100%ʱˮƽ������С�������Ŵ�)
*  \param  max_zoom �������ƣ�һ�������ʾ��������
*  \param  min_zoom �������ƣ�һ��������ʾ��������
*/
void GUI_HistoryGraph_SetTimeZoom(uint16_t screen_id,uint16_t control_id,uint16_t zoom,uint16_t max_zoom,uint16_t min_zoom)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x63);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_WriteByte(0x02);
    BSP_LCD_SendUint16(zoom);
    BSP_LCD_SendUint16(max_zoom);
    BSP_LCD_SendUint16(min_zoom);
    gui_SendEndCMD();
}

#endif

#if SD_FILE_EN
/*! 
*  \brief     ���SD���Ƿ����
*/
void GUI_SD_IsInsert(void)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x36);
    BSP_LCD_WriteByte(0x01);
    gui_SendEndCMD();
}
/*! 
*  \brief     �򿪻򴴽��ļ�
*  \param  filename �ļ�����(��ASCII����)
*  \param  mode ģʽ����ѡ���ģʽ����FA_XXXX
*/
void GUI_SD_CreateFile(uint8_t *filename,uint8_t mode)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x36);
    BSP_LCD_WriteByte(0x05);
    BSP_LCD_WriteByte(mode);
    BSP_LCD_SendStrings(filename);
    gui_SendEndCMD();
}
/*! 
*  \brief     �Ե�ǰʱ�䴴���ļ�������:20161015083000.txt
*  \param  ext �ļ���׺������ txt
*/
void GUI_SD_CreateFileByTime(uint8_t *ext)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x36);
    BSP_LCD_WriteByte(0x02);
    BSP_LCD_SendStrings(ext);
    gui_SendEndCMD();
}
/*! 
*  \brief     �ڵ�ǰ�ļ�ĩβд������
*  \param  buffer ����
*  \param  dlc ���ݳ���
*/
void GUI_SD_WriteFile(uint8_t *buffer,uint16_t dlc)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x36);
    BSP_LCD_WriteByte(0x03);
    BSP_LCD_SendUint16(dlc);
    BSP_LCD_WriteByteN(buffer,dlc);
    gui_SendEndCMD();
}
/*! 
*  \brief     ��ȡ��ǰ�ļ�
*  \param  offset �ļ�λ��ƫ��
*  \param  dlc ���ݳ���
*/
void GUI_SD_ReadFile(uint32_t offset,uint16_t dlc)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x36);
    BSP_LCD_WriteByte(0x07);
    BSP_LCD_SendUint32(offset);
    BSP_LCD_SendUint16(dlc);
    gui_SendEndCMD();
}

/*! 
*  \brief     ��ȡ��ǰ�ļ�����
*/
void GUI_SD_GetFileSize()
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x36);
    BSP_LCD_WriteByte(0x06);
    gui_SendEndCMD();
}
/*! 
*  \brief     �رյ�ǰ�ļ�
*/
void GUI_SD_CloseFile()
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x36);
    BSP_LCD_WriteByte(0x04);
    gui_SendEndCMD();
}

#endif//SD_FILE_EN
/*! 
*  \brief     ��¼�ؼ�-��������
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  value �澯ֵ
*  \param  time �澯������ʱ�䣬Ϊ0ʱʹ����Ļ�ڲ�ʱ��
*/
void GUI_Record_SetEvent(uint16_t screen_id,uint16_t control_id,uint16_t value,uint8_t *time)
{
    uint8_t i  = 0;

    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x50);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16(value);

    if(time)
    {
        for(i=0;i<7;++i)
            BSP_LCD_WriteByte(time[i]);
    }

    gui_SendEndCMD();
}
/*! 
*  \brief     ��¼�ؼ�-�������
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  value �澯ֵ
*  \param  time �澯�����ʱ�䣬Ϊ0ʱʹ����Ļ�ڲ�ʱ��
*/
void GUI_Record_ResetEvent(uint16_t screen_id,uint16_t control_id,uint16_t value,uint8_t *time)
{
    uint8_t i  = 0;

    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x51);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16(value);

    if(time)
    {
        for(i=0;i<7;++i)
            BSP_LCD_WriteByte(time[i]);
    }

    gui_SendEndCMD();
}
/*! 
*  \brief    ��¼�ؼ�- ��ӳ����¼
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  record һ����¼(�ַ���)������ͨ���ֺŸ��������磺��һ��;�ڶ���;������;
*/
void GUI_Record_Add(uint16_t screen_id,uint16_t control_id,uint8_t *record)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x52);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);

    BSP_LCD_SendStrings(record);

    gui_SendEndCMD();
}
/*! 
*  \brief     ��¼�ؼ�-�����¼����
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*/
void GUI_Record_Clear(uint16_t screen_id,uint16_t control_id)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x53);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    gui_SendEndCMD();
}
/*! 
*  \brief     ��¼�ؼ�-���ü�¼��ʾƫ��
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  offset ��ʾƫ�ƣ�������λ��
*/
void GUI_Record_SetOffset(uint16_t screen_id,uint16_t control_id,uint16_t offset)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x54);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16(offset);
    gui_SendEndCMD();
}
/*! 
*  \brief     ��¼�ؼ�-��ȡ��ǰ��¼��Ŀ
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*/
void GUI_Record_GetCount(uint16_t screen_id,uint16_t control_id)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x55);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    gui_SendEndCMD();
}
/*! 
*  \brief     ��ȡ��ĻRTCʱ��
*/
void GUI_ReadRTC(void)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x82);
    gui_SendEndCMD();
}

/*! 
*  \brief   ��������
*  \param   buffer ʮ�����Ƶ�����·��������
*/
void GUI_PlayMusic(uint8_t *buffer)
{
    uint8_t i  = 0;

    gui_SendHeadCMD();
    if(buffer)
    {
        for(i=0;i<19;++i)
            BSP_LCD_WriteByte(buffer[i]);
    }
    gui_SendEndCMD();
}
/*! 
*  \brief ��ȡ
*  \param  color ����ɫ
*/
void GUI_ColorPicker(uint8_t mode, uint16_t x,uint16_t y)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xA3);
    BSP_LCD_WriteByte(mode);
    BSP_LCD_SendUint16(x);
    BSP_LCD_SendUint16(y);
    gui_SendEndCMD();
}
/*! 
*  \brief  �������ּ��
*  \param  x_w ������
*  \param  y_w ������
*/
void GUI_SetTextSpace(uint8_t x_w, uint8_t y_w)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x43);
    BSP_LCD_WriteByte(x_w);
    BSP_LCD_WriteByte(y_w);
    gui_SendEndCMD();
}
/*! 
*  \brief  ����������ʾ����
*  \param  enable �Ƿ���������
*  \param  width ���
*  \param  height �߶�
*/
void GUI_SetFont_Region(uint8_t enable,uint16_t width,uint16_t height)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x45);
    BSP_LCD_WriteByte(enable);
    BSP_LCD_SendUint16(width);
    BSP_LCD_SendUint16(height);
    gui_SendEndCMD();
}
/*! 
*  \brief  ���ù���ɫ
*  \param  fillcolor_dwon ��ɫ�½�
*  \param  fillcolor_up ��ɫ�Ͻ�
*/
void GUI_SetFilterColor(uint16_t fillcolor_dwon, uint16_t fillcolor_up)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x44);
    BSP_LCD_SendUint16(fillcolor_dwon);
    BSP_LCD_SendUint16(fillcolor_up);
    gui_SendEndCMD();
}

/*! 
*  \brief  ���ù���ɫ
*  \param  x λ��X����
*  \param  y λ��Y����
*  \param  back ��ɫ�Ͻ�
*  \param  font ����
*  \param  strings �ַ�������
*/
void GUI_DisText(uint16_t x, uint16_t y,uint8_t back,uint8_t font,uint8_t *strings )
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x20);
    BSP_LCD_SendUint16(x);
    BSP_LCD_SendUint16(y);
    BSP_LCD_WriteByte(back);
    BSP_LCD_WriteByte(font);
    BSP_LCD_SendStrings(strings);
    gui_SendEndCMD();
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
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x21);
    BSP_LCD_WriteByte(enable);
    BSP_LCD_SendUint16(x);
    BSP_LCD_SendUint16(y);
    BSP_LCD_WriteByte(width);
    BSP_LCD_WriteByte(height);
    gui_SendEndCMD();
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
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x59);
    BSP_LCD_SendUint16(x);
    BSP_LCD_SendUint16(x_space);
    BSP_LCD_SendUint16N(dot_y,dot_cnt);
    gui_SendEndCMD();
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
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x75);
    BSP_LCD_SendUint16(x);
    BSP_LCD_SendUint16(y);
    BSP_LCD_SendUint16N(dot_offset,dot_cnt);
    gui_SendEndCMD();
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
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x76);
    BSP_LCD_SendUint16(x);
    BSP_LCD_SendUint16(y);
    BSP_LCD_SendUint8N(dot_offset,dot_cnt);
    gui_SendEndCMD();
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
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x77);
    BSP_LCD_WriteByte(enable);
    BSP_LCD_WriteByte(bl_off_level);
    BSP_LCD_WriteByte(bl_on_level);
    BSP_LCD_WriteByte(bl_on_time);
    gui_SendEndCMD();
}
/*! 
*  \brief  ���ƶ��Ķ���������ǰ��ɫ��������
*  \param  dot  �����
*  \param  dot_cnt  ƫ��������
*/
void GUI_GUI_FcolorConDots(uint16_t *dot,uint16_t dot_cnt)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x68);
    BSP_LCD_SendUint16N(dot,dot_cnt*2);
    gui_SendEndCMD();
}
/*! 
*  \brief  ���ƶ��Ķ��������ñ���ɫ��������
*  \param  dot  �����
*  \param  dot_cnt  ƫ��������
*/
void GUI_GUI_BcolorConDots(uint16_t *dot,uint16_t dot_cnt)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x69);
    BSP_LCD_SendUint16N(dot,dot_cnt*2);
    gui_SendEndCMD();
}
/*! 
*  \brief     ������Բ
*  \param  x0 Բ��λ��X����
*  \param  y0 Բ��λ��Y����
*  \param  r �뾶
*/
void GUI_GUI_Circle(uint16_t x, uint16_t y, uint16_t r)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x52);
    BSP_LCD_SendUint16(x);
    BSP_LCD_SendUint16(y);
    BSP_LCD_SendUint16(r);
    gui_SendEndCMD();
}
/*! 
*  \brief      ��ʵ��Բ
*  \param  x0 Բ��λ��X����
*  \param  y0 Բ��λ��Y����
*  \param  r �뾶
*/
void GUI_GUI_CircleFill(uint16_t x, uint16_t y, uint16_t r)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x53);
    BSP_LCD_SendUint16(x);
    BSP_LCD_SendUint16(y);
    BSP_LCD_SendUint16(r);
    gui_SendEndCMD();
}
/*! 
*  \brief      ������
*  \param  x0 Բ��λ��X����
*  \param  y0 Բ��λ��Y����
*  \param  r �뾶
*  \param  sa ��ʼ�Ƕ�
*  \param  ea ��ֹ�Ƕ�
*/
void GUI_GUI_Arc(uint16_t x,uint16_t y, uint16_t r,uint16_t sa, uint16_t ea)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x67);
    BSP_LCD_SendUint16(x);
    BSP_LCD_SendUint16(y);
    BSP_LCD_SendUint16(r);
    BSP_LCD_SendUint16(sa);
    BSP_LCD_SendUint16(ea);
    gui_SendEndCMD();
}
/*! 
*  \brief      �����ľ���
*  \param  x0 ��ʼλ��X����
*  \param  y0 ��ʼλ��Y����
*  \param  x1 ����λ��X����
*  \param  y1 ����λ��Y����
*/
void GUI_GUI_Rectangle(uint16_t x0, uint16_t y0, uint16_t x1,uint16_t y1 )
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x54);
    BSP_LCD_SendUint16(x0);
    BSP_LCD_SendUint16(y0);
    BSP_LCD_SendUint16(x1);
    BSP_LCD_SendUint16(y1);
    gui_SendEndCMD();
}
/*! 
*  \brief      ��ʵ�ľ���
*  \param  x0 ��ʼλ��X����
*  \param  y0 ��ʼλ��Y����
*  \param  x1 ����λ��X����
*  \param  y1 ����λ��Y����
*/
void GUI_GUI_RectangleFill(uint16_t x0, uint16_t y0, uint16_t x1,uint16_t y1 )
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x55);
    BSP_LCD_SendUint16(x0);
    BSP_LCD_SendUint16(y0);
    BSP_LCD_SendUint16(x1);
    BSP_LCD_SendUint16(y1);
    gui_SendEndCMD();
}
/*! 
*  \brief      ��������Բ
*  \param  x0 ��ʼλ��X����
*  \param  y0 ��ʼλ��Y����
*  \param  x1 ����λ��X����
*  \param  y1 ����λ��Y����
*/
void GUI_GUI_Ellipse(uint16_t x0, uint16_t y0, uint16_t x1,uint16_t y1 )
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x56);
    BSP_LCD_SendUint16(x0);
    BSP_LCD_SendUint16(y0);
    BSP_LCD_SendUint16(x1);
    BSP_LCD_SendUint16(y1);
    gui_SendEndCMD();
}
/*! 
*  \brief      ��ʵ����Բ
*  \param  x0 ��ʼλ��X����
*  \param  y0 ��ʼλ��Y����
*  \param  x1 ����λ��X����
*  \param  y1 ����λ��Y����
*/
void GUI_GUI_EllipseFill(uint16_t x0, uint16_t y0, uint16_t x1,uint16_t y1 )
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x57);
    BSP_LCD_SendUint16(x0);
    BSP_LCD_SendUint16(y0);
    BSP_LCD_SendUint16(x1);
    BSP_LCD_SendUint16(y1);
    gui_SendEndCMD();
}



void GUI_GUI_AreaInycolor(uint16_t x0, uint16_t y0, uint16_t x1,uint16_t y1 )
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x65);
    BSP_LCD_SendUint16(x0);
    BSP_LCD_SendUint16(y0);
    BSP_LCD_SendUint16(x1);
    BSP_LCD_SendUint16(y1);
    gui_SendEndCMD();
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

    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x70);
    BSP_LCD_WriteByte(options);
    gui_SendEndCMD();
}
/*! 
*  \brief   У׼������
*/
void GUI_CalibrateTouchPane()
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x72);
    gui_SendEndCMD();
}
/*! 
*  \brief  ����������
*/
void GUI_TestTouchPane()
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x73);
    gui_SendEndCMD();
}

/*! 
*  \brief  �����豸���ã�����֮����Ҫ�����������޸Ĳ����ʡ���������������������ʽ
*/
void GUI_LockDeviceConfig(void)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x09);
    BSP_LCD_WriteByte(0xDE);
    BSP_LCD_WriteByte(0xED);
    BSP_LCD_WriteByte(0x13);
    BSP_LCD_WriteByte(0x31);
    gui_SendEndCMD();
}

/*! 
*  \brief  �����豸����
*/
void GUI_UnlockDeviceConfig(void)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x08);
    BSP_LCD_WriteByte(0xA5);
    BSP_LCD_WriteByte(0x5A);
    BSP_LCD_WriteByte(0x5F);
    BSP_LCD_WriteByte(0xF5);
    gui_SendEndCMD();
}
/*! 
*  \brief    �޸Ĵ������Ĳ�����
*  \details  ������ѡ�Χ[0~14]����Ӧʵ�ʲ�����
{1200,2400,4800,9600,19200,38400,57600,115200,1000000,2000000,218750,437500,875000,921800,2500000}
*  \param  option ������ѡ��
*/
void GUI_SetCommBps(uint8_t option)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xA0);
    BSP_LCD_WriteByte(option);
    gui_SendEndCMD();
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
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xA1);
    BSP_LCD_WriteByte(layer);
    gui_SendEndCMD();
}
/*! 
*  \brief      ���õ�ǰ��ʾͼ��
*  \param  layer ͼ����
*/
void GUI_DisplyLayer(uint8_t layer)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xA2);
    BSP_LCD_WriteByte(layer);
    gui_SendEndCMD();
}
/*! 
*  \brief      ����ͼ��
*  \param  src_layer ԭʼͼ��
*  \param  dest_layer Ŀ��ͼ��
*/
void GUI_CopyLayer(uint8_t src_layer,uint8_t dest_layer)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xA4);
    BSP_LCD_WriteByte(src_layer);
    BSP_LCD_WriteByte(dest_layer);
    gui_SendEndCMD();
}
/*! 
*  \brief      ���ͼ�㣬ʹͼ����͸��
*  \param  layer ͼ����
*/
void GUI_ClearLayer(uint8_t layer)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x05);
    BSP_LCD_WriteByte(layer);
    gui_SendEndCMD();
}

void GUI_GUI_DispRTC(uint8_t enable,uint8_t mode,uint8_t font,uint16_t color,uint16_t x,uint16_t y)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x85);
    BSP_LCD_WriteByte(enable);
    BSP_LCD_WriteByte(mode);
    BSP_LCD_WriteByte(font);
    BSP_LCD_SendUint16(color);
    BSP_LCD_SendUint16(x);
    BSP_LCD_SendUint16(y);
    gui_SendEndCMD();
}
/*! 
*  \brief  д���ݵ��������û��洢��
*  \param  startAddress ��ʼ��ַ
*  \param  length �ֽ���
*  \param  _data ��д�������
*/
void GUI_WriteUserFlash(uint32_t startAddress,uint16_t length,uint8_t *_data)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x87);
    BSP_LCD_SendUint32(startAddress);
    BSP_LCD_SendUint8N(_data,length);
    gui_SendEndCMD();
}
/*! 
*  \brief  �Ӵ������û��洢����ȡ����
*  \param  startAddress ��ʼ��ַ
*  \param  length �ֽ���
*/
void GUI_ReadUserFlash(uint32_t startAddress,uint16_t length)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x88);
    BSP_LCD_SendUint32(startAddress);
    BSP_LCD_SendUint16(length);
    gui_SendEndCMD();
}
/*! 
*  \brief      ���ý���ֵ
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  value ��ֵ
*/
void GUI_SetProgressValue(uint16_t screen_id,uint16_t control_id,uint32_t value)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x10);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint32(value);
    gui_SendEndCMD();
}
/*! 
*  \brief     �����Ǳ�ֵ
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  value ��ֵ
*/
void GUI_SetMeterValue(uint16_t screen_id,uint16_t control_id,uint32_t value)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x10);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint32(value);
    gui_SendEndCMD();
}
/*! 
*  \brief     �����Ǳ�ֵ
*  \param  screen_id ����ID
*  \param  control_id ͼƬ�ؼ�ID
*  \param  value ��ֵ
*/
void GUI_Set_picMeterValue(uint16_t screen_id,uint16_t control_id,uint16_t value)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x10);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16(value);
    gui_SendEndCMD();
}
/*! 
*  \brief      ���û�����
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  value ��ֵ
*/

void GUI_SetSliderValue(uint16_t screen_id,uint16_t control_id,uint32_t value)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x10);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint32(value);
    gui_SendEndCMD();
}
/*! 
*  \brief      ����ѡ��ؼ�
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*  \param  item ��ǰѡ��
*/
void GUI_SetSelectorValue(uint16_t screen_id,uint16_t control_id,uint8_t item)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x10);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_WriteByte(item);
    gui_SendEndCMD();
}
/*! 
*  \brief     ��ȡ�ؼ�ֵ
*  \param  screen_id ����ID
*  \param  control_id �ؼ�ID
*/
void GUI_GetControlValue(uint16_t screen_id,uint16_t control_id)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x11);
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
    gui_SendEndCMD();
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
