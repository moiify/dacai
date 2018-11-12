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
    uint8_t buf[]={0xff,0xcf,0xff,0xff};
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
/* 发送握手命令*/
void GUI_HandShake()
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x04);
    gui_SendEndCMD();
}

/* 设置背光  levle 0-255*/
void GUI_SetBackLight(uint8_t light_level)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x60);
    BSP_LCD_WriteByte(light_level);
    gui_SendEndCMD();      
}
/*蜂鸣器设置   time 持续时间(毫秒单位)*/
void GUI_SetBuzzer(uint8_t time)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x61);
    BSP_LCD_WriteByte(time);
    gui_SendEndCMD();    
}
/*! 
*  \brief  设置前景色
*  \param  color 前景色
*/
void GUI_SetFtColor(uint16_t color)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x41);
    BSP_LCD_SendUint16(color);
    gui_SendEndCMD();
}
/*! 
*  \brief  设置背景色
*  \param  color 背景色
*/
void GUI_SetBkColor(uint16_t color)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x42);
    BSP_LCD_SendUint16(color);
    gui_SendEndCMD();
}
/*! 
*  \brief  清除画面
*/
void GUI_CleanScreen()
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x01);
    gui_SendEndCMD();
}

/*! 
*  \brief      显示全屏图片
*  \param  image_id 图片索引
*  \param  masken 是否启用透明掩码
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
*  \brief      指定位置显示图片
*  \param  x 位置X坐标
*  \param  y 位置Y坐标
*  \param  image_id 图片索引
*  \param  masken 是否启用透明掩码
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
*  \brief      显示裁剪图片
*  \param  x 位置X坐标
*  \param  y 位置Y坐标
*  \param  image_id 图片索引
*  \param  image_x 图片裁剪位置X坐标
*  \param  image_y 图片裁剪位置Y坐标
*  \param  image_l 图片裁剪长度
*  \param  image_w 图片裁剪高度
*  \param  masken 是否启用透明掩码
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
*  \brief      显示GIF动画
*  \param  x 位置X坐标
*  \param  y 位置Y坐标
*  \param  flashimage_id 图片索引
*  \param  enable 是否显示
*  \param  playnum 播放次数
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
*  \brief      画点
*  \param  x 位置X坐标
*  \param  y 位置Y坐标
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
*  \brief      画线
*  \param  x0 起始位置X坐标
*  \param  y0 起始位置Y坐标
*  \param  x1 结束位置X坐标
*  \param  y1 结束位置Y坐标
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
*  \brief      获取当前画面
*/
void GUI_GetScreen(uint16_t screen_id)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x01);
    gui_SendEndCMD();
}
/*! 
*  \brief      设置当前画面
*  \param  screen_id 画面ID
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
*  \brief     禁用\启用画面更新
*  \details 禁用\启用一般成对使用，用于避免闪烁、提高刷新速度
*  \details 用法：
*	\details SetScreenUpdateEnable(0);//禁止更新
*	\details 一系列更新画面的指令
*	\details SetScreenUpdateEnable(1);//立即更新
*  \param  enable 0禁用，1启用
*/
void GUI_SetUpdateEnable(uint8_t enable)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB3);
    BSP_LCD_WriteByte(enable);
    gui_SendEndCMD();
}
/*! 
*  \brief     设置控件输入焦点
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  focus 是否具有输入焦点
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
*  \brief     显示\隐藏控件
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  visible 是否显示
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
*  \brief     设置触摸控件使能
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  enable 控件是否使能
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
*  \brief     设置按钮状态
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  value 按钮状态
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
*  \brief     设置文本值
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  str 文本值
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
*  \brief     设置文本为整数值，要求FIRMWARE_VER>=908
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  value 文本数值
*  \param  sign 0-无符号，1-有符号
*  \param  fill_zero 数字位数，不足时左侧补零
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
*  \brief     设置文本单精度浮点值，要求FIRMWARE_VER>=908
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  value 文本数值
*  \param  precision 小数位数
*  \param  show_zeros 为1时，显示末尾0
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
*  \brief      开始播放动画
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
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
*  \brief      停止播放动画
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
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
*  \brief      暂停播放动画
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
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
*  \brief     播放制定帧
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  frame_id 帧ID
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
*  \brief     播放上一帧
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
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
*  \brief     播放下一帧
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
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
*  \brief     曲线控件-添加通道
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  channel 通道号
*  \param  color 颜色
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
*  \brief     曲线控件-删除通道
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  channel 通道号
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
*  \brief     曲线控件-添加数据
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  channel 通道号
*  \param  pData 曲线数据
*  \param  nDataLen 数据个数
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
*  \brief     曲线控件-清除数据
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  channel 通道号 
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
*  \brief     曲线控件-设置视图窗口
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  x_offset 水平偏移
*  \param  x_mul 水平缩放系数
*  \param  y_offset 垂直偏移
*  \param  y_mul 垂直缩放系数
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
*  \brief     开始批量更新
*  \param  screen_id 画面ID
*/
void GUI_BatchBegin(uint16_t screen_id)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xB1);
    BSP_LCD_WriteByte(0x12);
    BSP_LCD_SendUint16(screen_id);
}
/*! 
*  \brief     批量更新按钮控件
*  \param  control_id 控件ID
*  \param  value 数值
*/
void GUI_BatchSetButtonValue(uint16_t control_id,uint8_t state)
{
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16(1);
    BSP_LCD_WriteByte(state);
}
/*! 
*  \brief     批量更新进度条控件
*  \param  control_id 控件ID
*  \param  value 数值
*/
void GUI_BatchSetProgressValue(uint16_t control_id,uint32_t value)
{
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16(4);
    BSP_LCD_SendUint32(value);
}

