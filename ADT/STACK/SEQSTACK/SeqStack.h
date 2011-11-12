/**********************************************************************
*	文件名: SeqStack.h
*
*	文件描述: 顺序栈头文件
*
*	创建人: Astrol 2011年10月10日22:04:25
*
*	版本号: 1.0
*
*	修改记录:
***********************************************************************/

#ifndef __SEQSTACK_H__
#define __SEQSTACK_H__

#include <stdbool.h>	/* C99特性 */

#define MAXSIZE 100	/* 存储空间初始化分配量 */
typedef int SDataType; 	/* SDataType类型根据实际情况而定这里假设为int */

/* 栈的结构定义 */
typedef struct
{
	SDataType data[MAXSIZE];
	int top;	/* 用于栈顶指针 */
}SeqStack;


/* 顺序栈的各种操作 */

/* 顺序栈的初始化操作 */
void InitStack(SeqStack *S);
/* 判断栈是否为空 */
bool StackEmpty(SeqStack S);
/* 取栈顶元素操作 */
bool GetTop(SeqStack S, SDataType *e);
/* 进栈操作 */
bool PushStack(SeqStack *S, SDataType e);
/* 出栈操作 */
bool PopStack(SeqStack *S, SDataType *e);
/* 获得栈的长度操作 */
int StackLength(SeqStack S);
/* 清空栈操作 */
void ClearStack(SeqStack *S);

#endif
