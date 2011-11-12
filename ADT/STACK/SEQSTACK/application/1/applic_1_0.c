/**********************************************************************
*	文件名: applic_1_0.c
*
*	文件描述: 将元素a b c d e 依次进栈,然后将d和e出栈,再将f和g进栈,
*		最后将元素全部出栈,并将元素按照出栈次序输出
*
*	创建人: Astrol	2011-10-11 14:52:23
*
*	版本号: 1.0
*
*	修改记录:
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "SeqStack.h"

void err_exit(char *);	/* 出错处理函数 */

int main(int argc, char *argv[])
{
	SeqStack S;	/* 定义一个栈 */
	SDataType a[] = {'a', 'b', 'c', 'd', 'e'};
	SDataType e;
	int i;

	InitStack(&S);
	/* 入栈 */
	for (i = 0; i < sizeof(a) / sizeof(SDataType); i++)
	{
		if (!PushStack(&S, a[i]))
			err_exit("栈已满\n");
	}
	
	printf("出栈的元素是:");
	if (PopStack(&S, &e))
		printf("%4c", e);	/* 元素e出栈 */
	else
		err_exit("栈已空\n");

	if (PopStack(&S, &e))
		printf("%4c", e);	/* 元素d出栈 */
	else
		err_exit("栈已空\n");


	putchar('\n');

	printf("当前栈顶元素是:");
	if (GetTop(S, &e))
		printf("%4c", e);
	else
		err_exit("栈已空\n");
	putchar('\n');

	/* 将f g入栈 */
	if (!PushStack(&S, 'f'))
		err_exit("栈已满\n");
	if (!PushStack(&S, 'g'))
		 err_exit("栈已满\n");

	printf("当前栈中的元素个数是: %d\n", StackLength(S));

	printf("元素出栈的次序是:");
	while (!StackEmpty(S))
	{
		PopStack(&S, &e); /* 因为已在while循环中,所以无需担心是不是空栈*/
		printf("%4c", e);
	}
	
	putchar('\n');
	
	exit(EXIT_SUCCESS);
}

void err_exit(char *str)
{
	fprintf(stderr, str);
	exit(EXIT_FAILURE);
}