/*! 
*  \brief     批量更新滑动条控件
*  \param  control_id 控件ID
*  \param  value 数值
*/
void GUI_BatchSetSliderValue(uint16_t control_id,uint32_t value)
{
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16(4);
    BSP_LCD_SendUint32(value);
}
/*! 
*  \brief     批量更新仪表控件
*  \param  control_id 控件ID
*  \param  value 数值
*/
void GUI_BatchSetMeterValue(uint16_t control_id,uint32_t value)
{
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16(4);
    BSP_LCD_SendUint32(value);
}
/*! 
*  \brief      计算字符串长度
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
*  \brief     批量更新文本控件
*  \param  control_id 控件ID
*  \param  strings 字符串
*/
void GUI_BatchSetText(uint16_t control_id,uint8_t *strings)
{
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16(GetStringLen(strings));
    BSP_LCD_SendStrings(strings);
}
/*! 
*  \brief     批量更新动画\图标控件
*  \param  control_id 控件ID
*  \param  frame_id 帧ID
*/
void GUI_BatchSetFrame(uint16_t control_id,uint16_t frame_id)
{
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_SendUint16(2);
    BSP_LCD_SendUint16(frame_id);
}

#if FIRMWARE_VER>=908

/*! 
*  \brief     批量设置控件可见
*  \param  control_id 控件ID
*  \param  visible 帧ID
*/
void GUI_BatchSetVisible(uint16_t control_id,uint8_t visible)
{
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_WriteByte(1);
    BSP_LCD_WriteByte(visible);
}
/*! 
*  \brief     批量设置控件使能
*  \param  control_id 控件ID
*  \param  enable 帧ID
*/
void GUI_BatchSetEnable(uint16_t control_id,uint8_t enable)
{
    BSP_LCD_SendUint16(control_id);
    BSP_LCD_WriteByte(2);
    BSP_LCD_WriteByte(enable);
}

