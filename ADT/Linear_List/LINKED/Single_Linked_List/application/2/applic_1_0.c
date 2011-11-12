/*********************************************************************
*	文件名: applic_1_0.c
*
*	文件描述: 存在两个单链表A和B, 其中的元素都是非递减排列, 编写
*		算法合并单链表A和B得到单链表C, 表C中元素的值按照非递
*		减排列. 要求表C利用原来表A和B的结点空间,不申请额外空间
*
*	创建人: Astrol 2011-9-19 16:12:48
*
*	修改记录:
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

void Insert_Elem(LinkList, DataType *, int);  /* 插入元素函数声明 */
void Show_Elem(DataType); 
void MergeList(LinkList, LinkList, LinkList *); /* 合并函数声明 */

int main(int argc, char **argv)
{
	DataType a[] = {6, 7,  9, 14, 37, 45, 65, 67};
	DataType b[] = {3, 7, 11, 34, 45, 89};
	
	/* 声明单链表A,B,C */
	LinkList A = NULL;
	LinkList B = NULL;
	LinkList C = NULL;
	
	/* 初始化单链表A,B */
	InitList(&A);
	InitList(&B);

	/* 为单链表插入元素 */
	Insert_Elem(A, a, sizeof(a) / sizeof(DataType));
        Insert_Elem(B, b, sizeof(b) / sizeof(DataType));

	printf("单链表A中有%d个元素\n", ListLength(A) );
        ListTraverse(A, Show_Elem);
        printf("\n单链表A长度为: %d\n", ListLength(A) );

	printf("\n单链表B中有%d个元素\n", ListLength(B) );
        ListTraverse(B, Show_Elem);
        printf("\n单链表B长度为: %d\n", ListLength(B) );

	putchar('\n');

	MergeList(A, B, &C);/* 将A和B中的元素合并成C */

	printf("将在A和B合并成C中的元素: \n");
	ListTraverse(C, Show_Elem);
	printf("\n单链表C长度为: %d\n", ListLength(C) );

	putchar('\n');

	/* 释放单链表 */
	ClearList(&C);
	A = NULL;
	B = NULL;
	C = NULL;

	exit(EXIT_SUCCESS);
}

void Insert_Elem(LinkList A, DataType *pDaTy, int n)
{
        int i;

        for(i = 0; i < n; i++)
        {       /* 检查输入是否成功 */
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

void MergeList(LinkList A, LinkList B, LinkList *C)
{
	DataType e, p;
	int i = 1;
	int k = 1;
	LinkList pList_A = NULL;
	LinkList pList_B = NULL;
	LinkList pList_C = NULL;


	pList_A = A->next; 	/* pList_A指向A的第一个结点 */
	pList_B = B->next; 	/* pList_B指向B的第一个结点 */

	*C = A; 		/* C指向表A头结点 */
	(*C)->next = NULL;  	/* 初始化表C */
	pList_C = *C;     	/* pList_C指向C的第一个结点 */

	while(pList_A && pList_B) /* while(pList_A != NULL && pList_B != NULL) */
	{
		if(pList_A->data <= pList_B->data)/* 如果pList_A->data <= pList_B->data,
							 插入pList_A,否则插入pList_B->data*/
		{
			pList_C->next = pList_A;
			pList_C = pList_A;
			pList_A = pList_A->next;
		}
		else
		{
			pList_C->next = pList_B;
			pList_C = pList_B;
			pList_B = pList_B->next;
		}
	}

	pList_C->next = pList_A ? pList_A : pList_B;i; /* 将剩余的结点插入C中 */
	free(B); /* 释放B的头结点 */
}
