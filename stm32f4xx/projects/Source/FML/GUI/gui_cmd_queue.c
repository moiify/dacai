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
#include "stm32_bsp_conf.h"
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
#define DACAI_CMD_HEAD 0XEE                                                  //֡ͷ
#define DACAI_CMD_END 0XFFFCFFFF                                             //֡β
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
	uint8_t readbuf[BSP_USART1_RXBUF_SIZE];
	uint16_t index;
}cmd_decode_cache_t;
typedef struct
{
	uint8_t buf[GUI_CMD_LEN_MAX];
    uint16_t len;
}cmd_chache_t;
typedef struct
{
	cmd_chache_t Buf[5];
	uint8_t In;
	uint8_t Out;
	uint8_t Count;
	uint8_t Size;
}cmd_queue_cache_t;
/**
 * @}
 */

/**
 * @defgroup      gui_cmd_queue_Private_Variables 
 * @brief         
 * @{  
 */
static cmd_decode_cache_t s_cmd_cache =
{
	.index = 0,
	.readbuf = { 0 },
};
static cmd_queue_cache_t s_cmd_queue =
{
	.Count = 0,
	.In = 0,
	.Out = 0,
	.Size = sizeof(s_cmd_queue.Buf) / sizeof(s_cmd_queue.Buf[0]),
};
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
static uint16_t gui_cmd_queue_decode();
/**
 * @}
 */

/**
 * @defgroup      gui_cmd_queue_Functions 
 * @brief         
 * @{  
 */
/**
 * @brief    �Ӵ��ڻ���������ݣ���������Ϣ����
 */

void Gui_CMD_Queue_Push()
{
	uint16_t readcount = 0;
	uint16_t idlecount = 0;
	idlecount = sizeof(s_cmd_cache.readbuf) - s_cmd_cache.index;
	if (idlecount > 0)
	{
		readcount = BSP_USART_ReadBytes(BSP_USART1, &s_cmd_cache.readbuf[s_cmd_cache.index], idlecount);
		if (readcount > 0)
		{
			s_cmd_cache.index += readcount;
			s_cmd_cache.index -= gui_cmd_queue_decode();
		}
	}
}

/**
 * @brief    �Ӷ�����ȡһ����Ϣ
 * @param    dst:uint8_t* Ŀ�ĵ�����
 * @retval   uint8_t: 0����Ϣ  1ȡ�ɹ�
 */

uint8_t Gui_CMD_Queue_Pop(uint8_t *dst)
{	
	uint16_t queue_len;
    if(s_cmd_queue.Count>0)
    {   
        memcpy(dst,s_cmd_queue.Buf[s_cmd_queue.Out].buf,s_cmd_queue.Buf[s_cmd_queue.Out].len);
        memset(s_cmd_queue.Buf[s_cmd_queue.Out].buf,0,s_cmd_queue.Buf[s_cmd_queue.Out].len); //������ڴ���գ���Ȼ��һ�ζ�������Ӱ��
		queue_len = s_cmd_queue.Buf[s_cmd_queue.Out].len;
        s_cmd_queue.Out++;
        s_cmd_queue.Out %= s_cmd_queue.Size;
        s_cmd_queue.Count--;
        return queue_len ;
    }
    else 
    {
        return 0;
    }
}
/**
 * @brief    ���������е�Э���
 * @retval   uint16_t: ������ֽ���
 */

static uint16_t gui_cmd_queue_decode()
{
	uint16_t offset = 0;
	uint16_t cmd_head_index=0;
	uint16_t decode_count = 0;
	uint16_t remain_count = s_cmd_cache.index;
	uint8_t *pBuf = s_cmd_cache.readbuf;
	uint32_t check_end=0;

	while (remain_count > sizeof(DACAI_CMD_HEAD) + sizeof(DACAI_CMD_END)&&s_cmd_queue.Count<s_cmd_queue.Size)
	{
		if (pBuf[offset]== DACAI_CMD_HEAD)
		{	
			cmd_head_index=offset;
			while (remain_count>sizeof(DACAI_CMD_END))
			{	
				check_end=(uint32_t)pBuf[offset+1]<<24|(uint32_t)pBuf[offset+2]<<16|(uint32_t)pBuf[offset+3]<<8|(uint32_t)pBuf[offset+4];
				if (check_end == DACAI_CMD_END)  //�յ�һ��ָ��
				{   
                    s_cmd_queue.Buf[s_cmd_queue.In].len=(offset-cmd_head_index+5);
					memcpy(s_cmd_queue.Buf[s_cmd_queue.In].buf,&pBuf[cmd_head_index],s_cmd_queue.Buf[s_cmd_queue.In].len);
					s_cmd_queue.In++;
					s_cmd_queue.Count++;
					s_cmd_queue.In %= s_cmd_queue.Size;
					offset +=5;
					decode_count +=5;
					remain_count -=5;
                    break;                       //��break����������⻺�����Ǵ�����һ������
				}
				else 
				{
					offset++;
					decode_count++;
					remain_count--;
				}
			}

		}
		else
		{
			offset++;
			decode_count++;
			remain_count--;
		}
	}
    if (offset != 0)
    {
        for (int i=0; i < remain_count; i++)
        {
            pBuf[i] = pBuf[offset+i];
        }
    }
    return decode_count;
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

