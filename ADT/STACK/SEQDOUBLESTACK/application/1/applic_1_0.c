/**********************************************************************
*	文件名: applic_1_0.c
*
*	文件描述: 设有两个栈S1和S2都采用顺序栈的方式存储,并且共享一个存
*	储区。为了尽可能利用存储空间,减少溢出的可能,采用栈顶相向,迎面增
*	长的方式,试设计S1和S2有关入栈和出栈的算法
*
*	创建人: Astrol	2011-10-11 20:52:53
*
*	版本号: 1.0
*
*	修改记录:
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "SeqDoubleStack.h"

void err_exit(char *);	/* 出错处理函数 */

int main(int argc, char *argv[])
{
	SeqDoubleStack S;	/* 定义一个共享栈 */
	SDataType e1, e2;
	SDataType a[] = {'a', 'b', 'c', 'd', 'e'};
	SDataType b[] = {'x', 'y', 'z', 'r'};
	int i;

	/* 初始化共享栈 */
	InitStack(&S);

	/* 将数组a的元素压入第一个共享栈 */
	for (i = 0; i < sizeof(a) / sizeof(SDataType); i++)
	{
		if (!PushStack(&S, a[i], 1))	
			err_exit("栈已满\n");
	}

	/* 将数组b的元素压入第二个共享栈 */
	for (i = 0; i < sizeof(b) / sizeof(SDataType); i++)
	{
		if (!PushStack(&S, b[i], 2))	
			err_exit("栈已满\n");
	}

	/* 分别取共享栈的栈顶元素 */
	if (!GetTop(S, &e1, 1))
		err_exit("栈已空\n");
	if (!GetTop(S, &e2, 2))
		err_exit("栈已空\n");

	printf("栈1的栈顶元素是: %4c, 栈2的栈顶元素是: %4c\n", e1, e2);

	printf("栈1元素出战次序:");
	while (!StackEmpty(S, 1))
	{
		PopStack(&S, &e1, 1);
		printf("%4c", e1);
	}
	
	putchar('\n');
	printf("栈2元素出战次序:");
	while (!StackEmpty(S, 2))
	{
		PopStack(&S, &e2, 2);
		printf("%4c", e2);
	}
	
	putchar('\n');
	
	exit(EXIT_SUCCESS);
}


/* 出错处理函数 */
void err_exit(char *str)
{
	fprintf(stderr, str);
	exit(EXIT_FAILURE);
}	
