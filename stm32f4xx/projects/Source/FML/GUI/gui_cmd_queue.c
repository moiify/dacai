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
#define CMD_HEAD 0XEE                                                  //֡ͷ
#define CMD_TAIL 0XFFFCFFFF                                            //֡β
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
    uint16_t head;                                                       //����ͷ
    uint16_t tail;                                                       //����β
    uint8_t data[QUEUE_MAX_SIZE];                                       //�������ݻ�����
}gui_queue_t;                                                           
/**
 * @}
 */

/**
 * @defgroup      gui_cmd_queue_Private_Variables 
 * @brief         
 * @{  
 */
static gui_queue_t gui_queue= {0,0,0};                                   //ָ�����
static uint32_t s_cmd_state = 0;                                           //����֡β���״̬
static uint16_t s_cmd_pos = 0;                                              //��ǰָ��ָ��λ��
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
*  \brief  ���ָ������
*/
void GUI_Queue_Reset()
{
    gui_queue.head = gui_queue.tail = 0;
    s_cmd_pos =s_cmd_state = 0;
}
/*! 
* \brief  ���ָ������
* \detial ���ڽ��յ����ݣ�ͨ���˺�������ָ����� 
*  \param  _data ָ������
*/
void GUI_Queue_Push(uint8_t data)
{
    uint16_t pos = (gui_queue.head+1)%QUEUE_MAX_SIZE;
    if(pos!=gui_queue.tail)                                                //����״̬
    {
        gui_queue.data[gui_queue.head] = data;
        gui_queue.head = pos;
    }
}

//�Ӷ�����ȡһ������
static void gui_queue_pop(uint8_t* data)
{
    if(gui_queue.tail!=gui_queue.head)                                          //�ǿ�״̬
    {
        *data = gui_queue.data[gui_queue.tail];
        gui_queue.tail = (gui_queue.tail+1)%QUEUE_MAX_SIZE;
    }
}

//��ȡ��������Ч���ݸ���
static uint16_t gui_queue_get_size()
{
    return ((gui_queue.head+QUEUE_MAX_SIZE-gui_queue.tail)%QUEUE_MAX_SIZE);
}
/*! 
*  \brief  ��ָ�������ȡ��һ��������ָ��
*  \param  cmd ָ����ջ�����
*  \param  buf_len ָ����ջ�������С
*  \return  ָ��ȣ�0��ʾ������������ָ��
*/
uint16_t GUI_Queue_Find_Cmd(uint8_t *buffer,uint16_t buf_len)
{
    uint16_t cmd_size = 0;
    uint8_t data = 0;

    while(gui_queue_get_size()>0)
    {
        //ȡһ������
        gui_queue_pop(&data);

        if(s_cmd_pos==0&&data!=CMD_HEAD)                               //ָ���һ���ֽڱ�����֡ͷ����������adfasdfas
        {
            continue;
        }
        if(s_cmd_pos<buf_len)                                           //��ֹ���������
            buffer[s_cmd_pos++] = data;

        s_cmd_state = ((s_cmd_state<<8)|data);                           //ƴ�����4���ֽڣ����һ��32λ����

        //���4���ֽ���֡βƥ�䣬�õ�����֡
        if(s_cmd_state==CMD_TAIL)
        {
            cmd_size = s_cmd_pos;                                       //ָ���ֽڳ���
            s_cmd_state = 0;                                            //���¼��֡β��
            s_cmd_pos = 0;                                              //��λָ��ָ��

#if(CRC16_ENABLE)
            //ȥ��ָ��ͷβEE��βFFFCFFFF����5���ֽڣ�ֻ�������ݲ���CRC
            if(!CRC16_Modbus(buffer+1,s_cmd_size-5))                      //CRCУ��
                return 0;

            cmd_size -= 2;                                            //ȥ��CRC16��2�ֽڣ�
#endif
            return cmd_size;
        }
    }
    return 0;                                                         //û���γ�������һ֡
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

