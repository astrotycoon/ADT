/**********************************************************************
*	文件名: SeqDoubleStack.c
*
*	文件描述: 实现共享栈操作函数
*
*	创建人: Astrol	2011-10-10 23:31:42
*
*	版本号: 1.0
*
*	修改记录:
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "SeqDoubleStack.h"


/* 共享栈的初始化操作 */
void InitStack(SeqDoubleStack *S)
{
	S->top1 = 0;
	S->top2 = MAXSIZE;
}


 /* 判断栈是否为空 */
bool StackEmpty(SeqDoubleStack S, int StackNumber)
{
	if (StackNumber == 1) 		/* 共享栈1 */
	{
		return (S.top1 == 0) ? true : false;
	}
	else if (StackNumber == 2)	/* 共享栈2 */
	{
		return (S.top2 == MAXSIZE) ? true : false;
	}
}


/* 取栈顶元素操作 */
bool GetTop(SeqDoubleStack S, SDataType *e, int StackNumber)
{
	if (StackNumber == 1)		/* 共享栈1 */
	{
		if (S.top1 <= 0)	/* 如果栈1是空栈,直接返回报错 */
			return false;
		*e = S.data[S.top1 - 1];
			return true;
	}
	else if (StackNumber == 2)	/* 共享栈2 */
	{
		if (S.top2 >= MAXSIZE)	/* 如果栈2是空栈,直接返回报错 */
			return false;
		*e = S.data[S.top2];
			return true;
	}
}


 /* 进栈操作 */
bool PushStack(SeqDoubleStack *S, SDataType e, int StackNumber)
{
	if (S->top1 + 1 == S->top2)	/* 如果栈满,直接返回报错 */
		return false;
	if (StackNumber == 1)		/* 共享栈1 */
	{
		S->data[S->top1++] = e;
	}
	else if (StackNumber == 2)	/* 共享栈2 */
	{
		S->data[--S->top2] = e;
	}
	return true;
}


/* 出栈操作 */
bool PopStack(SeqDoubleStack *S, SDataType *e, int StackNumber)
{
	if (StackNumber == 1)		/* 共享栈1 */
	{
		if (StackEmpty(*S, 1))	/* 如果是空栈,直接返回报错 */
			return false;

		*e = S->data[--S->top1];
	}
	else if (StackNumber == 2)	/* 共享栈2 */
	{
		if (StackEmpty(*S, 2))	/* 如果是空栈,直接返回报错 */
			return false;
		
		*e = S->data[S->top2++];
	}
	
	return true;
}


/* 获得栈的长度操作 */
int StackLength(SeqDoubleStack S, int StackNumber)
{
	if (StackNumber == 1)		/* 共享栈1 */
		return S.top1;
	else if (StackNumber == 2)	/* 共享栈2 */
		return MAXSIZE - S.top2;
}


/* 清空栈操作 */
void ClearStack(SeqDoubleStack *S, int StackNumber)
{
	if (StackNumber == 1)		/* 共享栈1 */
		S->top1 = 0;
	else if (StackNumber == 2)
		S->top2 = MAXSIZE;




}