#endif
/*! 
*  \brief    结束批量更新
*/
void GUI_BatchEnd()
{
    gui_SendEndCMD();
}
/*! 
*  \brief     设置倒计时控件
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  timeout 倒计时(秒)
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
*  \brief     开启倒计时控件
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
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
*  \brief     停止倒计时控件
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
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
*  \brief     暂停倒计时控件
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
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
*  \brief     设置控件背景色
*  \details  支持控件：进度条、文本
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  color 背景色
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
*  \brief     设置控件前景色
* \details  支持控件：进度条
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  color 前景色
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
*  \brief     显示\隐藏弹出菜单控件
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  show 是否显示，为0时focus_control_id无效
*  \param  focus_control_id 关联的文本控件(菜单控件的内容输出到文本控件)
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
*  \brief     显示\隐藏系统键盘
*  \param  show 0隐藏，1显示
*  \param  x 键盘显示位置X坐标
*  \param  y 键盘显示位置Y坐标
*  \param  type 0小键盘，1全键盘
*  \param  option 0正常字符，1密码，2时间设置
*  \param  max_len 键盘录入字符长度限制
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
*  \brief     多语言设置
*  \param  ui_lang 用户界面语言0~9
*  \param  sys_lang 系统键盘语言-0中文，1英文
*/
void GUI_SetLanguage(uint8_t ui_lang,uint8_t sys_lang)
{
    uint8_t lang = ui_lang;
    if(sys_lang)    lang |= 0x80;

    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xC1);
    BSP_LCD_WriteByte(lang);
    BSP_LCD_WriteByte(0xC1+lang);//校验，防止意外修改语言
    gui_SendEndCMD();
}
#endif


#if FIRMWARE_VER>=921
/*! 
*  \brief     开始保存控件数值到FLASH
*  \param  version 数据版本号，可任意指定，高16位为主版本号，低16位为次版本号
*  \param  address 数据在用户存储区的存放地址，注意防止地址重叠、冲突
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
*  \brief     保存某个控件的数值到FLASH
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*/
void GUI_FlashSaveControl(uint16_t screen_id,uint16_t control_id)
{
    BSP_LCD_SendUint16(screen_id);
    BSP_LCD_SendUint16(control_id);
}
/*! 
*  \brief     保存某个控件的数值到FLASH
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*/
void GUI_FlashEndSaveControl()
{
    gui_SendEndCMD();
}
/*! 
*  \brief     从FLASH中恢复控件数据
*  \param  version 数据版本号，主版本号必须与存储时一致，否则会加载失败
*  \param  address 数据在用户存储区的存放地址
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
*  \brief     设置历史曲线采样数据值(单字节，uint8_t或int8)
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  value 采样点数据
*  \param  channel 通道数
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
*  \brief     设置历史曲线采样数据值(双字节，uint16_t或int16)
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  value 采样点数据
*  \param  channel 通道数
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
*  \brief     设置历史曲线采样数据值(四字节，uint32_t或int32)
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  value 采样点数据
*  \param  channel 通道数
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
*  \brief     设置历史曲线采样数据值(单精度浮点数)
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  value 采样点数据
*  \param  channel 通道数
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
*  \brief     允许或禁止历史曲线采样
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  enable 0-禁止，1-允许
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
*  \brief     显示或隐藏历史曲线通道
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  channel 通道编号
*  \param  show 0-隐藏，1-显示
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
*  \brief     设置历史曲线时间长度(即采样点数)
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  sample_count 一屏显示的采样点数
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
*  \brief     历史曲线缩放到全屏
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
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
*  \brief     设置历史曲线缩放比例系数
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  zoom 缩放百分比(zoom>100%时水平方向缩小，反正放大)
*  \param  max_zoom 缩放限制，一屏最多显示采样点数
*  \param  min_zoom 缩放限制，一屏最少显示采样点数
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
*  \brief     检测SD卡是否插入
*/
void GUI_SD_IsInsert(void)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x36);
    BSP_LCD_WriteByte(0x01);
    gui_SendEndCMD();
}
/*! 
*  \brief     打开或创建文件
*  \param  filename 文件名称(仅ASCII编码)
*  \param  mode 模式，可选组合模式如上FA_XXXX
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
*  \brief     以当前时间创建文件，例如:20161015083000.txt
*  \param  ext 文件后缀，例如 txt
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
*  \brief     在当前文件末尾写入数据
*  \param  buffer 数据
*  \param  dlc 数据长度
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
*  \brief     读取当前文件
*  \param  offset 文件位置偏移
*  \param  dlc 数据长度
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
*  \brief     获取当前文件长度
*/
void GUI_SD_GetFileSize()
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x36);
    BSP_LCD_WriteByte(0x06);
    gui_SendEndCMD();
}
/*! 
*  \brief     关闭当前文件
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
*  \brief     记录控件-触发警告
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  value 告警值
*  \param  time 告警产生的时间，为0时使用屏幕内部时间
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
*  \brief     记录控件-解除警告
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  value 告警值
*  \param  time 告警解除的时间，为0时使用屏幕内部时间
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
*  \brief    记录控件- 添加常规记录
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  record 一条记录(字符串)，子项通过分号隔开，例如：第一项;第二项;第三项;
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
*  \brief     记录控件-清除记录数据
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
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
*  \brief     记录控件-设置记录显示偏移
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  offset 显示偏移，滚动条位置
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
*  \brief     记录控件-获取当前记录数目
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
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
*  \brief     读取屏幕RTC时间
*/
void GUI_ReadRTC(void)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x82);
    gui_SendEndCMD();
}

