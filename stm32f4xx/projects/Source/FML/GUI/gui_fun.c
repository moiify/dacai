/**
 **************************************************************************************************
 * @file        gui_fun.c
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
#include "gui_task.h"
#include "system_info.h"
#include "gui_fun.h"
/**
 * @addtogroup    XXX 
 * @{  
 */

/**
 * @addtogroup    gui_fun_Modules 
 * @{  
 */

/**
 * @defgroup      gui_fun_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_fun_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_fun_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_fun_Private_Types
 * @brief         
 * @{  
 */
typedef struct
{
    uint8_t current_screen_id;
    uint8_t current_equip_id;
    uint8_t finger_name_buf[10];
    uint8_t finger_id_buf[10];
    uint16_t record_count;
}CBvalue_t;
/**
 * @}
 */

/**
 * @defgroup      gui_fun_Private_Variables 
 * @brief         
 * @{  
 */
static CBvalue_t s_CBvalue=
{
    .current_screen_id=99,
    .current_equip_id=1,
    .record_count=0,
}; 
static uint8_t sprint_buf[100];
/**
 * @}
 */

/**
 * @defgroup      gui_fun_Public_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_fun_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */
static void gui_notify_handshake();
static void gui_notify_screen(uint16_t screen_id);
static void gui_notify_button(uint16_t screen_id, uint16_t control_id, uint8_t  state);
static void gui_notify_touchxy(uint8_t press,uint16_t x,uint16_t y);
static void gui_notify_text(uint16_t screen_id, uint16_t control_id, uint8_t *str);
static void gui_notify_progress(uint16_t screen_id, uint16_t control_id, uint32_t value);
static void gui_notify_slider(uint16_t screen_id, uint16_t control_id, uint32_t value);
static void gui_notify_meter(uint16_t screen_id, uint16_t control_id, uint32_t value);
static void gui_notify_menu(uint16_t screen_id, uint16_t control_id, uint8_t item, uint8_t state);
static void gui_notify_selector(uint16_t screen_id, uint16_t control_id, uint8_t  item);
static void gui_notify_timer(uint16_t screen_id, uint16_t control_id);
static void gui_notify_readflash(uint8_t status,uint8_t *data,uint16_t length);
static void gui_notify_writeflash(uint8_t status);
static void gui_notify_readrtc(uint8_t year,uint8_t month,uint8_t week,uint8_t day,uint8_t hour,uint8_t minute,uint8_t second);
static void text_screen_update_event();
/**
 * @}
 */

/**
 * @defgroup      gui_fun_Functions 
 * @brief         
 * @{  
 */
     
void GUI_CON_SetCallBack()
{
    GUI_SetScreenCallback(gui_notify_screen);
    GUI_SetHandShakeCallback(gui_notify_handshake);
    GUI_SetButtonCallback(gui_notify_button);
    GUI_SetTouchCallback(gui_notify_touchxy);
    GUI_SetTextCallback(gui_notify_text);
    GUI_SetProgressCallback(gui_notify_progress);
    GUI_SetSliderCallback(gui_notify_slider);
    GUI_SetMeterCallback(gui_notify_meter);
    GUI_SetMenuCallback(gui_notify_menu);
    GUI_SetSelectorCallback(gui_notify_selector);
    GUI_SetTimerCallback(gui_notify_timer);
    GUI_SetFlashWCallback(gui_notify_writeflash);
    GUI_SetFlashRCallback(gui_notify_readflash);
    GUI_SetRtcCallback(gui_notify_readrtc);
}
/**
 * @brief    ����֪ͨ
 */
static void gui_notify_handshake()
{
    
}

/**
 * @brief    �����л�֪ͨ
 * @param    screen_id:uint16_t ��ǰ����ID
 */
static void gui_notify_screen(uint16_t screen_id)
{
    s_CBvalue.current_screen_id = screen_id;
    GuiTask_Send_Event(GUI_TASK_KEY_PROCESS_EVENT);    
}

/**
 * @brief    ���������¼���Ӧ
 * @param    press:uint8_t 1���´�������3�ɿ�������
 * @param    x:uint16_t x����
 * @param    y:uint16_t y����
 */

