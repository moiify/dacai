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
uint8_t cmd_buffer[CMD_MAX_SIZE];                                                     //指令缓存
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
 * @brief    循环检查是否存在命令
 */

void Gui_CheckCMD_Loop_Process()
{   
    uint16_t size=0;  
    Gui_CMD_Queue_Push();
    if(Gui_CMD_Queue_Pop(cmd_buffer))                                              					 //接收到指令
    {                                                                           
        gui_Message_Process((GUI_Dacai_Proto_t *)cmd_buffer, size);              //指令处理
    }                                                                           
}

/**
 * @brief    消息处理流程
 * @param    msg:GUI_Dacai_Proto_t*  待处理消息
 * @param    size:uint16_t 消息长度
 */

static void gui_Message_Process( GUI_Dacai_Proto_t* msg, uint16_t size )
{
    uint8_t cmd_type = msg->cmd_type;                                                  //指令类型
    uint8_t ctrl_msg = msg->ctrl_msg;                                                  //消息的类型
    uint8_t control_type = msg->control_type;                                          //控件类型
    uint16_t screen_id = BIG2LITTLESWAP16(msg->screen_id);                             //画面ID
    uint16_t control_id = BIG2LITTLESWAP16(msg->control_id);                           //控件ID
    uint32_t value = BIG2LITTLESWAP32(msg->param);                                     //数值
    
    
    switch(cmd_type)                                                                
    {  
        case NOTIFY_TOUCH_PRESS:                                                        //触摸屏按下
        case NOTIFY_TOUCH_RELEASE:                                                      //触摸屏松开
        {
            if(GUI_TOUCH_CallBack!=NULL)
            {
                GUI_TOUCH_CallBack(cmd_buffer[1],BIG2LITTLESWAP16(cmd_buffer[2]),BIG2LITTLESWAP16(cmd_buffer[4])); 
            }
            break;
        }
        case NOTIFY_WRITE_FLASH_OK:                                                     //写FLASH成功
        {
            if(GUI_FLASHW_CallBack!=NULL)
            {
                GUI_FLASHW_CallBack(1); 
            }
            break;
        }
        case NOTIFY_WRITE_FLASH_FAILD:                                                  //写FLASH失败
        {
            if(GUI_FLASHW_CallBack!=NULL)
            {
                GUI_FLASHW_CallBack(0);  
            }
            break;             
        }
        case NOTIFY_READ_FLASH_OK:                                                      //读取FLASH成功
        {
            if(GUI_FLASHR_CallBack!=NULL)
            {
                GUI_FLASHR_CallBack(1,cmd_buffer+2,size-6);                             //去除帧头帧尾
            }
            break;                                                                    
        }
        case NOTIFY_READ_FLASH_FAILD:          
        {
            //读取FLASH失败
            if(GUI_FLASHR_CallBack!=NULL)
            {
                GUI_FLASHR_CallBack(0,0,0);      
            }
            break;
        }
        case NOTIFY_READ_RTC:                                                           //读取RTC时间
        if(GUI_RTC_CallBack!=NULL)
        {
            GUI_RTC_CallBack(cmd_buffer[2],cmd_buffer[3],cmd_buffer[4],cmd_buffer[5],cmd_buffer[6],cmd_buffer[7],cmd_buffer[8]);
        }
        break;
        case NOTIFY_CONTROL:															//控件更新通知															//控件更新通知
        {
            if(ctrl_msg==MSG_GET_CURRENT_SCREEN)                                   		 //画面ID变化通知
            {   
                if(GUI_SCREEN_CallBack!=NULL)     
                {
                    GUI_SCREEN_CallBack(screen_id);                                            //画面切换调动的函数
                }
            }
            else
            {
                switch(control_type)
                {
                    case kCtrlButton:                                                   //按钮控件
                    {
                        if(GUI_BUTTON_State_CallBack!=NULL)
                        {
                            GUI_BUTTON_State_CallBack(screen_id,control_id,msg->param[1]);
                        }
                        break;                     
                    }
                    case kCtrlText:                                                     //文本控件
                    {
                        if(GUI_TEXT_StringUpdate_CallBack!=NULL)
                        {
                            GUI_TEXT_StringUpdate_CallBack(screen_id,control_id,msg->param);                       
                        }
                        break;              
                    }
                    case kCtrlProgress:                                                 //进度条控件
                    {
                        if(GUI_PROGRESS_CallBack!=NULL)
                        {
                            GUI_PROGRESS_CallBack(screen_id,control_id,value);                        
                        }
                        break;                                                             
                    }
                    case kCtrlSlider:                                                   //滑动条控件
                    {
                        if(GUI_SLIDER_CallBack!=NULL)
                        {
                            GUI_SLIDER_CallBack(screen_id,control_id,value);                          
                            break;                                                             
                        }
                    }
                    case kCtrlMeter:                                                    //仪表控件
                    {
                        if(GUI_METER_CallBack!=NULL)
                        {
                            GUI_METER_CallBack(screen_id,control_id,value);                           
                            break;                           
                        }
                    }
                    case kCtrlMenu:                                                     //菜单控件
                    {
                        if(GUI_MENU_CallBack!=NULL)
                        {
                            GUI_MENU_CallBack(screen_id,control_id,msg->param[0],msg->param[1]);      
                            break;                                                              
                        }
                    }
                    case kCtrlSelector:                                                 //选择控件
                    {
                        if(GUI_SELECTOR_CallBack!=NULL)
                        {
                            GUI_SELECTOR_CallBack(screen_id,control_id,msg->param[0]);                
                            break;                                                              
                        }
                    }
                    case kCtrlTimer:                                                    //倒计时控件
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
        case NOTIFY_HandShake:                                                          //握手通知                                                     
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

