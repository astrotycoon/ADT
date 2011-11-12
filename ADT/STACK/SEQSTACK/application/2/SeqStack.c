/**********************************************************************
*	文件名: SeqStack.c 
*
*	文件描述: 实现顺序栈操作函数
*
*	创建人: Astrol 2011-10-10 22:29:51
*
*	版本号: 1.0
*
*	修改记录:
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "SeqStack.h"

/* 顺序栈的初始化操作 */
void InitStack(SeqStack *S)
{
	S->top = 0; 
}


/* 判断栈是否为空 */
bool StackEmpty(SeqStack S)
{
	if (S.top == 0)  	/* 如果S.top等于0,则是空栈,返回true */
		return true; 
	else			/* 否则返回false */
		return false;		
}


 /* 取栈顶元素操作 */
bool GetTop(SeqStack S, SDataType *e)
{
	if (S.top <= 0)  /* 如果是空栈,直接返回报错 */
		return false;

	*e = S.data[S.top - 1];	
	
	return true;
}


/* 进栈操作 */
bool PushStack(SeqStack *S, SDataType e)
{
	if (S->top >= MAXSIZE)	/* 如果栈已满,直接返回报错 */
		return false;	
	
	S->data[S->top] = e;
	S->top++;			/* S->data[S->top++] = e */
	
	return true;
}


/* 出栈操作 */
bool PopStack(SeqStack *S, SDataType *e)
{
	if (StackEmpty(*S)) 	/* 如果是空栈,直接返回报错 */
		return false;

	S->top--;
	*e = S->data[S->top];	/* *e = S->data[--top]*/

	return true;
}


/* 获得栈的长度操作 */
int StackLength(SeqStack S)
{
	return S.top;
}


/* 清空栈操作 */
void ClearStack(SeqStack *S)
{
	S->top = 0;
}
