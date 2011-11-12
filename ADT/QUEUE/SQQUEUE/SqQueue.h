/**********************************************************************
*	文件名: SqQueue.h
*
*	文件描述: 循环队列的头文件
*
*	创建人: Astrol  2011-10-24 16:02:39
*
*	版本号: 1.0
*
*	修改记录:
**********************************************************************/
#ifndef __SQQUEUE_H__
#define __SQQUEUE_H__

#include <stdbool.h>	/* C99特性 */

extern int errno;
typedef MAXQSIZE 100	/* 最大队列长度 */
typedef int DataType;	/* DataType类型根据实际情况而定,这里假设为int */
typedef struct 		/* 循环队列结构定义 */
{
	DataType data[MAXQSIZE];/* 初始化的动态分配存储空间 */
	int head;	/* 头指针, 若队列不空, 指向队列头元素 */
	int tail;	/* 尾指针, 若队列不空, 指向队列尾元素的下一个位置 */
}SqQueue;

/* 循环队列的各种操作函数 */

/* 初始化操作 */
void InitQueue(SqQueue* Q);

/* 清空操作 */
void ClearQueue(SqQueue* Q);

/* 判断是否为空操作 */
bool QueueEmpty(SqQueue Q);

/* 取得对头元素 */
bool GetHead(SqQueue Q, DataType* e);

/* 插入新元素到队尾 */
bool EnQueue(SqQueue* Q, DataType e);

/* 删除对头元素 */
bool DeQueue(SqQueue* Q, DataType* e);

/* 取得队列长度操作 */
int QueueLength(SqQueue Q);

/* 遍历队列 */
void QueueTraverse(SqQueue Q, void (*fp)(DataType));

#endif 	/* __SQQUEUE_H__ */
