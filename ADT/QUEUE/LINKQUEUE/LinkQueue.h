/**********************************************************************
*	文件名: LinkQueue.h
*
*	文件描述: 链队列的头文件
*
*	创建人: Astrol  2011-10-24 20:46:04
*
*	版本号: 1.0
*
*	修改记录:
**********************************************************************/

#ifndef __LINKQUEUE_H__
#define __LINKQUEUE_H__

#include <stdbool.h>	/* C99特性 */
extern int errno;
typedef int DataType;	/* DataType类型根据实际情况而定,这里假设为int */
typedef struct QNode	/* 链队列结点定义 */
{
	DataType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct	/* 链队列结构定义 */
{
	int size;
	QueuePtr head;	/* 对头指针, 若队列不空, 指向队列头结点 */
	QueuePtr tail;	/* 队尾指针, 若不空, 指向队尾元素, 若为空,  */
}LinkQueue;		/* 指向头结点 */

/* 链队列的各种操作 */

/* 初始化操作 */
void InitQueue(LinkQueue* Q);

/* 清空操作 */
void ClearQueue(LinkQueue* Q);

/* 判断是否为空操作 */
bool QueueEmpty(LinkQueue Q);

/* 取得对头元素 */
bool GetHead(LinkQueue Q, DataType* e);

/* 插入新元素到队尾 */
bool EnQueue(LinkQueue* Q, DataType e);

/* 删除对头元素 */
bool DeQueue(LinkQueue* Q, DataType* e);

/* 取得队列长队操作 */
int QueueLength(LinkQueue Q);

/* 遍历队列 */
void QueueTraverse(LinkQueue Q, void (*fp)(DataType));

#endif	/* __LINKQUEUE_H__ */
