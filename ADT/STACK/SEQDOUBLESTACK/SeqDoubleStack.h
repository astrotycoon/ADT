/**********************************************************************
*	文件名: SeqDoubleStack.h
*
*	文件描述: 共享栈头文件
*
*	创建人: Astrol 2011-10-10 23:26:07
*
*	版本号: 1.0
*
*	修改记录:
***********************************************************************/

#ifndef __SEQDOUBLESTACK_H__
#define __SEQDOUBLESTACK_H__

#include <stdbool.h>	/* C99特性 */

#define MAXSIZE 100	/* 存储空间初始化分配量 */
typedef int SDataType; 	/* SDataType类型根据实际情况而定这里假设为int */


/* 共享栈的结构定义 */
typedef struct 
{
	SDataType data[MAXSIZE];
	int top1;	/* 用于栈1栈顶指针 */
	int top2;	/* 用于栈2栈顶指针 */
}SeqDoubleStack;

/* 共享栈的各种操作 */

/* 共享栈的初始化操作 */
void InitStack(SeqDoubleStack *S);
/* 判断栈是否为空 */
bool StackEmpty(SeqDoubleStack S, int StackNumber);
/* 取栈顶元素操作 */
bool GetTop(SeqDoubleStack S, SDataType *e, int StackNumber);
/* 进栈操作 */
bool PushStack(SeqDoubleStack *S, SDataType e, int StackNumber);
/* 出栈操作 */
bool PopStack(SeqDoubleStack *S, SDataType *e, int StackNumber);
/* 获得栈的长度操作 */
int StackLength(SeqDoubleStack S, int StackNumber);
/* 清空栈操作 */
void ClearStack(SeqDoubleStack *S, int StackNumber);

#endif
