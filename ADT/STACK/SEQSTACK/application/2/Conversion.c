/**********************************************************************
*	文件名: Conversion.c
*
*	文件描述: 将一个10进制数转化成任意进制数
*
*	创建人: Astrol	2011-10-12 19:43:15
*
*	版本号: 1.0
*
*	修改记录:
**********************************************************************/

#include "SeqStack.h"

bool Conversion(unsigned int value, int num)
{
	/* 定义一个栈并初始化,用于存储余数 */
	SeqStack S;
	InitStack(&S);
	SDataType e;

	while (value > 0)
	{
		if (!PushStack(&S, value % num))		
			return false;

		value /= num;	
	}
	/* 依次出栈 */
	while (!StackEmpty(S))
	{
		if (PopStack(&S, &e))
			printf("%d", e);
		else
			return false;
	}
	
	putchar('\n');
	return true;
}
