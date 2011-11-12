/*********************************************************************
*	文件名: applic_1_0.c
*
*	文件描述: 利用单链表的基本运算,实现如果在单链表A中出现的元素,
*		在单链表B中也出现,则将单链表A中的该元素删除
*
*	创建人: Astrol  2011-9-11 21:28:12
*
*	版本号: 1.0
*
*	修改记录:
**********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

void Insert_Elem(LinkList, DataType *, int);/* 插入元素函数声明 */
void Show_Elem(DataType);
void DelElem(LinkList, LinkList);/* 删除A中出现的B中的元素的函数声明 */
static int compare(DataType, DataType);
LinkList ReversalList_first(LinkList list);
LinkList ReversalList_second(LinkList* list);

int main(int argc, char *argv[])
{
	DataType a[] = {2, 3, 6, 7, 9, 14, 56, 45, 65, 67};
	DataType b[] = {3, 4, 7, 11, 34, 54, 45, 67};

	LinkList A;  /* 声明单链表A和B */
	LinkList B;
	LinkList C;

	InitList(&A);/* 初始化单链表A和B */
	InitList(&B);

	Insert_Elem(A, a, sizeof(a) / sizeof(DataType));
	Insert_Elem(B, b, sizeof(b) / sizeof(DataType));/* 为单链表插入元素 */

	printf("单链表A中有%d个元素\n", ListLength(A) );
	ListTraverse(A, Show_Elem);

	printf("\n单链表B中有%d个元素\n", ListLength(B) );
	ListTraverse(B, Show_Elem);

	putchar('\n');
	
	DelElem(A, B);/* 将在单链表A中出现的B的元素删除 */
	printf("将在A中出现B的元素删除后A的元素: \n");
	ListTraverse(A, Show_Elem);

	putchar('\n');
	putchar('\n');
	C = ReversalList_first(A);
	ListTraverse(C, Show_Elem);

	putchar('\n');
	putchar('\n');
	C = ReversalList_second(&B);
	ListTraverse(C, Show_Elem);
	putchar('\n');

	free(A);
	free(B);
	A = NULL;
	B = NULL;

	return 0;
}

void Insert_Elem(LinkList A, DataType *pDaTy, int n)
{
	int i;

	for(i = 0; i < n; i++)
	{	/* 检查输入是否成功 */
		if(ListInsert(&A, i+1, *(pDaTy + i)) == false)
		{
			fprintf(stderr, "插入错误!\n");
			exit(EXIT_FAILURE);
		}
	}



}

void Show_Elem(DataType n)
{
	printf("%4d", n);
}

void DelElem(LinkList A, LinkList B)
{
	int i, pos;
	DataType e;

	for(i = 0; i < ListLength(B); i++)
	{
		if(GetElem(B, i+1, &e))/* 依次把B中的每个元素取出来 */
		{
			if(pos = (LocatePos(A, e, compare)) != 0);
				ListDelete(&A, pos, &e);	
		}
	}
}

static int compare(DataType n, DataType m)
{
	if(n == m)
		return 0;
	else
		return -1;

}

/* 反转链表1 */
LinkList ReversalList_first(LinkList list)
{
	LinkList list_ret = NULL;
	LinkList tmp = NULL;
	LinkList p = NULL;

	if (list == NULL)
		return NULL;

	if ((list_ret = (LinkList)malloc(sizeof(ListNode))) == NULL)
		return NULL;

	list_ret->next = NULL;
	tmp = list->next;	/* tmp指向list首节点 */
	p = list->next;
	
	while (p != NULL)	/* 用p遍历链表list */
	{
		p = p->next;
		tmp->next = list_ret->next;
		list_ret->next = tmp;
		tmp = p;
	}
	
	return list_ret;
}

/* 反转链表2 */
LinkList ReversalList_second(LinkList* list)
{
	if (NULL == *list)
		return NULL;

	LinkList list_last = NULL;	/* 指向尾结点的指针 */
	LinkList tmp = NULL;

	for (list_last = *list; list_last->next != NULL; list_last = list_last->next);	/* 现在指向尾结点 */

	for (tmp = (*list)->next; tmp != list_last; tmp = (*list)->next)
	{
		(*list)->next = tmp->next;
		tmp->next = list_last->next;
		list_last->next = tmp;
	}
	
	return *list;
}
