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
#include "gui_conf.h"
#include "gui_fun.h"
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

/**
* @}
*/

/**
* @defgroup      gui_process_Private_Variables 
* @brief         
* @{  
*/ 
uint8_t cmd_buffer[CMD_MAX_SIZE];                                                     //ָ���
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
static void gui_Message_Process( GUI_Dacai_Proto_t * msg, uint16_t size );
/**
* @}
*/

/**
* @defgroup      gui_process_Functions 
* @brief         
* @{  
*/
/**
 * @brief    ѭ������Ƿ��������
 */

void Gui_CheckCMD_Loop_Process()
{   
    uint16_t size=0;  
    Gui_CMD_Queue_Push();
    if(Gui_CMD_Queue_Pop(cmd_buffer))                                              					 //���յ�ָ��
    {                                                                           
        gui_Message_Process((GUI_Dacai_Proto_t *)cmd_buffer, size);              //ָ���
    }                                                                           
}

/**
 * @brief    ��Ϣ��������
 * @param    msg:GUI_Dacai_Proto_t*  ��������Ϣ
 * @param    size:uint16_t ��Ϣ����
 */

static void gui_Message_Process( GUI_Dacai_Proto_t* msg, uint16_t size )
{
    uint8_t cmd_type = msg->cmd_type;                                                  //ָ������
    uint8_t ctrl_msg = msg->ctrl_msg;                                                  //��Ϣ������
    uint8_t control_type = msg->control_type;                                          //�ؼ�����
    uint16_t screen_id = BIG2LITTLESWAP16(msg->screen_id);                             //����ID
    uint16_t control_id = BIG2LITTLESWAP16(msg->control_id);                           //�ؼ�ID
    uint32_t value = BIG2LITTLESWAP32(msg->param);                                     //��ֵ
    
    
    switch(cmd_type)                                                                
    {  
        case NOTIFY_TOUCH_PRESS:                                                        //����������
        case NOTIFY_TOUCH_RELEASE:                                                      //�������ɿ�
        {
            if(GUI_TOUCH_CallBack!=NULL)
            {
                GUI_TOUCH_CallBack(cmd_buffer[1],BIG2LITTLESWAP16(cmd_buffer[2]),BIG2LITTLESWAP16(cmd_buffer[4])); 
            }
            break;
        }
        case NOTIFY_WRITE_FLASH_OK:                                                     //дFLASH�ɹ�
        {
            if(GUI_FLASHW_CallBack!=NULL)
            {
                GUI_FLASHW_CallBack(1); 
            }
            break;
        }
        case NOTIFY_WRITE_FLASH_FAILD:                                                  //дFLASHʧ��
        {
            if(GUI_FLASHW_CallBack!=NULL)
            {
                GUI_FLASHW_CallBack(0);  
            }
            break;             
        }
        case NOTIFY_READ_FLASH_OK:                                                      //��ȡFLASH�ɹ�
        {
            if(GUI_FLASHR_CallBack!=NULL)
            {
                GUI_FLASHR_CallBack(1,cmd_buffer+2,size-6);                             //ȥ��֡ͷ֡β
            }
            break;                                                                    
        }
        case NOTIFY_READ_FLASH_FAILD:          
        {
            //��ȡFLASHʧ��
            if(GUI_FLASHR_CallBack!=NULL)
            {
                GUI_FLASHR_CallBack(0,0,0);      
            }
            break;
        }
        case NOTIFY_READ_RTC:                                                           //��ȡRTCʱ��
        if(GUI_RTC_CallBack!=NULL)
        {
            GUI_RTC_CallBack(cmd_buffer[2],cmd_buffer[3],cmd_buffer[4],cmd_buffer[5],cmd_buffer[6],cmd_buffer[7],cmd_buffer[8]);
        }
        break;
        case NOTIFY_CONTROL:															//�ؼ�����֪ͨ															//�ؼ�����֪ͨ
        {
            if(ctrl_msg==MSG_GET_CURRENT_SCREEN)                                   		 //����ID�仯֪ͨ
            {   
                if(GUI_SCREEN_CallBack!=NULL)     
                {
                    GUI_SCREEN_CallBack(screen_id);                                            //�����л������ĺ���
                }
            }
            else
            {
                switch(control_type)
                {
                    case kCtrlButton:                                                   //��ť�ؼ�
                    {
                        if(GUI_BUTTON_State_CallBack!=NULL)
                        {
                            GUI_BUTTON_State_CallBack(screen_id,control_id,msg->param[1]);
                        }
                        break;                     
                    }
                    case kCtrlText:                                                     //�ı��ؼ�
                    {
                        if(GUI_TEXT_StringUpdate_CallBack!=NULL)
                        {
                            GUI_TEXT_StringUpdate_CallBack(screen_id,control_id,msg->param);                       
                        }
                        break;              
                    }
                    case kCtrlProgress:                                                 //�������ؼ�
                    {
                        if(GUI_PROGRESS_CallBack!=NULL)
                        {
                            GUI_PROGRESS_CallBack(screen_id,control_id,value);                        
                        }
                        break;                                                             
                    }
                    case kCtrlSlider:                                                   //�������ؼ�
                    {
                        if(GUI_SLIDER_CallBack!=NULL)
                        {
                            GUI_SLIDER_CallBack(screen_id,control_id,value);                          
                            break;                                                             
                        }
                    }
                    case kCtrlMeter:                                                    //�Ǳ�ؼ�
                    {
                        if(GUI_METER_CallBack!=NULL)
                        {
                            GUI_METER_CallBack(screen_id,control_id,value);                           
                            break;                           
                        }
                    }
                    case kCtrlMenu:                                                     //�˵��ؼ�
                    {
                        if(GUI_MENU_CallBack!=NULL)
                        {
                            GUI_MENU_CallBack(screen_id,control_id,msg->param[0],msg->param[1]);      
                            break;                                                              
                        }
                    }
                    case kCtrlSelector:                                                 //ѡ��ؼ�
                    {
                        if(GUI_SELECTOR_CallBack!=NULL)
                        {
                            GUI_SELECTOR_CallBack(screen_id,control_id,msg->param[0]);                
                            break;                                                              
                        }
                    }
                    case kCtrlTimer:                                                    //����ʱ�ؼ�
                    {
                        if(GUI_TIMER_CallBack!=NULL)
                        {
                            GUI_TIMER_CallBack(screen_id,control_id);
                            break;
                        }
                    }
                    default:
                    break;
                }
            } 
            break;  
        } 
        case NOTIFY_HandShake:                                                          //����֪ͨ                                                     
        GUI_HANDSHAKE_CallBack();
        break;
        default:
        break;
        
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

