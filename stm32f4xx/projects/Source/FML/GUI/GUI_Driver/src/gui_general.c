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
#include "gui_conf.h"
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
/* 发送握手命令*/
void GUI_HandShake()
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x04);
    GUI_SendEndCMD();
}

/* 设置背光  levle 0-255*/
void GUI_SetBackLight(uint8_t light_level)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x60);
    BSP_LCD_WriteByte(light_level);
    GUI_SendEndCMD();      
}
/*蜂鸣器设置   time 持续时间(毫秒单位)*/
void GUI_SetBuzzer(uint8_t time)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x61);
    BSP_LCD_WriteByte(time);
    GUI_SendEndCMD();    
}
/*! 
*  \brief  设置前景色
*  \param  color 前景色
*/
void GUI_SetFtColor(uint16_t color)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x41);
    BSP_LCD_SendUint16(color);
    GUI_SendEndCMD();
}
/*! 
*  \brief  设置背景色
*  \param  color 背景色
*/
void GUI_SetBkColor(uint16_t color)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x42);
    BSP_LCD_SendUint16(color);
    GUI_SendEndCMD();
}
/*! 
*  \brief 获取颜色
*  \param  color 背景色
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
*  \brief  清除画面
*/
void GUI_CleanScreen()
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x01);
    GUI_SendEndCMD();
}
/*! 
*  \brief      获取当前画面
*/
void GUI_GetScreen(uint16_t screen_id)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x01);
    GUI_SendEndCMD();
}
/*! 
*  \brief      设置当前画面
*  \param  screen_id 画面ID
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
*  \brief     禁用\启用画面更新
*  \details 禁用\启用一般成对使用，用于避免闪烁、提高刷新速度
*  \details 用法：
*   \details SetScreenUpdateEnable(0);//禁止更新
*   \details 一系列更新画面的指令
*   \details SetScreenUpdateEnable(1);//立即更新
*  \param  enable 0禁用，1启用
*/
void GUI_SetUpdateEnable(uint8_t enable)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xB3);
    BSP_LCD_WriteByte(enable);
    GUI_SendEndCMD();
}
/*! 
*  \brief    显示光标
*  \param  enable 是否显示
*  \param  x 位置X坐标
*  \param  y 位置Y坐标
*  \param  width 宽度
*  \param  height 高度
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
*  \brief   触摸屏设置
*  \param enable 触摸使能
*  \param beep_on 触摸蜂鸣器
*  \param work_mode 触摸工作模式：0按下就上传，1松开才上传，2不断上传坐标值，3按下和松开均上传数据
*  \param press_calibration 连续点击触摸屏20下校准触摸屏：0禁用，1启用
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
*  \brief   校准触摸屏
*/
void GUI_CalibrateTouchPane()
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x72);
    GUI_SendEndCMD();
}
/*! 
*  \brief  触摸屏测试
*/
void GUI_TestTouchPane()
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0x73);
    GUI_SendEndCMD();
}

/*! 
*  \brief  锁定设备配置，锁定之后需要解锁，才能修改波特率、触摸屏、蜂鸣器工作方式
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
*  \brief  解锁设备配置
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
*  \brief    修改串口屏的波特率
*  \details  波特率选项范围[0~14]，对应实际波特率
{1200,2400,4800,9600,19200,38400,57600,115200,1000000,2000000,218750,437500,875000,921800,2500000}
*  \param  option 波特率选项
*/
void GUI_SetCommBps(uint8_t option)
{
    GUI_SendHeadCMD();
    BSP_LCD_WriteByte(0xA0);
    BSP_LCD_WriteByte(option);
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

