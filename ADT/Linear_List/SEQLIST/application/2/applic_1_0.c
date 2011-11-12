/*********************************************************************
*	文件名: applic_1_0.c
*
*	文件描述: 顺序表A和顺序表B的元素都是非递减排列,利用线性表的基
*		本运算,将他们合并成一个顺序表C,要求C中的元素也是非递
*		减排列
*
*	创建人: Astrol 2011年9月6日
*
*	修改记录:
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "SeqList.h"

extern int compare(DataType, DataType);
void Insert_Elem(SeqList *, int *, int);
void Show_Elem(DataType);
void MergeList(LinkList, LinkList, LinkList);/* 合并函数声明 */


int main(int argc, char *argv[])
{
	int a[] = {6, 11, 15, 16, 18};
	int b[] = {2, 10, 12, 12};
	SeqList A, B, C;

	InitList(&A);
	InitList(&B);
	InitList(&C);/* 初始化三个顺序表 */	

	Insert_Elem(&A, a, sizeof(a) / sizeof(int) );/* 将a数组元素插入A顺序表 */
	Insert_Elem(&B, b, sizeof(b) / sizeof(int) );/* 将b数组元素插入B顺序表 */

	printf("顺序表A中的元素: \n");/* 输出顺序表A中的每个元素 */
	ListTraverse(A, Show_Elem);

	printf("\n顺序表B中的元素: \n");/* 输出顺序表B中的每个元素 */
	ListTraverse(B, Show_Elem);

	putchar('\n');
	
	MergeList(&A, &B, &C);	

	printf("将在A和B合并成C中的元素: \n");/* 将A和B中的元素合并 */
	ListTraverse(C, Show_Elem);

	printf("\n顺序表C的长度为%d \n", C.length);
	putchar('\n');

	return(0);
}

/*====================================================================
*       操作目的: 为顺序表插入元素
*
*       初始条件: 线性表L已存在
*
*       操作结果: 为顺序表插入元素
*
*       函数参数:
*               SeqList *L      线性表L
*               int length      要插入多少元素,0< length < LISTSIZE
*
*       返回值:
*               无
======================================================================*/
void Insert_Elem(SeqList *L, int *array,  int length)
{
        int i;
        for(i = 0; i < length; i++)
        {
                if(ListInsert(L, i + 1, *(array + i)) == false ) /* 检查插入是否成功 */
                {
                        fprintf(stderr, "插入错误!\n");
                        exit(EXIT_FAILURE);
                }
        }
}

void Show_Elem(DataType n)
{
        printf("%6d",n);
}


/*=====================================================================
*	操作目的: 将顺序表A和顺序表B按要求合并成顺序表C
*
*	初始条件: 三个顺序表都存在,a_length > b_length
*
*	操作结果: 成功得到符合要求的顺序表C
*
*	函数参数:
*		LinkList A	顺序表A
*		LinkList B 	顺序表B
*		LinkList C	顺序表C
*	
*	返回值:
*		无
======================================================================*/
void MergeList(LinkList A, LinkList B, LinkList C)
{
	int a_length, b_length; /* 顺序表A和B的长度 */
	int i, n, m;
	DataType e, p;

	a_length = ListLength(*A);
	b_length = ListLength(*B);

	i = 1;
	n = 0;
	m = 0;

	while(n < a_length && m < b_length && GetElem(*A, n+1, &e) && GetElem(*B, m+1, &p) )
	{
		/* 如果取元素成功 */
		if(e < p) /* 如果e<p,插入e,否则插入p */
		{
			ListInsert(C, i, e);
			n++;
		}
		else
		{
			ListInsert(C, i, p);
			m++;
		}
	
		i++;/* 插入下一个位置 */
	}

	if(n == a_length)/* 说明顺序表A比顺序表B短 */
	{
		for(i = 1; i <= b_length - a_length; i++)
		{
			if( GetElem(*B, a_length+i, &e) )
			{
				ListInsert(C, 2*a_length+i, e);
			}
		}
	
	}	

	if(m == b_length)/* 说明顺序表A比顺序表B长 */
	{
		for(i = 1; i <= a_length - b_length; i++)
		{
			if( GetElem(*A, b_length+i, &e) )
			{
				ListInsert(C, 2*b_length+i, e);
			}
		}

	}

}

