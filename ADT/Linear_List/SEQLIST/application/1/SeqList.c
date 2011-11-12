/*********************************************************************
*	文件名:	SeqList.c
*
*	文件描述: 实现顺序表操作函数
*
*	创建人: Astrol  2011年9月5日
*
*	版本号: 1.0
*
*	修改记录:
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "SeqList.h"

extern int compare(DataType, DataType);


/* 初始化顺序表 */
void InitList(SeqList * L)
{
	assert(L != NULL);
	L->length = 0; /* 把线性表的长度设置为0 */
}


/* 判断顺序表是否为空 */
bool ListEmpty(SeqList L)
{
	if(0 == L.length) /* 判断顺序表的长度是否为0 */
		return true; /* 如果为0,返回true,否则返回false */
	else
		return false;
}


/* 得到顺序表的第i个元素 */
bool GetElem(SeqList L, int i, DataType *e)
{
	if(i < 1 || i > ListLength(L)) /* 在查找第i个元素之前,先判断该序号是否合法*/
		return false;

	*e = L.list[i - 1];  /* 将第i个元素的值赋给e */

	return true;
}


/* 得到顺序表指定元素的位置 */
int LocateList(SeqList L, DataType e, int (*fp)(DataType, DataType) )
{
	int i;

	for(i = 0; i < L.length; i++)
	{
		if(0 == (*fp)(e, L.list[i]) )
			return i+1;
	}
		
	return 0;
}


/* 在顺序表的指定位置插入指定元素 */
bool ListInsert(SeqList *L, int i, DataType e)
{
	assert(L != NULL);

	int k;

	if(i < 1 || i > L->length + i) /* 在插入元素前,判断插入位置是否合法 */
		return false;
	else if(L->length >= LISTSIZE) /* 在插入元素前,判断顺序表是否已满 */
		return false;
	else  /* 将第i个位置以后的元素依次后移 */
	{
		for(k = L->length; k >= i; k--)
		{
			L->list[k] = L->list[k -1];
		}		
		
		L->list[i - 1] = e; /* 插入元素到第i个位置 */
		L->length++; 	    /* 将顺序表长增1 */

		return true;
	}	
}	

/* 删除顺序表的第i个结点 */
bool ListDelete(SeqList *L, int i, DataType *e)
{
	assert(L != NULL);

	int k;

	if(L->length == 0) 		/* 在删除元素前,判断L是否为空 */
		return false;
	else if(i < 1 || i > L->length) /* 在删除元素前,判断删除位置是否合法 */
		return false;
	else
	{
		*e = L->list[i - 1];

		for(k = i; k < L->length; k++)
		{
			L->list[k - 1] = L->list[k];
		}
		
		L->length--; /* 将顺序表长减1 */

		return true;
	}

}


/* 得到顺序表的长度 */
int ListLength(SeqList L)
{
	return L.length;
}


/* 清空顺序表 */
void ClearList(SeqList *L)
{
	assert(L != NULL);
	
	L->length = 0;
}


/* 得到顺序表指定数据元素的前驱 */
bool PriorElem(SeqList L, DataType cur_e, DataType *pre_e)
{
	int pos;
	
	pos = LocateList(L, cur_e, compare);

	if(pos < 2)
		return false;
	
	*pre_e = L.list[pos - 2];
	return true;

}


/* 得到顺序表指定数据元素的后继 */
bool NextElem(SeqList L, DataType cur_e, DataType *pre_e)
{
	int pos;

	pos = LocateList(L, cur_e, compare);

	if(pos = L.length)
		return false;
	
	*pre_e = L.list[pos];
	return true;
}	


/* 遍历顺序表 */
void ListTraverse(SeqList L, void (*fp)(DataType) )
{
	assert(fp != NULL);

	int k;

	for(k = 0; k < L.length; k++)
	{
		(*fp)(L.list[k]);
	}

}

extern int compare(DataType n, DataType m)
{
	if(n == m)
		return 0;    /*(n == m) ? (return 0) : (return -1)*/
	else
		return -1;
}
