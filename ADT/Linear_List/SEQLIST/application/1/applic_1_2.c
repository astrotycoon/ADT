/*********************************************************************
*	文件名: applic_1_2.c
*
*	文件描述: 实现如果在顺序表A中出现的元素,在顺序表B中也出现,则将
*			顺序表A中得该元素删除
*
*	创建人: Astrol  2011年9月5日
*
*	版本号: 1.2
*
*	修改记录: 	
*		2011-9-6 10:29:46
*		其实Show_Elem(SeqList *);函数完全没必要,应该使用SeqList.h
*		中定义的ListTraverse()函数更方便些
*		因为函数ListTraverse()参数中有一个函数指针,所以
*		再建立一个Show_Elem()函数
**********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "SeqList.h"


void Insert_Elem(SeqList *, int);  /* 为顺序表插入元素函数声明 */
void Show_Elem(DataType);
void DelElem(SeqList *A, SeqList B); /* 删除A中出项的B中的元素的函数声明 */
extern int compare(DataType, DataType);

int main(int argc, char *argv[])
{
	int i, j;
	SeqList A;	/* 声明顺序表A和B */
	SeqList B;

	InitList(&A);	/* 初始化顺序表A和B */
	InitList(&B);

     
	Insert_Elem(&A, 10); /* 将1~10插入顺序表A */  
	Insert_Elem(&B, 5); /* 将1~5插入顺序表B */	

	printf("顺序表A中的元素: \n");	/* 输出顺序表A中的每个元素 */
	ListTraverse(A, Show_Elem);

	printf("\n顺序表B中的元素: \n");  /* 输出顺序表B中的每个元素 */
	ListTraverse(B, Show_Elem);

	putchar('\n');

	printf("将在A中出项B的元素删除后A的元素: \n");
	DelElem(&A, B);  /* 将在顺序表A中出现B的元素删除 */
   	ListTraverse(A, Show_Elem);
	
	putchar('\n');

	return 0;
}

/*====================================================================
*	操作目的: 为顺序表插入元素
*
*	初始条件: 线性表L已存在
*
*	操作结果: 为顺序表插入元素
*
*	函数参数:
*		SeqList *L	线性表L
*		int length	要插入多少元素,0< length < LISTSIZE
*
*	返回值:	
*		无
======================================================================*/
void Insert_Elem(SeqList *L, int length)
{	
	int i;
	for(i = 0; i < length; i++)
	{
		if(ListInsert(L, i + 1, i + 1) == false ) /* 检查插入是否成功 */
		{
			fprintf(stderr, "插入错误!\n");
			exit(EXIT_FAILURE);
		}
	}
}

void Show_Elem(DataType n)
{
	printf("%4d",n);
}


void DelElem(SeqList *A, SeqList B)
{
	int i, pos;
	DataType e;

	for(i = 0; i < B.length; i++)
	{
		if(GetElem(B, i + 1, &e)) /* 依次把B中的每个元素取出来 */
		{
			if( (pos = LocateList(*A, e, compare )) >= 1)
				ListDelete(A, pos, &e );
		}

	}

}
