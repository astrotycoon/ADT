/**********************************************************************
*	文件名: CirList.c
*
*	文件描述: 实现循环单链表(带头结点)的操作
*
*	创建人: Astrol 2011-10-28 21:42:18
*
*	版本号: 1.0
*
*	修改记录:
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "CirList.h"

/* 初始化操作 */
void InitList(p_CirList list)
{
	list->head = (p_CirNode)malloc(sizeof(CirNode));
	if (list->head == NULL)
	{
		errno = ENOMEM;
		return;
	}
	
	list->tail = (p_CirNode)malloc(sizeof(CirNode));
	if (list->tail == NULL)
	{
		errno = ENOMEM;
		free(list->head);
		return;
	}

	list->head->prev = list->tail;
	list->head->next = list->tail;
	list->tail->prev = list->head;
	list->tail->next = list->head;
	list->size = 0;
}

/* 判断是否为空 */
bool ListEmpty(CirList list)
{
	if (list.size == 0)	
		return true;
	else
		return false;
}

static p_CirNode GetNode(p_CirList list, int i)
{
	p_CirNode p = NULL;
	int k;

	if (list == NULL || i < 0 || i > list->size)
	{
		errno = EINVAL;
		return NULL; 
	}

	if (i <= (list->size / 2))
	{
		p = list->head;
		for (k = 0; k < i; k++)
		{
			p = p->next;
		}
	}
	else
	{
		p = list->tail;
		int max = list->size - i + 1;
		for (k = 0; k < max; k++)
		{
			p = p->prev;
		}
	}

	return p;
}

/* 得到循环链表的第i个元素 */
bool GetElem(p_CirList list, int i, DataType* e)
{
	p_CirNode p = NULL;

	p = GetNode(list, i);
	if (NULL == p)
	{
		errno = EINVAL;
		return false;
	}
	*e = p->data;
	
	return true;
}

/* 得到循环单链表指定元素的结点指针 */
p_CirNode LocateList(CirList list, DataType e, int (*fp)(DataType, DataType))
{
	p_CirNode p = NULL;

	p = list.head->next;	/* p指向第一个结点 */
	
	if (list.head->next == list.tail)
	{
		errno = EINVAL;
		return NULL;
	}

	while (p != list.tail)
	{
		if (0 == (*fp)(e, p->data))
		{
			return p;
		}
		else
		{
			p = p->next;
		}
	}

	return NULL;
}	

/* 得到循环链表指定元素的位置 */
int LocatePos(CirList list, DataType e, int (*fp)(DataType, DataType))
{
	p_CirNode p = NULL;
	int k;

	p = list.head->next;	/* p指向第一个结点 */
	k = 1;

	if (list.head->next == list.tail)
	{
		errno = EINVAL;
		return 0;
	}

	while (p != list.tail)
	{
		if (0 == (*fp)(e, p->data))
		{
			return k;
		}
		else
		{
			p = p->next;
			k++;
		}
	}

	return 0;
}

/* 插入操作 */
bool ListInsert(p_CirList list, int i, DataType e)
{
	p_CirNode p = NULL;
	p_CirNode q = NULL;

	p = GetNode(list, i);
	if (NULL == p)
	{
		errno = EINVAL;
		return false;
	}

	q = (p_CirNode)malloc(sizeof(CirNode));
	if (NULL == q)
	{
		errno = ENOMEM;
		return false;
	}	

	q->data = e;
	
	if (p == list->head)
	{
		q->next = list->tail;
		q->prev = p;
		p->next = q;
		list->tail->prev = q;
	}
	else
	{
		q->next = p->next;
		q->prev = p;
		p->next->prev = q;
		p->next = q;
	}

	list->size++;

	return true;
}
	
/* 删除操作 */
bool ListDelete(p_CirList list, int i, DataType* e)
{
	p_CirNode p = NULL;
	
	p = GetNode(list, i);
	if (NULL == p)
	{
		errno = EINVAL;
		return false;
	}	

	*e = p->data;

	p->prev->next = p->next;
	p->next->prev = p->prev;
	
	list->size--;
	free(p);
	
	return true;
}

/* 得到循环链表的长度 */
int ListLength(CirList list)
{
	return list.size;
}

 /* 清空循环链表 */
void ClearList(p_CirList list)
{
	p_CirNode p = NULL;
	p_CirNode q = NULL;

	p = list->head->next;	/* p指向第一个结点 */

	while (p != list->tail)
	{
		q = p->next;
		free(q);
		p = q;
	}
	
	free(list->head);
	free(list->tail);
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}

/* 遍历链表 */
void ListTraverse(CirList list, void (*fp)(DataType))
{
	p_CirNode p = NULL;
	
	p = list.head->next;	/* p指向第一个结点 */

	if (list.size == 0)
	{
		errno = EINVAL;
		return;
	}

	while (p != list.tail)
	{
		(*fp)(p->data);
		p = p->next;
	}
}