/*! 
*  \brief   播放音乐
*  \param   buffer 十六进制的音乐路径及名字
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
*  \brief 获取
*  \param  color 背景色
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
*  \brief  设置文字间隔
*  \param  x_w 横向间隔
*  \param  y_w 纵向间隔
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
*  \brief  设置文字显示限制
*  \param  enable 是否启用限制
*  \param  width 宽度
*  \param  height 高度
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
*  \brief  设置过滤色
*  \param  fillcolor_dwon 颜色下界
*  \param  fillcolor_up 颜色上界
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
*  \brief  设置过滤色
*  \param  x 位置X坐标
*  \param  y 位置Y坐标
*  \param  back 颜色上界
*  \param  font 字体
*  \param  strings 字符串内容
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
*  \brief    显示光标
*  \param  enable 是否显示
*  \param  x 位置X坐标
*  \param  y 位置Y坐标
*  \param  width 宽度
*  \param  height 高度
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
*  \brief   x坐标等距使用前景色连线
*  \param  x 横坐标
*  \param  x_space 距离
*  \param  dot_y  一组纵轴坐标
*  \param  dot_cnt  纵坐标个数
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
*  \brief   按照坐标偏移量用前景色连线
*  \param  x 横坐标
*  \param  y 纵距离
*  \param  dot_offset  偏移量
*  \param  dot_cnt  偏移量个数
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
*  \brief   按照坐标偏移量用背景色连线
*  \param  x 横坐标
*  \param  y 纵距离
*  \param  dot_offset  偏移量
*  \param  dot_cnt  偏移量个数
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
*  \brief  自动调节背光亮度
*  \param  enable 使能
*  \param  bl_off_level 待机亮度
*  \param  bl_on_level  激活亮度
*  \param  bl_on_time  偏移量个数
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
*  \brief  将制定的多个坐标点用前景色连接起来
*  \param  dot  坐标点
*  \param  dot_cnt  偏移量个数
*/
void GUI_GUI_FcolorConDots(uint16_t *dot,uint16_t dot_cnt)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x68);
    BSP_LCD_SendUint16N(dot,dot_cnt*2);
    gui_SendEndCMD();
}
/*! 
*  \brief  将制定的多个坐标点用背景色连接起来
*  \param  dot  坐标点
*  \param  dot_cnt  偏移量个数
*/
void GUI_GUI_BcolorConDots(uint16_t *dot,uint16_t dot_cnt)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x69);
    BSP_LCD_SendUint16N(dot,dot_cnt*2);
    gui_SendEndCMD();
}
/*! 
*  \brief     画空心圆
*  \param  x0 圆心位置X坐标
*  \param  y0 圆心位置Y坐标
*  \param  r 半径
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
*  \brief      画实心圆
*  \param  x0 圆心位置X坐标
*  \param  y0 圆心位置Y坐标
*  \param  r 半径
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
*  \brief      画弧线
*  \param  x0 圆心位置X坐标
*  \param  y0 圆心位置Y坐标
*  \param  r 半径
*  \param  sa 起始角度
*  \param  ea 终止角度
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
*  \brief      画空心矩形
*  \param  x0 起始位置X坐标
*  \param  y0 起始位置Y坐标
*  \param  x1 结束位置X坐标
*  \param  y1 结束位置Y坐标
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
*  \brief      画实心矩形
*  \param  x0 起始位置X坐标
*  \param  y0 起始位置Y坐标
*  \param  x1 结束位置X坐标
*  \param  y1 结束位置Y坐标
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
*  \brief      画空心椭圆
*  \param  x0 起始位置X坐标
*  \param  y0 起始位置Y坐标
*  \param  x1 结束位置X坐标
*  \param  y1 结束位置Y坐标
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
*  \brief      画实心椭圆
*  \param  x0 起始位置X坐标
*  \param  y0 起始位置Y坐标
*  \param  x1 结束位置X坐标
*  \param  y1 结束位置Y坐标
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

    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x70);
    BSP_LCD_WriteByte(options);
    gui_SendEndCMD();
}
/*! 
*  \brief   校准触摸屏
*/
void GUI_CalibrateTouchPane()
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x72);
    gui_SendEndCMD();
}
/*! 
*  \brief  触摸屏测试
*/
void GUI_TestTouchPane()
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0x73);
    gui_SendEndCMD();
}

