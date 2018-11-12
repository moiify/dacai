/**
 **************************************************************************************************
 * @file        cstring.c
 * @author
 * @version
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#include "string.h"
#include "cstring.h"

/**
 * @addtogroup    XXX 
 * @{  
 */

/**
 * @addtogroup    cstring_Modules 
 * @{  
 */

/**
 * @defgroup      cstring_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      cstring_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      cstring_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      cstring_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      cstring_Private_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      cstring_Public_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      cstring_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      cstring_Functions 
 * @brief         
 * @{  
 */
unsigned short CString_HexStrToValueArray(char* srcStr,unsigned char* destArray)
{
    unsigned char high,low;
    unsigned short length = 0;
    char *p_src = srcStr;
    unsigned char *p_dest = destArray;

    length = strlen(p_src);
    if (length <= 0)
    {
        return CSTRING_ERR_EMPTY_STRING;
    }

    if ((length%2) != 0)
    {
        low = *p_src++;
        if ((low >= 0x30) && (low <= 0x39))
        {
            low -= 0x30;
        }
        else if ((low >= 0x41) && (low <= 0x46))
        {
            low -= 55;
        }
        else if ((low >= 0x61) && (low <= 0x66))
        {
            low -= 87;
        }
        else
        {
            low = 0x7E;
        }
        *p_dest++ = low;
    }

    while (*p_src != 0)
    {
        high = *p_src++;
        if ((high >= 0x30) && (high <= 0x39))
        {
            high -= 0x30;
        }
        else if ((high >= 0x41) && (high <= 0x46))
        {
            high -= 55;
        }
        else if ((high >= 0x61) && (high <= 0x66))
        {
            high -= 87;
        }
        else
        {
            high = 0x7E;
        }

        low = *p_src++;
        if ((low >= 0x30) && (low <= 0x39))
        {
            low -= 0x30;
        }
        else if ((low>=0x41)&&(low<=0x46))
        {
            low -= 55;
        }
        else if ((low>=0x61)&&(low<=0x66))
        {
            low -= 87;
        }
        else
        {
            low = 0x7E;
        }
        *p_dest++ = (high<<4)+low;
    }
    return (length+1)/2;
}

unsigned short CString_ValueArrayToHexStr(unsigned char* srcArray,unsigned short arrayLength,char* destStr)
{
    unsigned short i;
    unsigned char tmp;
    unsigned char *p_array = srcArray;
    char *p_str = destStr;

    for (i=0; i<arrayLength; i++) 
    {
        tmp = p_array[i]>>4;
        if (tmp <= 9)
        {
            tmp += 0x30;
        }
        else
        {
            tmp += 55;
        }
        *p_str++ = tmp;

        tmp = p_array[i]&0x0F;
        if (tmp <= 9)
        {
            tmp += 0x30;
        }
        else
        {
            tmp += 55;
        }
        *p_str++ = tmp;
    }
    *p_str = 0;
    return i*2;
}

//char* CMem_Split(unsigned char* src,unsigned short src_len,unsigned char *delim,unsigned short delim_len)
//{
//    static unsigned char *cur = NULL;
//    unsigned char match_len = 0;
//
//    if (src != NULL)
//    {
//        cur = src;
//    }
//
//    if (src == NULL && cur == NULL)
//    {
//        return NULL;
//    }
//
//    char *p = src, *start_p = src;
//    unsigned short calc_len = len;
//    short tmp;
//    if (src == 0 || delim == 0)
//    {
//        return 0;
//    }
//
//    if(*delim)
//    {
//        while(length--)
//        {
//            match_len = 0;
//            for(int i=0; *(cur+i) == *(delim+i); i++)
//            {
//                match_len++;
//                if (match_len == delim_len) // ƥ�����
//                {
//
//                    *p = 0; // ��ƥ����ʼλ����0���ָ�ǰһ���ַ���
//                    *next = p + strlen(delim); // ������һ���ַ���λ��
//                    /* ����ʣ���ֽڳ��� */
//                    tmp = len - (*next - src); 
//                    if (tmp < 0)
//                    {
//                        *remain_len = 0;
//                    }
//                    else
//                    {
//                        *remain_len = tmp;
//                    }
//                    /* ��ʣ�೤��Ϊ0ʱ��nextΪ�� */
//                    if (*remain_len == 0)
//                    {
//                        *next = 0;
//                    }
//
//                    // ���˵���ʼλƥ��
//                    if (p != start_p)
//                    {
//                        return start_p;
//                    }
//                    
//                    p += strlen(delim)-1; // ���µ����ηָ�β��
//                    start_p += strlen(delim); // ������ʼλ��
//                    break;
//                }
//            }
//            p++;
//        }
//    }
//
//    return 0;
//}

