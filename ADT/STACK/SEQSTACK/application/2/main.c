/**********************************************************************
*	文件名: main.c
*
*	文件描述: 将一个十进制数字转化成任意进制
*
*	创建人: Astrol	2011-10-12 19:56:50
*
*	版本号: 1.0
*
*	修改记录:
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "SeqStack.h"

int main(int argc, char *argv[])
{
	unsigned int value; 	/* 十进制数 */
	int num;		/* 进制数 */

	printf("Please input a value(>0):");
	scanf("%u", &value);
	printf("Please input a num(>0):");
	scanf("%d", &num);
	
	if(!Conversion(value, num))
		exit(0);
	
	return 0;
}
	
