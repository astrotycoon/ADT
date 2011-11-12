/*********************************************************************
*	文件名: heapstring.h
*
*	文件描述: 串的堆分配存储函数实现
*
*	创建人: Astrol 2011-11-7 0:19:50
*
*	版本号: 1.1
*
*	修改记录:
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "heapstring.h"

p_heapstring_t heapstring_create(char* chars)
{
	p_heapstring_t heapstring_ret = NULL;
	char* chars_ret = NULL;
	char* chars_tmp = NULL;
	int len;

	heapstring_ret = (p_heapstring_t)malloc(sizeof(heapstring_t));
	if (NULL == heapstring_ret)
	{
		errno = ENOMEM;
		return NULL;
	}

	for (len = 0, chars_tmp = chars; *chars_tmp != '\0'; ++len, ++chars_tmp);
	if (0 == len)
	{
		heapstring_ret->ch = NULL;
		heapstring_ret->length = 0;
	}
	else
	{	
		heapstring_ret->ch = (char *)malloc(sizeof(char) * (len + 1));
		if (NULL == heapstring_ret->ch)
		{
			free(heapstring_ret);	/* don't forget */
			errno = ENOMEM;
			return NULL;
		}
	
		chars_ret = heapstring_ret->ch;
		chars_tmp = chars;
		while (*chars_ret++ = *chars_tmp++);
		heapstring_ret->length = len;
	}

	return heapstring_ret;
}

int heapstring_len(const p_heapstring_t string)
{
	if (string == NULL)
	{
		errno = EINVAL;
		exit(EXIT_FAILURE);
	}

	return string->length;
}

int heapstring_cmp(const p_heapstring_t dst, const p_heapstring_t src)
{
	int ret;
	char* char_dst = NULL;
	char* char_src = NULL;

	if (NULL == dst || NULL == src)
	{
		errno = EINVAL;
		exit(EXIT_FAILURE);
	}
	char_dst = dst->ch;
	char_src = src->ch;

	while (( ret = ( *(unsigned char *)char_dst - *(unsigned char *)char_src )) == 0 
								&& *char_src != '\0')
	{
		++char_dst;
		++char_src;
	}

	if (ret < 0)
		return -1;
	if (ret > 0)
		return 1;
	
	return 0;
}

bool heapstring_cat(p_heapstring_t dst, const p_heapstring_t src1,
				const p_heapstring_t src2)
{
	char *char_dst = NULL;
	char *char_src1 = NULL;
	char *char_src2 = NULL;

	if (NULL == dst || NULL == src1 || NULL == src2)
	{
		errno = EINVAL;
		return false;
	}

	if (NULL != dst)
		free(dst->ch);
	dst->ch = (char *)malloc(sizeof(char) * (src1->length + src2->length + 1));	
	if (NULL == dst->ch)
	{
		errno = ENOMEM;
		return false;
	}
	dst->length = 0;
		
	char_dst  = dst->ch;
	char_src1 = src1->ch;
	char_src2 = src2->ch;

	while (*char_dst++ = *char_src1++);
	--char_dst;	//easy to forget, +_+
	while (*char_dst++ = *char_src2++);
	*char_dst = '\0';
	dst->length = src1->length + src2->length;

	return true;;
}

bool heapstring_sub(p_heapstring_t sub, const p_heapstring_t string,
					int pos, int len)
/* 1 <= pos <= string->length, 0 <= len <= string->length - pos + 1 (靠靠) */
{
	char * char_string = NULL;
	char *    char_sub = NULL;
	int tmp = 0;

	if (NULL == sub || NULL == string || pos < 1 || 
	pos > string->length || len < 0 || len > string->length - pos + 1)
	{
		errno = EINVAL;
		return false;
	}
	
	if (NULL != sub->ch)
		free(sub->ch);
	if (0 == len)
	{
		sub->ch = NULL;
		sub->length = 0;
	}
	else
	{
		sub->ch = (char *)malloc(sizeof(char)*len + 1);
		if (NULL == sub->ch)
		{
			errno = ENOMEM;
			return false;
		}
		sub->length = 0;

		char_string = string->ch + pos -1;
		char_sub = sub->ch;
		while (*char_sub++ = *char_string++)
		{
			if (++tmp == len)
				break;	
		}
		*char_sub = '\0';
		sub->length = len;
	}
	
	return true;
}

bool heapstring_empty(const p_heapstring_t string)
{
	if (NULL == string)
	{
		errno = EINVAL;
		return false;
	}
	if (0 == string->length)
		return true;
	else
		return false;
}		

bool heapstring_cpy(p_heapstring_t dst, const p_heapstring_t src)
{
	char* chars_src = NULL;
	char* chars_dst = NULL;

	if (NULL == dst || NULL == src)
	{
		errno = EINVAL;
		return false;
	}

	if (NULL != dst)
		free(dst->ch);
	dst->ch = (char *)malloc(sizeof(char) * (src->length + 1));
	if (NULL == dst->ch)
	{
		errno = ENOMEM;
		return false;
	}

	chars_src = src->ch;
	chars_dst = dst->ch;

	while (*chars_dst++ = *chars_src++);
	*chars_dst = '\0';	
	
	dst->length = src->length;
	return true;
}

