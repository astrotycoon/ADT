/**********************************************************************
*	文件名: LinkQueue.c
*
*	文件描述: 链队列函数实现
*
*	创建人: Astrol 2011-10-24 21:13:46
*
*	版本号: 1.0
*
*	修改记录:
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "LinkQueue.h"

/* 初始化操作 */
void InitQueue(LinkQueue* Q)
{
	Q->head = (QueuePtr)malloc(sizeof(QNode));/* 开辟头结点 */
	if (Q->head == NULL)
	{
		errno = ENOMEM;	/* 分配内存失败 */
		return;
	}

	Q->tail = Q->head;
	Q->size = 0;
}

/* 清空操作 */
void ClearQueue(LinkQueue* Q)
{
	QueuePtr* p = NULL;
	QueuePtr* q = NULL;

	if (Q->head == Q->tail)	/* 空队列 */
	{
		errno = EINVAL;	/* 参数错误 */
		return;
	}

	p = Q->head->next;	/* p指向第一个结点 */
	
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}

	free(Q->head);	/* 释放头结点 */
	Q->head = NULL;
	Q->tail = Q->head;
	Q->size = 0;
}

/* 判断是否为空操作 */
bool QueueEmpty(LinkQueue Q)
{	/* Q.size == 0 ? true : false; */
	if (Q.head->next == NULL)
		return true;
	else	
		return false;
}

/* 取得对头元素 */
bool GetHead(LinkQueue Q, DataType* e)
{
	if (Q.head == Q.tail)	/* 空队列 */
	{
		errno = EINVAL;	/* 参数错误 */
		return false;
	}

	*e = Q.head->next->data;

	return true;
}

/* 插入新元素到队尾 */
bool EnQueue(LinkQueue* Q, DataType e)
{
	QueuePtr p = NULL;

	p = (QueuePtr)malloc(sizeof(QNode));
	if (p == NULL)
	{
		errno = ENOMEM;	/* 分配内存失败 */
		return false;
	}	

	p->data = e;
	p->next = NULL;

	Q->tail->next = p;
	Q->tail = p;
	Q->size++;

	return true;
}
/* 删除对头元素 */
bool DeQueue(LinkQueue* Q, DataType* e)
{
	QueuePtr p = NULL;

	if (Q->head == Q->tail)	/* 空队列 */
	{
		errno = EINVAL;	/* 参数错误 */
		return false;
	}

	p = Q->head->next;	/* p指向要删除的第一个结点 */
	*e = p->data;
	Q->head->next = p->next;
	
	if (Q->tail == p)
		Q->tail = Q->head;
	free(p);
	Q->size--;

	return true;
}
/* 取得队列长队操作 */
int QueueLength(LinkQueue Q)
{
	return Q.size;
}

/* 遍历队列 */
void QueueTraverse(LinkQueue Q, void (*fp)(DataType))
{
	QueuePtr p = NULL;

	if (Q.head == Q.tail)
	{
		errno = EINVAL;	/* 参数错误 */
		return;
	}

	p = Q.head->next;	/* p指向第一个结点 */

	while (p)
	{
		(*fp)(p->data);
		p = p->next;
	}	
}
