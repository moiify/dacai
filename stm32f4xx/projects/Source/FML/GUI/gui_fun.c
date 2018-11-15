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
 * @brief    握手通知
 */
static void gui_notify_handshake()
{
    
}

/**
 * @brief    画面切换通知
 * @param    screen_id:uint16_t 当前画面ID
 */
static void gui_notify_screen(uint16_t screen_id)
{
    s_CBvalue.current_screen_id = screen_id;
    GuiTask_Send_Event(GUI_TASK_KEY_PROCESS_EVENT);    
}

/**
 * @brief    触摸坐标事件响应
 * @param    press:uint8_t 1按下触摸屏，3松开触摸屏
 * @param    x:uint16_t x坐标
 * @param    y:uint16_t y坐标
 */

static void gui_notify_touchxy(uint8_t press,uint16_t x,uint16_t y)
{ 
    //TODO: 添加用户代码
}
/** 
*  @brief  按钮控件通知
*  @param screen_id 画面ID
*  @param control_id 控件ID
*  @param state 按钮状态：0弹起，1按下
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
            if(state==1) //1表示按下
            {
                switch(control_id)
                {   
                    
                    case ADDCONTROLID:
                    {
                        sprintf((char *)sprint_buf,"添加第%d条数据;温度:%d.%d%d;压力:%d.%d%d",1+s_CBvalue.record_count++,
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
*  @brief  文本控件通知
*  @details  当文本通过键盘更新(或调用GetControlValue)时，执行此函数
*  @details  文本控件的内容以字符串形式下发到MCU，如果文本控件内容是浮点值，
*  @details  则需要在此函数中将下发字符串重新转回浮点值。
*  @param screen_id 画面ID
*  @param control_id 控件ID
*  @param str 文本控件内容
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
*  @brief  进度条控件通知 
*  @param screen_id 画面ID                                                      
*  @param control_id 控件ID                                                     
*  @param value 值                                                              
*/                                                                              
static void gui_notify_progress(uint16_t screen_id, uint16_t control_id, uint32_t value)           
{  
    //TODO: 添加用户代码
}                                                                                

/**                                                                              
*  @brief  滑动条控件通知                                                       
                
*  @param screen_id 画面ID                                                      
*  @param control_id 控件ID                                                     
*  @param value 值                                                              
*/                                                                              
static void gui_notify_slider(uint16_t screen_id, uint16_t control_id, uint32_t value)             
{                                                             
    //TODO: 添加用户代码
}

/** 
*  @brief  仪表控件通知

*  @param screen_id 画面ID
*  @param control_id 控件ID
*  @param value 值
*/
static void gui_notify_meter(uint16_t screen_id, uint16_t control_id, uint32_t value)
{
    //TODO: 添加用户代码
}

/** 
*  @brief  菜单控件通知
*  @details  当菜单项按下或松开时，执行此函数
*  @param screen_id 画面ID
*  @param control_id 控件ID
*  @param item 菜单项索引
*  @param state 按钮状态：0松开，1按下
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
*  @brief  选择控件通知
*  @details  当选择控件变化时，执行此函数
*  @param screen_id 画面ID
*  @param control_id 控件ID
*  @param item 当前选项
*/

static void gui_notify_selector(uint16_t screen_id, uint16_t control_id, uint8_t  item)
{
    
}

/** 
*  @brief  定时器超时通知处理
*  @param screen_id 画面ID
*  @param control_id 控件ID
*/
static void gui_notify_timer(uint16_t screen_id, uint16_t control_id)
{
    //TODO: 添加用户代码   
}

/** 
*  @brief  读取用户FLASH状态返回
*  @param status 0失败，1成功
*  @param _data 返回数据
*  @param length 数据长度
*/
static void gui_notify_readflash(uint8_t status,uint8_t *_data,uint16_t length)
{
    //TODO: 添加用户代码
}

/** 
*  @brief  写用户FLASH状态返回
*  @param status 0失败，1成功
*/
static void gui_notify_writeflash(uint8_t status)
{
    //TODO: 添加用户代码
}

/** 
*  @brief  读取RTC时间，注意返回的是BCD码
*  @param year 年（BCD）
*  @param month 月（BCD）
*  @param week 星期（BCD）
*  @param day 日（BCD）
*  @param hour 时（BCD）
*  @param minute 分（BCD）
*  @param second 秒（BCD）
*/
static void gui_notify_readrtc(uint8_t year,uint8_t month,uint8_t week,uint8_t day,uint8_t hour,uint8_t minute,uint8_t second)
{
    //TODO: 添加用户代码
}


/** 
*  @brief  更新数据
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
 * @brief    设备信息界面更新事件
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
        sprintf((char *)sprint_buf,"运行中");
        GUI_TEXT_SetText(TEXTVALUESCREENID,TEXT4_VALUCONTROLCID,sprint_buf);
        GUI_Icon_PlayFrame(TEXTVALUESCREENID,Frame1_VALUCONTROLCID,0);
        GUI_GIF_Stop(TEXTVALUESCREENID,GIF1_VALUCONTROLCID);
        GUI_GIF_Start(TEXTVALUESCREENID,GIF1_VALUCONTROLCID);
    }
    else 
    {
        sprintf((char *)sprint_buf,"未启动");
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