static void gui_notify_touchxy(uint8_t press,uint16_t x,uint16_t y)
{ 
    //TODO: ����û�����
}
/** 
*  @brief  ��ť�ؼ�֪ͨ
*  @param screen_id ����ID
*  @param control_id �ؼ�ID
*  @param state ��ť״̬��0����1����
*/
static void gui_notify_button(uint16_t screen_id, uint16_t control_id, uint8_t  state)
{ 
    switch (screen_id)
    {
        case FINGERMANAGESCREENID:
        switch (control_id)
        {
            //        GUI_TEXT_GetValue(FINGERMANAGESCREENID,FINGER_NAME_VALUCONTROLCID);
            //        GUI_TEXT_GetValue(FINGERMANAGESCREENID,FINGER_ID_VALUCONTROLCID);
        }
        case RECORDSCREENID:
        {
            if(state==1) //1��ʾ����
            {
                switch(control_id)
                {   
                    
                    case ADDCONTROLID:
                    {
                        sprintf((char *)sprint_buf,"��ӵ�%d������;�¶�:%d.%d%d;ѹ��:%d.%d%d",1+s_CBvalue.record_count++,
                                g_SystemInfo.Equip_Info[s_CBvalue.current_equip_id-1].tem/100,g_SystemInfo.Equip_Info[s_CBvalue.current_equip_id-1].tem/10%10,g_SystemInfo.Equip_Info[s_CBvalue.current_equip_id-1].tem%10,
                                g_SystemInfo.Equip_Info[s_CBvalue.current_equip_id-1].pre/100,g_SystemInfo.Equip_Info[s_CBvalue.current_equip_id-1].pre/10%10,g_SystemInfo.Equip_Info[s_CBvalue.current_equip_id-1].pre%10);
                        GUI_Record_Add(RECORDSCREENID,RECORDCONTROLID,sprint_buf);            
                    }
                    break;
                    case DELLTECONTROLID:
                    {   
                        if(s_CBvalue.record_count>0)
                        {
                            GUI_Record_Delete(RECORDSCREENID,RECORDCONTROLID,--s_CBvalue.record_count);
                        }
                    }
                    break;
                    case EMPTYCONTROLID:
                    {
                        GUI_Record_Clear(RECORDSCREENID,RECORDCONTROLID);
                        s_CBvalue.record_count=0;
                    }
                    break;
                    default:
                    break;
                    
                }
            }
        }
        default:
        break;
    }
}
/** 
*  @brief  �ı��ؼ�֪ͨ
*  @details  ���ı�ͨ�����̸���(�����GetControlValue)ʱ��ִ�д˺���
*  @details  �ı��ؼ����������ַ�����ʽ�·���MCU������ı��ؼ������Ǹ���ֵ��
*  @details  ����Ҫ�ڴ˺����н��·��ַ�������ת�ظ���ֵ��
*  @param screen_id ����ID
*  @param control_id �ؼ�ID
*  @param str �ı��ؼ�����
*/
static void gui_notify_text(uint16_t screen_id, uint16_t control_id, uint8_t *str)
{   
    uint8_t i=0;
    switch(screen_id)
    {
        case FINGERMANAGESCREENID:
        switch(control_id)
        {
            case FINGER_NAME_VALUCONTROLCID:
            {
                while(*str)
                {
                    s_CBvalue.finger_name_buf[i++]=*str++;
                }
                s_CBvalue.finger_name_buf[i]=0; 
            }
            case FINGER_ID_VALUCONTROLCID:
            {
                while(*str)
                {
                    s_CBvalue.finger_id_buf[i++]=*str++;
                }
                s_CBvalue.finger_id_buf[i]=0; 
            }
            default:
            break;
        }
        default:
        break;                              
    }                                 
}
/**                                                                              
*  @brief  �������ؼ�֪ͨ 
*  @param screen_id ����ID                                                      
*  @param control_id �ؼ�ID                                                     
*  @param value ֵ                                                              
*/                                                                              
static void gui_notify_progress(uint16_t screen_id, uint16_t control_id, uint32_t value)           
{  
    //TODO: ����û�����
}                                                                                

/**                                                                              
*  @brief  �������ؼ�֪ͨ                                                       
                
*  @param screen_id ����ID                                                      
*  @param control_id �ؼ�ID                                                     
*  @param value ֵ                                                              
*/                                                                              
static void gui_notify_slider(uint16_t screen_id, uint16_t control_id, uint32_t value)             
{                                                             
    //TODO: ����û�����
}

/** 
*  @brief  �Ǳ�ؼ�֪ͨ

*  @param screen_id ����ID
*  @param control_id �ؼ�ID
*  @param value ֵ
*/
static void gui_notify_meter(uint16_t screen_id, uint16_t control_id, uint32_t value)
{
    //TODO: ����û�����
}

/** 
*  @brief  �˵��ؼ�֪ͨ
*  @details  ���˵���»��ɿ�ʱ��ִ�д˺���
*  @param screen_id ����ID
*  @param control_id �ؼ�ID
*  @param item �˵�������
*  @param state ��ť״̬��0�ɿ���1����
*/
static void gui_notify_menu(uint16_t screen_id, uint16_t control_id, uint8_t item, uint8_t state)
{
    switch(screen_id)
    {
        case TEXTVALUESCREENID:
        s_CBvalue.current_equip_id=item+1;
        GuiTask_Send_Event(GUI_TASK_KEY_PROCESS_EVENT);
        break;
        default:
        break;
    }
}

/** 
*  @brief  ѡ��ؼ�֪ͨ
*  @details  ��ѡ��ؼ��仯ʱ��ִ�д˺���
*  @param screen_id ����ID
*  @param control_id �ؼ�ID
*  @param item ��ǰѡ��
*/

