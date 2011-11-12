/*********************************************************************
*	文件名: applic_1_1.c
*
*	文件描述: 实现如果在顺序表A中出现的元素,在顺序表B中也出现,则将
*			顺序表A中得该元素删除
*
*	创建人: Astrol  2011年9月5日
*
*	版本号: 1.1
*
*	修改记录: 
*		2011-9-6 9:37:51
*		版本1.0中很多函数是重复的,例如为顺序表插入元素以及输出
*		顺序表元素,完全可以写成单独的函数,用时在调用
*		void Insert_Elem(SeqList *, int);
*		void Show_Elem(SeqList *);
**********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "SeqList.h"


void Insert_Elem(SeqList *, int);  /* 为顺序表插入元素函数声明 */
void Show_Elem(SeqList *);    /* 输出顺序表元素函数声明 */
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
	Show_Elem(&A);
	
	printf("\n顺序表B中的元素: \n");  /* 输出顺序表B中的每个元素 */
	Show_Elem(&B);
      
	putchar('\n');

	printf("将在A中出项B的元素删除后A的元素: \n");
	DelElem(&A, B);  /* 将在顺序表A中出现B的元素删除 */
	Show_Elem(&A);
	
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

/*====================================================================
*	操作目的: 输出顺序表中的元素
*
*	初始条件: 线性表L已存在
*
*	操作结果: 输出了顺序表中的元素
*
*	函数参数:
*		SeqList *L	线性表L
*
*	返回值:
*		无
======================================================================*/
void Show_Elem(SeqList *L)
{
	int i;
	DataType e;
	for(i = 0; i < L->length; i++)
	{
		if(GetElem(*L, i+1, &e) == false)
		{
			fprintf(stderr,"输出失败!\n");
			exit(EXIT_FAILURE);
		}
		printf("%4d", e);
	}
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
