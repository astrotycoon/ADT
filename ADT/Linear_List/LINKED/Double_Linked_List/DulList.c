/**********************************************************************
*	文件名: DulList.c 
*
*	文件描述: 实现双向链表的操作
*
*	创建人: Astrol	2011-10-18 0:41:16
*
*	版本号: 1.0
*
*	修改记录:
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "DulList.h"

/* 双向链表的初始化操作 */
bool InitList(DulList *head)
{
	if ((*head = (DulList *)malloc(sizeof(DulNode))) == NULL)
		return false;	
	(*head)->prior = NULL;
	(*head)->next = NULL;	/* 动态生成一个头结点,并且指针域为空 */
}

/* 判断双向链表是否为空 */
bool ListEmpty(DulList head)
{
	if (head->next == NULL)	/* 判断双向的后继指针是否为空 */
		return true;	/* 为空返回true,否则返回false */
	else
		return false;
}

/* 得到双向链表的第i个元素 */
bool GetElem(DulList head, int i, DataType *e)
{
	assert(head->next != NULL);
	
	DulList p = NULL;
	int k;

	p = head->next;	/* p指向第一个结点 */
	k = 1;		/* k是计时器 */

	while (p && k < i)	/* while (p != NULL && k < i)*/
	{
		p = p->next;
		k++;
	}

	if (!p || k > i)
		return false;
	
	*e = p->data;
	
	return true;
}

/* 得到双向链表指定元素的结点指针 */
DulList LocateList(DulList head, DataType e, int (*fp)(DataType, DataType))
{
	assert(head->next != NULL);
	
	DulList p = NULL;

	p = head->next;	/* p指向第一个结点 */

	while (p)	/* while (p != NULL)*/
	{
		if (0 == (*fp)(e, p->data))
			return p;
		else
			p = p->next;
	}		
	
	return NULL;
}


/* 得到双向链表指定元素的位置 */
int LocatePos(DulList head, DataType e, int (*fp)(DataType, DataType))
{
	assert(head->next != NULL);
	
	DulList p = NULL;
	int i;

	p = head->next;	/* p指向第一个结点 */
	i = 1;

	while (p)	/* while (p != NULL)*/
	{
		if (0 == (*fp)(e, p->data))
			return i;
		else
		{
			p = p->next;	
			i++;
		}
	}
	
	return 0;
}

/* 插入操作 */
bool ListInsert(DulList *head, int i, DataType e)
{
	assert(*head != NULL);

	DulList p = NULL;
	DulList q = NULL;
	int k;

	p = *head;	/* p指向头结点 */
	k = 1;

	while (p->next && k < i)	/* 寻找第i个结点 */
	{
		p = p->next;
		k++;
	}	

	if (!p || k > i)
		return false;

	if ((q = (DulList)malloc(sizeof(DulNode))) == NULL)/* 为q分配空间 */
		return false;

	q->date = e;	/* 为q->data赋值 */

	q->prior = p;
	q->next = p->next;
	p->next = q;
	p->next->prior = q;

	return true;	
}


/* 删除操作 */
bool ListDelete(DulList *head, int i, DataType *e)
{
	assert((*head)->next != NULL);

	DulList p = NULL;
	int k;

	p = (*head)->next;	/* p指向第一个结点 */
	k = 1;			/* k为计数器 */

	while (p && k < i)
	{
		p = p->next;
		k++;
	}

	if (!p || k > i)
		return false;
	
	*e = p->data;
	p->next->prior = p->prior;
	p->prior->next = p->next;
	free(p);
	p = NULL;

	return true;
}

/* 得到双向链表的长度 */
int ListLength(DulList head)
{
	assert(head->next != NULL);

	DulList p = NULL;
	int count;

	p = head->next;	/* p指向第一个结点 */
	count = 0;

	while (p)
	{
		p = p->next;
		count++;
	}

	return count;
}

/* 清空双向链表 */
void ClearList(DulList *head)
{
	assert((*head)->next != NULL);

	DulList p = NULL;
	DulList q = NULL;

	p = (*head)->next;	/* p指向第一个结点 */
	
	while (p)
	{
		q = p->next;
		free(p);
		p = q;		
	}

	(*head)->next = NULL;
}


/* 遍历双向链表 */
void ListTraverse(DulList head, void (*fp)(DataType))
{
	assert(head->next != NULL);
	
	DulList p = NULL;
	
	p = head->next;	/* p指向第一个结点 */

	while (p)
	{
		(*fp)(p->data);
		p = p->next;
	}
}