bool heapstring_destroy(p_heapstring_t string)
{
	if (NULL == string)
	{
		errno = EINVAL;
		return false;
	}

	if (NULL != string->ch)
	{
		free(string->ch);
		string->ch = NULL;
	}
	
	free(string);

	return true;
}

int heapstring_index(const p_heapstring_t corpora, const p_heapstring_t subset, 
							int pos)
{
	p_heapstring_t sub = NULL;
	int index;

	/* 1 <= pos <= corpora->length - subset->length + 1*/
	if (NULL == corpora || NULL == subset 
		|| pos < 1 || pos > corpora->length - subset->length + 1)
	{
		errno = EINVAL;
		return 0;
	}

	sub = heapstring_create("");
	if (NULL == sub)
	{
		errno = ENOMEM;
		exit(EXIT_FAILURE);;
	}

	index = pos;
	while (index <= corpora->length - subset->length + 1)
	{
		if (heapstring_sub(sub, corpora, index, subset->length))
		{
			if (heapstring_cmp(sub, subset) == 0)
			{
				return index;	
			}
			index++;
		}
	}
		
	heapstring_destroy(sub);

 	return 0;
}

bool heapstring_insert(p_heapstring_t dst, int pos, p_heapstring_t src)
{       /* 1 <= pos <= dst->length */
        char* chars_dst = NULL;
        char* chars_src = NULL;
        int pos_dst;
        int pos_src;

        if (NULL == dst || NULL == dst->ch ||
            NULL == src || NULL == src->ch ||
            pos < 0 || pos > dst->length)
        {
                errno = ENOMEM;
                return false;
        }

        dst->ch = (char *)realloc(dst->ch, sizeof(char) * (dst->length + src->length + 1));
        if (NULL == dst->ch)
        {
                errno = ENOMEM;
                return false;
        }

        chars_dst = dst->ch + dst->length; //chars_dst point to the end of dst->ch
        for (pos_dst = dst->length - pos + 2; pos_dst > 0; pos_dst--)
        {
                *(chars_dst + src->length) = *chars_dst;
                chars_dst--;
        }

        chars_dst = dst->ch + pos - 1;
        chars_src = src->ch;
        for (pos_src = src->length; pos_src > 0; pos_src--)
        {
                *chars_dst++ = *chars_src++;
        }

	dst->length += src->length;

        return true;
}

bool heapstring_delete(p_heapstring_t string, int pos, int len)
{       /* 1 <= pos <= string->length - len + 1 */
        char* chars_new = NULL;
        char* chars_string = NULL;
        char* chars_len = NULL;
	char* chars_pnew = NULL;

        if (NULL == string || NULL == string->ch
                || pos < 1 || pos > string->length - len + 1)
        {
                errno = EINVAL;
                return false;
        }

        chars_new = (char *)malloc(sizeof(char) * (string->length - len + 1));
        if (NULL == chars_new)
        {
                errno = ENOMEM;
                return false;
        }

	
        chars_string = string->ch;
        chars_len = string->ch + pos + len - 1;
	chars_pnew = chars_new;
	if (1 == pos)
	{
		while (*chars_pnew++ = *chars_len++);
	}
	else
	{
        	while (*chars_pnew++ = *chars_string++)
        	{
                	if (chars_string == string->ch + pos - 1)
                        	break;
        	}

        	while (*chars_pnew++ = *chars_len++);
	}

        free(string->ch);
        string->ch = chars_new;
	string->length -= len;
        return true;
}

bool heapstring_replace(p_heapstring_t dst, const p_heapstring_t src, 
				const p_heapstring_t replace)
{
	int pos;
	int index;
	char* chars_dst = NULL;
	char* chars_replace = NULL;

	if (NULL == dst || NULL == src || NULL == replace)
	{
		errno = EINVAL;
		return false;
	}
	
	chars_dst = dst->ch;
	chars_replace =  replace->ch;

	if (src->length == replace->length)
	{	
		for (index = 1; pos = heapstring_index(dst, src, index); index = pos + replace->length)
		{
			chars_dst = chars_dst + pos - 1;
			while (*chars_dst = *chars_replace)
			{
				chars_dst++;
				chars_replace++;

				if ('\0' == *chars_replace)	//靠'\0'靠靠靠靠靠
					break;
			}
			chars_dst = dst->ch;
			chars_replace = replace->ch;
		}
	}
	else	//insert replace firstly, then  delete the src
	{
		index = 1;
		while (pos = heapstring_index(dst, src, index))
		{
			if (heapstring_insert(dst, pos, replace) == false)
			{
				errno = ENOMEM;
				return false;
			}
			index = replace->length + src->length + pos;
		}

		index = 1;
		while (pos = heapstring_index(dst, src, index))
		{
			if (heapstring_delete(dst, pos, src->length) == false)
			{
				errno = ENOMEM;
				return false;
			}
		}
	}
		
	return true; //work?
}
