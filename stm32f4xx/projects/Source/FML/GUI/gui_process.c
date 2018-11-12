/**
 **************************************************************************************************
 * @file        gui_process.c
 * @author
 * @version   v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#include "gui_cmd_queue.h"
#include "gui_process.h"
#include "gui_dev_api.h"
#include "system_info.h"
#include "stm32_bsp_conf.h"

/**
 * @addtogroup    XXX 
 * @{  
 */

/**
 * @addtogroup    gui_process_Modules 
 * @{  
 */

/**
 * @defgroup      gui_process_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_process_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_process_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_process_Private_Types
 * @brief         
 * @{  
 */
typedef struct
{
    uint8_t current_screen_id;
    uint8_t current_equip_id;
}s_CBvalue_t;

/**
 * @}
 */

/**
 * @defgroup      gui_process_Private_Variables 
 * @brief         
 * @{  
 */ 
uint8_t cmd_buffer[CMD_MAX_SIZE];                                                     //ָ���

s_CBvalue_t s_CBvalue={
 .current_screen_id=0,}; 
/**
 * @}
 */

/**
 * @defgroup      gui_process_Public_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_process_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */
static void gui_Message_Process( PCTRL_MSG_t msg, uint16_t size );
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
static void gui_notify_readflash(uint8_t status,uint8_t *_data,uint16_t length);
static void gui_notify_writeflash(uint8_t status);
static void gui_notify_readrtc(uint8_t year,uint8_t month,uint8_t week,uint8_t day,uint8_t hour,uint8_t minute,uint8_t second);

static void text_screen_update_event();
/**
 * @}
 */

/**
 * @defgroup      gui_process_Functions 
 * @brief         
 * @{  
 */
void Gui_CheckCMD_Loop_Process()
{   
    uint8_t size=0;
    
    size = GUI_Queue_Find_Cmd(cmd_buffer,CMD_MAX_SIZE);                          //�ӻ������л�ȡһ��ָ��         
    
    if(size>0&&cmd_buffer[1]!=0x07)                                              //���յ�ָ�� �����ж��Ƿ�Ϊ������ʾ
    {                                                                           
        gui_Message_Process((PCTRL_MSG_t)cmd_buffer, size);                      //ָ���
        
    }                                                                           
    else if(size>0&&cmd_buffer[1]==0x07)                                         //���Ϊָ��0x07��������STM32  
    {                                                                           
        __disable_fault_irq();                                                   
        NVIC_SystemReset();                                                                                                                                          
    }      
}
///*! 
//*  \brief  ��Ϣ��������
//*  \param msg ��������Ϣ
//*  \param size ��Ϣ����
//*/
static void gui_Message_Process( PCTRL_MSG_t msg, uint16_t size )
{
    uint8_t cmd_type = msg->cmd_type;                                                  //ָ������
    uint8_t ctrl_msg = msg->ctrl_msg;                                                  //��Ϣ������
    uint8_t control_type = msg->control_type;                                          //�ؼ�����
    uint16_t screen_id = PTR2U16(msg->screen_id);                                     //����ID
    uint16_t control_id = PTR2U16(msg->control_id);                                   //�ؼ�ID
    uint32_t value = PTR2U32(msg->param);                                              //��ֵ

  
    switch(cmd_type)                                                                
    {  
    case NOTIFY_TOUCH_PRESS:                                                        //����������
    case NOTIFY_TOUCH_RELEASE:                                                      //�������ɿ�
        gui_notify_touchxy(cmd_buffer[1],PTR2U16(cmd_buffer[2]),PTR2U16(cmd_buffer[4])); 
        break;                                                                    
    case NOTIFY_WRITE_FLASH_OK:                                                     //дFLASH�ɹ�
        gui_notify_writeflash(1);                                                      
        break;                                                                    
    case NOTIFY_WRITE_FLASH_FAILD:                                                  //дFLASHʧ��
        gui_notify_writeflash(0);                                                      
        break;                                                                    
    case NOTIFY_READ_FLASH_OK:                                                      //��ȡFLASH�ɹ�
        gui_notify_readflash(1,cmd_buffer+2,size-6);                                //ȥ��֡ͷ֡β
        break;                                                                    
    case NOTIFY_READ_FLASH_FAILD:                                                   //��ȡFLASHʧ��
        gui_notify_readflash(0,0,0);                                                   
        break;                                                                    
    case NOTIFY_READ_RTC:                                                           //��ȡRTCʱ��
        gui_notify_readrtc(cmd_buffer[2],cmd_buffer[3],cmd_buffer[4],cmd_buffer[5],cmd_buffer[6],cmd_buffer[7],cmd_buffer[8]);
        break;
    case NOTIFY_CONTROL:															//�ؼ�����֪ͨ															//�ؼ�����֪ͨ
        {
            if(ctrl_msg==MSG_GET_CURRENT_SCREEN)                                    //����ID�仯֪ͨ
            {
                gui_notify_screen(screen_id);                                            //�����л������ĺ���
            }
            else
            {
                switch(control_type)
                {
                case kCtrlButton:                                                   //��ť�ؼ�
                    gui_notify_button(screen_id,control_id,msg->param[1]);                  
                    break;                                                             
                case kCtrlText:                                                     //�ı��ؼ�
                    gui_notify_text(screen_id,control_id,msg->param);                       
                    break;                                                             
                case kCtrlProgress:                                                 //�������ؼ�
                    gui_notify_progress(screen_id,control_id,value);                        
                    break;                                                             
                case kCtrlSlider:                                                   //�������ؼ�
                    gui_notify_slider(screen_id,control_id,value);                          
                    break;                                                             
                case kCtrlMeter:                                                    //�Ǳ�ؼ�
                    gui_notify_meter(screen_id,control_id,value);                           
                    break;                                                             
                case kCtrlMenu:                                                     //�˵��ؼ�
                    gui_notify_menu(screen_id,control_id,msg->param[0],msg->param[1]);      
                    break;                                                              
                case kCtrlSelector:                                                 //ѡ��ؼ�
                    gui_notify_selector(screen_id,control_id,msg->param[0]);                
                    break;                                                              
                case kCtrlRTC:                                                      //����ʱ�ؼ�
                    gui_notify_timer(screen_id,control_id);
                    break;
                default:
                    break;
                }
            } 
            break;  
        } 
    case NOTIFY_HandShake:                                                          //����֪ͨ                                                     
        gui_notify_handshake();
        break;
    default:
        break;
    }
}
/*! 
*  \brief  ����֪ͨ
*/
static void gui_notify_handshake()
{

}

