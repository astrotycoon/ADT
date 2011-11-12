/**********************************************************************
*	文件名: SqQueue.c
*
*	文件描述: 实现循环队列的操作函数
*
*	创建人: Astrol	2011-10-24 16:40:45
*
*	版本号: 1.0
*
*	修改记录:
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "SqQueue.h"

/* 初始化操作 */
void InitQueue(SqQueue* Q)
{
	Q->head = Q->tail = 0;
	return;
}

/* 销毁操作 */
void ClearQueue(SqQueue* Q)
{
	Q->head = Q->tail = 0;	
	return;
}

/* 判断是否为空操作 */
bool QueueEmpty(SqQueue Q)
{	/* (tail-head+MAXQSIZE)%MAXQSIZE是通用的计算队列长度公式 */
	if ((Q.tail - Q.head + MAXQSIZE) % MAXQSIZE == 0) 
		return true;
	else
		return false;
}	

/* 取得对头元素 */
bool GetHead(SqQueue Q, DataType* e)
{
	if (QueueEmpty(Q) == false)
	{
		errno = EINVAL;	/* 参数不对 */
		return false;
	}

	*e = Q.data[Q.head];

	return false;
}

/* 插入新元素到队尾 */
bool EnQueue(SqQueue* Q, DataType e)
{	/* (tail + 1) % MAXQSIZE == head是判断队列是否已满 */
	if ((Q->tail + 1) % MAXQSIZE == Q->head)	/* 队列已满 */
	{
		errno = EINVAL;	/* 参数不对 */
		return false;
	} 

	Q->data[Q->tail] = e;	/* 将元素e插入队尾 */
	Q->tail = (Q->tail + 1) % MAXQSIZE;
	
	return true;
}

/* 删除对头元素 */
bool DeQueue(SqQueue* Q, DataType* e)
{
	if (QueueEmpty(*Q) == false)
	{
		errno = EINVAL;	/* 参数不对 */
		return false;
	}

	*e = Q->data[Q->head];
	Q->head = (Q->head + 1) % MAXQSIZE;

	return true;
}

/* 取得队列长度操作 */
int QueueLength(SqQueue Q)
{
	return (Q.tail - Q.head + MAXQSIZE) % MAXQSIZE;
}

/* 遍历队列 */
void QueueTraverse(SqQueue Q, void (*fp)(DataType))
{
	int pos;

	if (QueueEmpty(Q) == false)
	{
		errno = EINVAL;
		return;
	}

	pos = Q.head;	
	while (pos != Q.tail)
	{
		(*fp)(Q.data[Q.head]);
		pos = (pos + 1) % MAXQSIZE;
	}
}

