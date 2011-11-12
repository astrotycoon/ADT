/**********************************************************************
*	文件名: applic_1_0.c
*
*	文件描述: 利用链栈的基本运算,通过输入将字符进栈,然后输出其出栈
*			次序
*
*	创建人: Astrol 	2011-10-12 16:04:20
*
*	版本号: 1.0
*
*	修改记录:
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"

void err_exit(char *);	/* 出错处理函数 */
int main(int argc, char *argv[])
{
	LinkStack S;
	SDataType a[] = {'a', 'b', 'c', 'd', 'e'};
	SDataType e;
	int i;

	/* 初始化链栈 */
	InitStack(&S);

	/*入栈 */
	for (i = 0; i < sizeof(a) / sizeof(SDataType); i++)
	{
		if (!PushStack(&S, a[i]))
			err_exit("分配内存出错\n");
	}
	
	printf("当前栈顶元素是:");
	if (GetTop(S, &e))
		printf("%4c", e);
	else
		err_exit("栈已空\n");

	putchar('\n');

	printf("当前栈中的元素个数是: %d\n", StackLength(S));

	/* 顺序出栈 */
	printf("元素出栈的序列是:");
	while (!StackEmpty(S))
	{
		PopStack(&S, &e);
		printf("%4c", e);
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