/*! 
*  \brief  �����л�֪ͨ
*  \details  ��ǰ����ı�ʱ(�����GetScreen)��ִ�д˺���
*  \param screen_id ��ǰ����ID
*/
static void gui_notify_screen(uint16_t screen_id)
{
    s_CBvalue.current_screen_id = screen_id;    
}
/*! 
*  \brief  ���������¼���Ӧ
*  \param press 1���´�������3�ɿ�������
*  \param x x����
*  \param y y����
*/
static void gui_notify_touchxy(uint8_t press,uint16_t x,uint16_t y)
{ 
    //TODO: ����û�����
}
/*! 
*  \brief  ��ť�ؼ�֪ͨ
*  \details  ����ť״̬�ı�(�����GetControlValue)ʱ��ִ�д˺���
*  \param screen_id ����ID
*  \param control_id �ؼ�ID
*  \param state ��ť״̬��0����1����
*/
static void gui_notify_button(uint16_t screen_id, uint16_t control_id, uint8_t  state)
{ 
}
/*! 
*  \brief  �ı��ؼ�֪ͨ
*  \details  ���ı�ͨ�����̸���(�����GetControlValue)ʱ��ִ�д˺���
*  \details  �ı��ؼ����������ַ�����ʽ�·���MCU������ı��ؼ������Ǹ���ֵ��
*  \details  ����Ҫ�ڴ˺����н��·��ַ�������ת�ظ���ֵ��
*  \param screen_id ����ID
*  \param control_id �ؼ�ID
*  \param str �ı��ؼ�����
*/
static void gui_notify_text(uint16_t screen_id, uint16_t control_id, uint8_t *str)
{
  //TODO: ����û�����                                                 
}                                                                                

/*!                                                                              
*  \brief  �������ؼ�֪ͨ                                                       
*  \details  ����GetControlValueʱ��ִ�д˺���                                  
*  \param screen_id ����ID                                                      
*  \param control_id �ؼ�ID                                                     
*  \param value ֵ                                                              
*/                                                                              
static void gui_notify_progress(uint16_t screen_id, uint16_t control_id, uint32_t value)           
{  
   //TODO: ����û�����
}                                                                                