/*! 
*  \brief  锁定设备配置，锁定之后需要解锁，才能修改波特率、触摸屏、蜂鸣器工作方式
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
*  \brief  解锁设备配置
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
*  \brief    修改串口屏的波特率
*  \details  波特率选项范围[0~14]，对应实际波特率
{1200,2400,4800,9600,19200,38400,57600,115200,1000000,2000000,218750,437500,875000,921800,2500000}
*  \param  option 波特率选项
*/
void GUI_SetCommBps(uint8_t option)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xA0);
    BSP_LCD_WriteByte(option);
    gui_SendEndCMD();
}
/*! 
*  \brief      设置当前写入图层
*  \details  一般用于实现双缓存效果(绘图时避免闪烁)：
*  \details  uint8_t layer = 0;
*  \details  WriteLayer(layer);   设置写入层
*  \details  ClearLayer(layer);   使图层变透明
*  \details  添加一系列绘图指令
*  \details  DisText(100,100,0,4,"hello hmi!!!");
*  \details  DisplyLayer(layer);  切换显示层
*  \details  layer = (layer+1)%2; 双缓存切换
*  \see DisplyLayer
*  \see ClearLayer
*  \param  layer 图层编号
*/
void GUI_WriteLayer(uint8_t layer)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xA1);
    BSP_LCD_WriteByte(layer);
    gui_SendEndCMD();
}
/*! 
*  \brief      设置当前显示图层
*  \param  layer 图层编号
*/
void GUI_DisplyLayer(uint8_t layer)
{
    gui_SendHeadCMD();
    BSP_LCD_WriteByte(0xA2);
    BSP_LCD_WriteByte(layer);
    gui_SendEndCMD();
}
/*! 
*  \brief      拷贝图层
*  \param  src_layer 原始图层
*  \param  dest_layer 目标图层
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
*  \brief      清除图层，使图层变成透明
*  \param  layer 图层编号
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
*  \brief  写数据到串口屏用户存储区
*  \param  startAddress 起始地址
*  \param  length 字节数
*  \param  _data 待写入的数据
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
*  \brief  从串口屏用户存储区读取数据
*  \param  startAddress 起始地址
*  \param  length 字节数
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
*  \brief      设置进度值
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  value 数值
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
*  \brief     设置仪表值
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  value 数值
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
*  \brief     设置仪表值
*  \param  screen_id 画面ID
*  \param  control_id 图片控件ID
*  \param  value 数值
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
*  \brief      设置滑动条
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  value 数值
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
*  \brief      设置选择控件
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
*  \param  item 当前选项
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
*  \brief     获取控件值
*  \param  screen_id 画面ID
*  \param  control_id 控件ID
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
