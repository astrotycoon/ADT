/*********************************************************************
*	文件名: applic_1_0.c
*
*	文件描述: 串string1 = "Welcome to ", string2 = "China", sub = 
*	"Xi'an", 将string2接在串string1的末尾,然后将串string1中的string2
*	用sub替换
*
*	创建人: Astrol 2011-11-11 0:08:19
*	
*	版本号: 1.0
*
*	修改记录:
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "heapstring.h"

void err_exit(char *);

int main(int argc, char* argv[])
{
	p_heapstring_t string1 = NULL;
	p_heapstring_t string2 = NULL;
	p_heapstring_t sub = NULL;
	p_heapstring_t string = NULL;

	//初始化
	string1 = heapstring_create("Welcome to ");
	string2 = heapstring_create("China");
	sub = heapstring_create("Xi'an");
	string = heapstring_create("");
	if (NULL == string1 || NULL == string2 
		|| NULL == sub ||NULL == string)
	{
		err_exit("create error");
	}
	
	printf("string1->ch = %s\n", string1->ch);
	printf("string1->length = %d\n", string1->length);
	
	printf("\nstring2->ch = %s\n", string2->ch);
	printf("string2->length = %d\n", string2->length);

	printf("\nsub->ch = %s\n", sub->ch);
	printf("sub->length = %d\n", sub->length);

	if (heapstring_cat(string, string1, string2) == false)
	{
		err_exit("cat error");
	}
	
	printf("string->ch = %s\n", string->ch);
	printf("string->length = %d\n", string->length);

	if (heapstring_replace(string, string2, sub) == false)
	{
		err_exit("replace error");
	}
	
	printf("string->ch = %s\n", string->ch);
	printf("string->length = %d\n", string->length);

	heapstring_destroy(string1);
	heapstring_destroy(string2);
	heapstring_destroy(sub);
	heapstring_destroy(string);

	exit(EXIT_SUCCESS);
}

void err_exit(char* err_str)
{
	perror(err_str);
	exit(EXIT_FAILURE);
}
