/**********************************************************************
*	文件名: applic_1_0.c
*
*	文件描述: 有两个循环单链表,头指针分别是head1和head2,实现算法将
*	链表head2连接在head1之后,连接后的链表仍是循环链表的形式
*
*	创建人: Astrol 2011-10-29 19:02:00
*
*	版本号: 1.0
*
*	修改记录：
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "CirList.h"

void Insert_Elem(p_CirList, DataType *, int);/* 插入元素函数声明 */
void err_exit(char *);	/* 出错处理函数 */
void Show_Elem(DataType);
p_CirList Merge(p_CirList, p_CirList);	/* 合并函数声明 */

int main(int argc, char *argv[])
{
	DataType a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9,};
	DataType b[] = {10, 11, 12, 13, 14, 15};
	DataType e;

	CirList A;	/* 声明循环链表A和B */
	CirList B;
	p_CirList C = NULL;

	InitList(&A);	/* 初始化 */
	InitList(&B);
	C = &A;

	/* 插入元素 */
	Insert_Elem(&A, a, sizeof(a) / sizeof(DataType));
	Insert_Elem(&B, b, sizeof(b) / sizeof(DataType));

	printf("循环链表A中有%d个元素\n", ListLength(A));
	ListTraverse(A, Show_Elem);
	
	putchar('\n');

	printf("循环链表B中有%d个元素\n", ListLength(B));
	ListTraverse(B, Show_Elem);

	puts("\n\n");

	if (GetElem(&A, 8, &e))
		printf("循环链表A第8个元素是%4d\n", e);
	
	if (GetElem(&B, 5, &e))
		printf("循环链表B第5个元素是%4d\n", e);
	putchar('\n');

	printf("删除链表B最后一个元素\n");
	ListDelete(&B, 6, &e);
	ListTraverse(B, Show_Elem);

	putchar('\n');

	C = Merge(&A, &B);	/* 合并 */
	
	printf("合并后的链表有%d个元素\n", ListLength(*C));
	ListTraverse(*C, Show_Elem);	

	putchar('\n');
	
	if (GetElem(C, 14, &e))
		printf("合并后的链表第14个元素是%4d\n", e);

	ClearList(&A);
	ClearList(&B);
	
	putchar('\n');
	
	exit(EXIT_SUCCESS);
}

void Insert_Elem(p_CirList list, DataType *pDaTy, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (ListInsert(list, i, *(pDaTy + i)) == false)
			err_exit("插入错误");
	}

}

void err_exit(char *err_str)
{
	perror(err_str);
	exit(EXIT_FAILURE);
}

void Show_Elem(DataType e)
{
	printf("%4d", e);
}


p_CirList Merge(p_CirList A, p_CirList B)
{	/* 去掉A的tail, 去掉B的head */
	p_CirList CirList_Ret = NULL;
	
	CirList_Ret = A;

	A->tail->prev->next = B->head->next;
	B->tail->next = A->head;
	A->tail = B->tail;
	A->size += B->size;	/* 差点忘了 */
	free(A->tail);
	free(B->head);

	return CirList_Ret;
}

int compare(DataType e, DataType n)
{
	if (e == n)
		return 0;
	else -1;
}