/*!                                                                              
*  \brief  �������ؼ�֪ͨ                                                       
*  \details  ���������ı�(�����GetControlValue)ʱ��ִ�д˺���                  
*  \param screen_id ����ID                                                      
*  \param control_id �ؼ�ID                                                     
*  \param value ֵ                                                              
*/                                                                              
static void gui_notify_slider(uint16_t screen_id, uint16_t control_id, uint32_t value)             
{                                                             
    //TODO: ����û�����
}

/*! 
*  \brief  �Ǳ�ؼ�֪ͨ
*  \details  ����GetControlValueʱ��ִ�д˺���
*  \param screen_id ����ID
*  \param control_id �ؼ�ID
*  \param value ֵ
*/
static void gui_notify_meter(uint16_t screen_id, uint16_t control_id, uint32_t value)
{
    //TODO: ����û�����
}

/*! 
*  \brief  �˵��ؼ�֪ͨ
*  \details  ���˵���»��ɿ�ʱ��ִ�д˺���
*  \param screen_id ����ID
*  \param control_id �ؼ�ID
*  \param item �˵�������
*  \param state ��ť״̬��0�ɿ���1����
*/
static void gui_notify_menu(uint16_t screen_id, uint16_t control_id, uint8_t item, uint8_t state)
{
    switch(screen_id)
    {
        case TEXTVALUESCREENID:
        s_CBvalue.current_equip_id=item;
        break;
        default:
        break;
    }
}

/*! 
*  \brief  ѡ��ؼ�֪ͨ
*  \details  ��ѡ��ؼ��仯ʱ��ִ�д˺���
*  \param screen_id ����ID
*  \param control_id �ؼ�ID
*  \param item ��ǰѡ��
*/
static void gui_notify_selector(uint16_t screen_id, uint16_t control_id, uint8_t  item)
{
   
}

/*! 
*  \brief  ��ʱ����ʱ֪ͨ����
*  \param screen_id ����ID
*  \param control_id �ؼ�ID
*/
static void gui_notify_timer(uint16_t screen_id, uint16_t control_id)
{
  //TODO: ����û�����   
}

/*! 
*  \brief  ��ȡ�û�FLASH״̬����
*  \param status 0ʧ�ܣ�1�ɹ�
*  \param _data ��������
*  \param length ���ݳ���
*/
static void gui_notify_readflash(uint8_t status,uint8_t *_data,uint16_t length)
{
    //TODO: ����û�����
}

/*! 
*  \brief  д�û�FLASH״̬����
*  \param status 0ʧ�ܣ�1�ɹ�
*/
static void gui_notify_writeflash(uint8_t status)
{
    //TODO: ����û�����
}

/*! 
*  \brief  ��ȡRTCʱ�䣬ע�ⷵ�ص���BCD��
*  \param year �꣨BCD��
*  \param month �£�BCD��
*  \param week ���ڣ�BCD��
*  \param day �գ�BCD��
*  \param hour ʱ��BCD��
*  \param minute �֣�BCD��
*  \param second �루BCD��
*/
static void gui_notify_readrtc(uint8_t year,uint8_t month,uint8_t week,uint8_t day,uint8_t hour,uint8_t minute,uint8_t second)
{
     //TODO: ����û�����
}


/*! 
*  \brief  ��������
*/ 
void GUI_Update(void)
{   
//    uint8_t a;
//    a=s_CBvalue.current_screen_id;
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
static void text_screen_update_event()
{   
    
    GUI_TEXT_SetFloat(TEXTVALUESCREENID,TEXT1_VALUCONTROLCID,g_SystemInfo.Equip_Info[s_CBvalue.current_equip_id-1].tem,1,1);
    GUI_TEXT_SetFloat(TEXTVALUESCREENID,TEXT2_VALUCONTROLCID,g_SystemInfo.Equip_Info[s_CBvalue.current_equip_id-1].pre,1,1);
    GUI_TEXT_SetFloat(TEXTVALUESCREENID,TEXT3_VALUCONTROLCID,g_SystemInfo.Equip_Info[s_CBvalue.current_equip_id-1].water,1,1);        
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

