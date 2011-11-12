/*********************************************************************
*	文件名: heapstring.h
*
*	文件描述: 串的堆分配存储头文件
*
*	创建人: Astrol	2011-11-6 23:38:07
*
*	版本号: 1.0
*
*	修改记录:
*********************************************************************/

#ifndef __HEAPSTRING_H__
#define __HEAPSTRING_H__

#include <stdbool.h>	/* C99特性 */

/* 串的堆分配存储结构 */
typedef struct 
{
	char *ch;	/* 若是非空串, 则分配存储区, 否则ch为NULL*/
	int length;	/* 串长度 */
}heapstring_t, *p_heapstring_t;

/* 生成一个其值等于串常量chars的串string */
p_heapstring_t heapstring_create(char *chars);

/* 串的长度 */
int heapstring_len(const p_heapstring_t string);

/* 串的比较, dst > src返回1, dst == src返回0, dst < src返回-1 */
int heapstring_cmp(const p_heapstring_t dst,const p_heapstring_t src);

/* 串的联接 */
bool heapstring_cat(p_heapstring_t dst, const p_heapstring_t src1,
				const p_heapstring_t src2);
/* 求子串,用sub返回string的第pos个字符起字符长度为len的子串 */
bool heapstring_sub(p_heapstring_t sub,const p_heapstring_t string,
					 int pos, int len);
/* 判断是否是空串 */
bool heapstring_empty(const p_heapstring_t string);

/* 复制  */
bool heapstring_cpy(p_heapstring_t dst, const p_heapstring_t src);

/* 清空 */
bool heapstring_destroy(p_heapstring_t string);

/* 返回字串在主串中第pos个字符之后第一次出现的位置 */
int heapstring_index(const p_heapstring_t corpora, const p_heapstring_t subset, 
								int pos);
/* 替换字符串 */
bool heapstring_replace(p_heapstring_t dst, const p_heapstring_t src, 
				const p_heapstring_t replace);

/* 在第pos个字符之前插入字符串 */
bool heapstring_insert(p_heapstring_t dst, int pos, const p_heapstring_t src);

/* 删除从第pos字符起字符长度为len的字串 */
bool heapstring_delete(p_heapstring_t string, int pos, int len);


#endif	/* __HEAPSTRING_H__ */
