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
 * @brief    �����ַ���ָ��
 * @param    str:uint8_t* �ַ��������׵�ַ
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
 * @brief    ����һ���ֽ�
 * @param    value:uint8_t һ���ֽ�����
 */

void BSP_LCD_SendUint8(uint8_t value)
{
    BSP_LCD_WriteByte(value);
}

/**
 * @brief    һ���Է��������ֽڵ�����
 * @param    value:uint16_t �����ֽ�����
 */

void BSP_LCD_SendUint16(uint16_t value)
{
    BSP_LCD_WriteByte(value>>8);
    BSP_LCD_WriteByte(value&0xff);
}

/**
 * @brief    һ���Է����ĸ��ֽ�����
 * @param    value:uint32_t �ĸ��ֽ�����
 */

void BSP_LCD_SendUint32(uint32_t value)
{
    BSP_LCD_SendUint16(value>>16);
    BSP_LCD_SendUint16(value&0xffff);
}

/**
 * @brief    ����һ��short�͵Ĳ���������
 * @param    pData:uint16_t* ����
 * @param    count:uint16_t ����
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
 * @brief    ����һ��char�͵Ĳ���������
 * @param    pData:uint8_t* �����׵�ַ
 * @param    count:uint16_t ����
 */

void BSP_LCD_SendUint8N(uint8_t *pData,uint16_t count)
{
    uint16_t i=0;
    for (i=0;i<count;++i)
    {
        BSP_LCD_SendUint8(pData[i]);
    }
}

#if(CRC16_ENABLE) //����꿪����CRC16У��

#else
/**
 * @brief    ��������֡ͷ
 */

void GUI_SendHeadCMD()
{   
    BSP_LCD_WriteByte(0XEE);
}

/**
 * @brief    ��������֡β
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

