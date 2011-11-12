/*********************************************************************
*	文件名: applic_0_1.c
*
*	文件描述: 约瑟夫问题.有n个人,编号为1,2,...n,围成一个圈,按照顺
*	时针方向从编号为k的人从1开始报数,报数为m的人出列,他的下一个人
*	重新开始从1报数,数到m的人出列,如此重复下去,直到所有人都出列.编
*	写一个算法,要求输入n,k和m,按照出列的顺序输出编号
*
*	创建人: Astrol 2011-11-2 19:31:19
*
*	版本号: 1.0
*
*	修改记录:
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "CirList.h"

void err_exit(char *);	/* 出错处理函数 */
void show_elem(DataType);
void Insert_Elem(p_CirList, int, DataType);
DataType clist_trave(p_CirList, int, int);
void eat_line(void);
int get_int(void);

int main(int argc, char *argv[])
{
	int n, k, m;
	int index = 0;
	int list_size;
	DataType num_man;
	DataType e;	

	CirList list_a; /* 声明循环链表 */
	CirList list_b;

	if ((n = atoi(argv[1])) <= 0)
		err_exit("n should bigger than 0!");
	if ((k = atoi(argv[2])) <= 0 || k > n)
		err_exit("k should bigger than 0 and smaller than n");
	if ((m = atoi(argv[3])) <= 0 || m > n)
		err_exit("m should bigger than 0 and smaller than n");

	InitList(&list_a);	/* 初始化 */
	InitList(&list_b);
	
	while (index < n)
	{
		num_man = get_int();
		printf("number:%d\n", index );
		Insert_Elem(&list_a, index, num_man);
		if (++index == 8)
			break;
	}

	printf("=============");
	list_size = list_a.size;

	for (index = 0; index < list_size; index++)
	{
		printf("=============");
		e = clist_trave(&list_a, k, m);
		
		Insert_Elem(&list_b, index, e);
	}	
	
	printf("按出列顺序为:");
	ListTraverse(list_b, show_elem);
	
	ClearList(&list_a);
	ClearList(&list_b);
	
	exit(EXIT_SUCCESS);
}

void err_exit(char *err_str)
{
	perror(err_str);
	exit(EXIT_FAILURE);
}

void Insert_Elem(p_CirList list, int index, DataType number)
{
	if (ListInsert(list, index, number) == false)
		err_exit("insert failed.");
}

void show_elem(DataType e)
{
	printf("%4d", e);
}

DataType clist_trave(p_CirList list, int k, int m)
{
	DataType num_ret;
	int n;
	
	n = (k + m -1) % list->size;	/* 关键 */

	if (ListDelete(list, n, &num_ret) == false)
		err_exit("delete failed.");

	return num_ret;
}

void eat_line(void)
{
	while (getchar() != '\n')
		continue;
}

int get_int()
{
	int input;
	
	while (scanf("%d", &input) != 1)
	{
		eat_line();
		printf("is not an integer.\n");
	}
	
	return input;
}
