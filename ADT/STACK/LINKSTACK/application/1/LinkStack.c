/**********************************************************************
*	文件名: LinkStack.c 
*
*	文件描述: 实现链栈操作函数
*
*	创建人: Astrol 	2011-10-11 22:42:54
*
*	版本号: 1.0
*
*	修改记录:
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"

/* 链栈的初始化操作 */
void InitStack(LinkStack *Stop)
{
	Stop->top = NULL;
	Stop->count = 0;	/* 栈为空时,栈元素个数为0 */
}


/* 判断单链表是否为空 */
bool StackEmpty(LinkStack Stop)
{
	/* 可以判断Stop.top是否等于NULL,也可以判断Stop.count是否等于0 */
	if (NULL == Stop.top)
		return true;
	else
		return false;
}		


/* 取栈顶元素操作 */
bool GetTop(LinkStack Stop, SDataType *e)
{
	if (StackEmpty(Stop))	/* 如果是空栈,直接返回报错 */
		return false;	

	*e = Stop.top->data;
	
	return true;
}


/* 进栈操作 */
bool PushStack(LinkStack *Stop, SDataType e)
{
	LinkStackPtr s = NULL;	/* s为要添加的新节点 */
	if((s = (LinkStackPtr)malloc(sizeof(StackNode))) == NULL)
		return false;

	s->data = e;	/* 将e元素添加到新节点 */
	s->next = Stop->top;	/* 将当前栈顶指针赋给新节点的指针域*/
			    	/* 使栈顶元素成为新节点的后继元素 */
	Stop->top = s;	 	/* 将新的节点赋值给栈顶指针 */

	Stop->count++;		/* 栈元素个数增加 */

	return true;
}


/* 出栈操作 */
bool PopStack(LinkStack *Stop, SDataType *e)
{
	LinkStackPtr s = NULL;

	if (StackEmpty(*Stop))
		return false;	/* 如果是空栈,直接返回报错 */
	
	s = Stop->top;		/* s指向栈顶 */
	*e = Stop->top->data;	/* *e=s->data将栈顶元素的data赋值给e */
	Stop->top = Stop->top->next;	/* 栈顶元素指向后续元素 */
	Stop->count--;			/* 栈元素个数减少 */
	
	free(s);	

	return true;
}

 /* 获得栈的长度操作 */
int StackLength(LinkStack Stop)
{
	return Stop.count;
}

/* 清空栈操作 */
void ClearStack(LinkStack *Stop)
{
	LinkStackPtr s = NULL;
	
	while (Stop->top)
	{
		s = Stop->top;
		Stop->top = Stop->top->next;
		free(s);
	}
}

