/**********************************************************************
*	文件名: LinkStack.h
*
*	文件描述: 链栈头文件
*
*	创建人: Astrol 	2011-10-11 21:59:57
*
*	版本号: 1.0
*
*	修改记录:
**********************************************************************/

#ifndef __LINKSTACK_H__
#define __LINKSTACK_H__

#include <stdbool.h>	/* C99特性 */

typedef int SDataType;  /* SDataType类型根据实际情况而定这里假设为int */


/* 链栈的结构定义 */
typedef struct StackNode
{
	SDataType data;		/* 链栈的数据域 */
	struct StackNode *next;	/* 链栈的指针域 */
}StackNode, *LinkStackPtr;     	/* 结构体类型名, 指向结构的指针 */

typedef struct
{
	LinkStackPtr top;	/* 栈顶指针 */
	int count;		/* 链栈元素个数 */
}LinkStack;

/* 链栈的各种操作 */

/* 链栈的初始化操作 */
void InitStack(LinkStack *Stop);

/* 判断栈是否为空 */
bool StackEmpty(LinkStack Stop);

/* 取栈顶元素操作 */
bool GetTop(LinkStack Stop, SDataType *e);

/* 进栈操作 */
bool PushStack(LinkStack *Stop, SDataType e);

/* 出栈操作 */
bool PopStack(LinkStack *Stop, SDataType *e);

/* 获得栈的长度操作 */
int StackLength(LinkStack Stop);

/* 清空栈操作 */
void ClearStack(LinkStack *Stop);

#endif	/*__LINKSTACK_H__*/
