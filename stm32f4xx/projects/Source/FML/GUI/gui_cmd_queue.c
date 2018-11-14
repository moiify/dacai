/**
 **************************************************************************************************
 * @file        gui_cmd_queue.c
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
#include "gui_cmd_queue.h"
#include "gui_base.h"
#include "crc.h"
/**
 * @addtogroup    XXX 
 * @{  
 */

/**
 * @addtogroup    gui_cmd_queue_Modules 
 * @{  
 */

/**
 * @defgroup      gui_cmd_queue_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_cmd_queue_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_cmd_queue_Constants_Defines 
 * @brief         
 * @{  
 */
#define CMD_HEAD 0XEE                                                  //帧头
#define CMD_TAIL 0XFFFCFFFF                                            //帧尾
#define QUEUE_MAX_SIZE              512
/**
 * @}
 */

/**
 * @defgroup      gui_cmd_queue_Private_Types
 * @brief         
 * @{  
 */
typedef struct                                            
{                                                                 
    uint16_t head;                                                       //队列头
    uint16_t tail;                                                       //队列尾
    uint8_t data[QUEUE_MAX_SIZE];                                       //队列数据缓存区
}gui_queue_t;                                                           
/**
 * @}
 */

/**
 * @defgroup      gui_cmd_queue_Private_Variables 
 * @brief         
 * @{  
 */
static gui_queue_t gui_queue= {0,0,0};                                   //指令队列
static uint32_t s_cmd_state = 0;                                           //队列帧尾检测状态
static uint16_t s_cmd_pos = 0;                                              //当前指令指针位置
/**
 * @}
 */

/**
 * @defgroup      gui_cmd_queue_Public_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      gui_cmd_queue_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */
static void gui_queue_pop(uint8_t* data);
static uint16_t gui_queue_get_size();

/**
 * @}
 */

/**
 * @defgroup      gui_cmd_queue_Functions 
 * @brief         
 * @{  
 */
/*! 
*  \brief  清空指令数据
*/
void GUI_Queue_Reset()
{
    gui_queue.head = gui_queue.tail = 0;
    s_cmd_pos =s_cmd_state = 0;
}
/*! 
* \brief  添加指令数据
* \detial 串口接收的数据，通过此函数放入指令队列 
*  \param  _data 指令数据
*/
void GUI_Queue_Push(uint8_t data)
{
    uint16_t pos = (gui_queue.head+1)%QUEUE_MAX_SIZE;
    if(pos!=gui_queue.tail)                                                //非满状态
    {
        gui_queue.data[gui_queue.head] = data;
        gui_queue.head = pos;
    }
}

//从队列中取一个数据
static void gui_queue_pop(uint8_t* data)
{
    if(gui_queue.tail!=gui_queue.head)                                          //非空状态
    {
        *data = gui_queue.data[gui_queue.tail];
        gui_queue.tail = (gui_queue.tail+1)%QUEUE_MAX_SIZE;
    }
}

//获取队列中有效数据个数
static uint16_t gui_queue_get_size()
{
    return ((gui_queue.head+QUEUE_MAX_SIZE-gui_queue.tail)%QUEUE_MAX_SIZE);
}
/*! 
*  \brief  从指令队列中取出一条完整的指令
*  \param  cmd 指令接收缓存区
*  \param  buf_len 指令接收缓存区大小
*  \return  指令长度，0表示队列中无完整指令
*/
uint16_t GUI_Queue_Find_Cmd(uint8_t *buffer,uint16_t buf_len)
{
    uint16_t cmd_size = 0;
    uint8_t data = 0;

    while(gui_queue_get_size()>0)
    {
        //取一个数据
        gui_queue_pop(&data);

        if(s_cmd_pos==0&&data!=CMD_HEAD)                               //指令第一个字节必须是帧头，否则跳过adfasdfas
        {
            continue;
        }
        if(s_cmd_pos<buf_len)                                           //防止缓冲区溢出
            buffer[s_cmd_pos++] = data;

        s_cmd_state = ((s_cmd_state<<8)|data);                           //拼接最后4个字节，组成一个32位整数

        //最后4个字节与帧尾匹配，得到完整帧
        if(s_cmd_state==CMD_TAIL)
        {
            cmd_size = s_cmd_pos;                                       //指令字节长度
            s_cmd_state = 0;                                            //重新检测帧尾巴
            s_cmd_pos = 0;                                              //复位指令指针

#if(CRC16_ENABLE)
            //去掉指令头尾EE，尾FFFCFFFF共计5个字节，只计算数据部分CRC
            if(!CRC16_Modbus(buffer+1,s_cmd_size-5))                      //CRC校验
                return 0;

            cmd_size -= 2;                                            //去掉CRC16（2字节）
#endif
            return cmd_size;
        }
    }
    return 0;                                                         //没有形成完整的一帧
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

