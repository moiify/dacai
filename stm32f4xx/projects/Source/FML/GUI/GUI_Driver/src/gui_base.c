/**
 **************************************************************************************************
 * @file        gui_base.c
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
/**
 * @addtogroup    XXX 
 * @{  
 */

/**
 * @addtogroup    gui_base_Modules 
 * @{  
 */

/**
 * @defgroup      gui_base_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_base_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_base_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_base_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_base_Private_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_base_Public_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_base_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_base_Functions 
 * @brief         
 * @{ 
 */

/**
 * @brief    发送字符串指令
 * @param    str:uint8_t* 字符串数组首地址
 */

void BSP_LCD_SendStrings(uint8_t *str)
{
    while(*str)
    {
        BSP_LCD_WriteByte(*str);
        str++;
    }
}

/**
 * @brief    发送一个字节
 * @param    value:uint8_t 一个字节数据
 */

void BSP_LCD_SendUint8(uint8_t value)
{
    BSP_LCD_WriteByte(value);
}

/**
 * @brief    一次性发送两个字节的数据
 * @param    value:uint16_t 两个字节数据
 */

void BSP_LCD_SendUint16(uint16_t value)
{
    BSP_LCD_WriteByte(value>>8);
    BSP_LCD_WriteByte(value&0xff);
}

/**
 * @brief    一次性发送四个字节数据
 * @param    value:uint32_t 四个字节数据
 */

void BSP_LCD_SendUint32(uint32_t value)
{
    BSP_LCD_SendUint16(value>>16);
    BSP_LCD_SendUint16(value&0xffff);
}

/**
 * @brief    发送一个short型的不定长数组
 * @param    pData:uint16_t* 数组
 * @param    count:uint16_t 长度
 */

void BSP_LCD_SendUint16N(uint16_t *pData,uint16_t count)
{
    uint16_t i=0;
    for (i=0;i<count;++i)
    {
        BSP_LCD_SendUint16(pData[i]);
    }
}

/**
 * @brief    发送一个char型的不定长数组
 * @param    pData:uint8_t* 数组首地址
 * @param    count:uint16_t 长度
 */

void BSP_LCD_SendUint8N(uint8_t *pData,uint16_t count)
{
    uint16_t i=0;
    for (i=0;i<count;++i)
    {
        BSP_LCD_SendUint8(pData[i]);
    }
}

#if(CRC16_ENABLE) //如果宏开启了CRC16校验

#else
/**
 * @brief    发送命令帧头
 */

void GUI_SendHeadCMD()
{   
    BSP_LCD_WriteByte(0XEE);
}

/**
 * @brief    发送命令帧尾
 */

void GUI_SendEndCMD()
{   
    uint8_t buf[]={0xff,0xfc,0xff,0xff};
    BSP_LCD_WriteBytes(buf,4);
}

#endif

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