/**
 * @brief    �������ַ���pBuf��delim�ַ���offset���ֵ�λ��
 * @param    pBuf:char* 
 * @param    delim:char 
 * @param    offset:unsigned char 
 * @retval   char*: 
 */
char* CString_IndexOfByte(char *pBuf,char delim,unsigned char offset)
{
    char *p = pBuf;

    while(offset && *p)
    {
        if (*p == delim)
        {
            offset--;
            if(offset == 0)
            {
                return p;
            }
        }
        p++;
    }

    return NULL;
}

/**
 * @brief    ��������src��delim��offset���ֵ�λ�á�ƥ��������delim
 * @param    src:unsigned char* 
 * @param    src_len:unsigned char 
 * @param    delim:unsigned char* 
 * @param    delim_len:unsigned char 
 * @param    offset:unsigned char 
 * @retval   unsigned char*: 
 */
unsigned char* CMem_IndexOfBytes(unsigned char *src,unsigned char src_len,unsigned char *delim,unsigned char delim_len,unsigned char offset)
{
    unsigned short match_len = 0,remain_len = src_len;
    unsigned char *cur = src;

    if (src_len == 0 || delim_len == 0 || src == NULL || delim == NULL || src_len < delim_len || offset == 0)
    {
        return 0;
    }

    while(remain_len >= delim_len)
    {
        match_len = 0;
        for(int i=0; *(cur+i) == *(delim+i); i++)
        {
            match_len++;
            if (match_len == delim_len) // ƥ�����
            {
                offset--;
                if (offset == 0)
                {
                    return cur;
                }
            }
        }
        cur++;
        
        remain_len--;
    }   

    return NULL;
}

/**
 * @brief    �Ƴ�����src�е�һ�γ��ֵ�delim�ָ���(��)֮ǰ���������ݡ�
 * @param    src:unsigned char* 
 * @param    src_len:unsigned short 
 * @param    delim:unsigned char* 
 * @param    delim_len:unsigned short 
 * @retval   unsigned short: 
 */
unsigned short CMem_RemoveAt(unsigned char* src,unsigned short src_len,unsigned char *delim,unsigned short delim_len)
{
    unsigned short match_len = 0,remain_len = src_len,offset = 0;
    unsigned char *cur = src;

    if (src_len == 0 || delim_len == 0 || src == 0 || delim == 0 || src_len < delim_len)
    {
        return 0;
    }
 
    while(remain_len >= delim_len)
    {
        match_len = 0;
        for(int i=0; *(cur+i) == *(delim+i); i++)
        {
            match_len++;
            if (match_len == delim_len) // ƥ�����
            {
                offset = cur - src + delim_len;
                for (i=0;i<src_len-offset;i++)
                {
                    src[i] = src[i+offset];
                }
                return offset;
            }
        }
        cur++;

        remain_len--;
    }

    return offset;
}

/**
 * @brief    �Ƴ�����src�����һ��delim�ָ���(��)֮ǰ���������ݡ�
 * @param    src:unsigned char* 
 * @param    src_len:unsigned short 
 * @param    delim:unsigned char* 
 * @param    delim_len:unsigned short 
 * @retval   unsigned short: 
 */
unsigned short CMem_RemoveAll(unsigned char* src,unsigned short src_len,unsigned char *delim,unsigned short delim_len)
{
    unsigned short match_len = 0, remain_len = src_len, offset = 0;
    unsigned char *cur = src;

    if (src_len == 0 || delim_len == 0 || src == 0 || delim == 0 || src_len < delim_len)
    {
        return 0;
    }

    while(remain_len >= delim_len)
    {
        match_len = 0;
        for(int i=0; *(cur+i) == *(delim+i); i++)
        {
            match_len++;
            if (match_len == delim_len) // ƥ�����
            {
                offset = cur - src + delim_len;
                break;
            }
        }
        cur++;

        remain_len--;
    }

    if (offset > 0)
    {
        for (int i=0;i<src_len-offset;i++)
        {
            src[i] = src[i+offset];
        }
    }
    return offset;
}

/**
 * @brief    ��destλ�ó�dest_len�����ݴ�src���Ƴ�
 * @param    src:unsigned char* 
 * @param    src_len:unsigned short 
 * @param    dest:unsigned char* 
 * @param    dest_len:unsigned short 
 * @retval   unsigned short: 
 */
unsigned short CMem_RemoveBlock(unsigned char *src,unsigned short src_len,unsigned char *dest,unsigned short dest_len)
{
    if ( (src <= dest) && 
        (src + src_len >= dest + dest_len))
    {
        unsigned short tmp_len = (src + src_len) - (dest + dest_len);
        for (int i=0; i<tmp_len; i++)
        {
            src[i] = dest[dest_len + i];
        }
        return dest_len;
    }

    return 0;
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