static void gui_notify_selector(uint16_t screen_id, uint16_t control_id, uint8_t  item)
{
    
}

/** 
*  @brief  ��ʱ����ʱ֪ͨ����
*  @param screen_id ����ID
*  @param control_id �ؼ�ID
*/
static void gui_notify_timer(uint16_t screen_id, uint16_t control_id)
{
    //TODO: ����û�����   
}

/** 
*  @brief  ��ȡ�û�FLASH״̬����
*  @param status 0ʧ�ܣ�1�ɹ�
*  @param _data ��������
*  @param length ���ݳ���
*/
static void gui_notify_readflash(uint8_t status,uint8_t *_data,uint16_t length)
{
    //TODO: ����û�����
}

/** 
*  @brief  д�û�FLASH״̬����
*  @param status 0ʧ�ܣ�1�ɹ�
*/
static void gui_notify_writeflash(uint8_t status)
{
    //TODO: ����û�����
}

/** 
*  @brief  ��ȡRTCʱ�䣬ע�ⷵ�ص���BCD��
*  @param year �꣨BCD��
*  @param month �£�BCD��
*  @param week ���ڣ�BCD��
*  @param day �գ�BCD��
*  @param hour ʱ��BCD��
*  @param minute �֣�BCD��
*  @param second �루BCD��
*/
static void gui_notify_readrtc(uint8_t year,uint8_t month,uint8_t week,uint8_t day,uint8_t hour,uint8_t minute,uint8_t second)
{
    //TODO: ����û�����
}


/** 
*  @brief  ��������
*/ 
void GUI_Update(void)
{   
    switch(s_CBvalue.current_screen_id)
    {
        case TEXTVALUESCREENID:
        text_screen_update_event();
        break;
        case FINGERMANAGESCREENID:
        break;
        
        case CONFIGSCREENID:
        
        break;
        default:        
        break;
    }
}

/**
 * @brief    �豸��Ϣ��������¼�
 */

static void text_screen_update_event()
{   
    GUI_TEXT_SetInt32(TEXTVALUESCREENID,EQUIP_ID_VALUEID,s_CBvalue.current_equip_id,0,4);
    GUI_GIF_Pause(TEXTVALUESCREENID,GIF1_VALUCONTROLCID);  
    sprintf((char *)sprint_buf,"%d.%d%d",g_SystemInfo.Equip_Info[s_CBvalue.current_equip_id-1].tem/100,g_SystemInfo.Equip_Info[s_CBvalue.current_equip_id-1].tem/10%10,g_SystemInfo.Equip_Info[s_CBvalue.current_equip_id-1].tem%10);
    GUI_TEXT_SetText(TEXTVALUESCREENID,TEXT1_VALUCONTROLCID,sprint_buf);
    sprintf((char *)sprint_buf,"%d.%d%d",g_SystemInfo.Equip_Info[s_CBvalue.current_equip_id-1].pre/100,g_SystemInfo.Equip_Info[s_CBvalue.current_equip_id-1].pre/10%10,g_SystemInfo.Equip_Info[s_CBvalue.current_equip_id-1].pre%10);
    GUI_TEXT_SetText(TEXTVALUESCREENID,TEXT2_VALUCONTROLCID,sprint_buf);
    sprintf((char *)sprint_buf,"%d.%d%d",g_SystemInfo.Equip_Info[s_CBvalue.current_equip_id-1].water/100,g_SystemInfo.Equip_Info[s_CBvalue.current_equip_id-1].water/10%10,g_SystemInfo.Equip_Info[s_CBvalue.current_equip_id-1].water%10);
    GUI_TEXT_SetText(TEXTVALUESCREENID,TEXT3_VALUCONTROLCID,sprint_buf);
    if(g_SystemInfo.Equip_Info[s_CBvalue.current_equip_id-1].run_state==1)
    {
        sprintf((char *)sprint_buf,"������");
        GUI_TEXT_SetText(TEXTVALUESCREENID,TEXT4_VALUCONTROLCID,sprint_buf);
        GUI_Icon_PlayFrame(TEXTVALUESCREENID,Frame1_VALUCONTROLCID,0);
        GUI_GIF_Stop(TEXTVALUESCREENID,GIF1_VALUCONTROLCID);
        GUI_GIF_Start(TEXTVALUESCREENID,GIF1_VALUCONTROLCID);
    }
    else 
    {
        sprintf((char *)sprint_buf,"δ����");
        GUI_TEXT_SetText(TEXTVALUESCREENID,TEXT4_VALUCONTROLCID,sprint_buf);
        GUI_Icon_PlayFrame(TEXTVALUESCREENID,Frame1_VALUCONTROLCID,1);
        GUI_GIF_Stop(TEXTVALUESCREENID,GIF1_VALUCONTROLCID);  
    }
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

