/*********************************************************************
*	文件名: applic_1_0.c
*
*	文件描述: 实现如果在顺序表A中出现的元素,在顺序表B中也出现,则将
*			顺序表A中得该元素删除
*
*	创建人: Astrol  2011年9月5日
*
*	版本号: 1.0
*
*	修改记录: 
*********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "SeqList.h"

void DelElem(SeqList *A, SeqList B); /* 删除A中出项的B中的元素的函数声明 */
extern int compare(DataType, DataType);

int main(int argc, char *argv[])
{
	int i, j;
	DataType e;
	SeqList A;	/* 声明顺序表A和B */
	SeqList B;

	InitList(&A);	/* 初始化顺序表A和B */
	InitList(&B);

    	for(i = 1; i <= 10; i++) // 将1~10插入顺序表A 
	{
		if(ListInsert(&A, i, i) == false )
		{
			fprintf(stderr, "插入错误!\n");
			exit(EXIT_FAILURE);
		}
	}
	

    	for(i = 1, j = 1; i <= 6; i++,j = j + 2) // 插入顺序表中6个数 
	{
		if(ListInsert(&B, i, j*2) == false)
		{
			fprintf(stderr,"插入失败!\n");
			exit(EXIT_FAILURE);
		}
	}
	

	printf("顺序表A中的元素: \n");	/* 输出顺序表A中的每个元素 */

    	for(i = 0; i < A.length; i++ )
	{
		if(GetElem(A, i+1, &e) == false)
		{
			fprintf(stderr,"输出失败!\n");
			exit(EXIT_FAILURE);
		}
		printf("%4d", e);
	}
	

	printf("\n顺序表B中的元素: \n");  /* 输出顺序表B中的每个元素 */

    	for(i = 0; i < B.length; i++)
	{
		if(GetElem(B, i+1, &e) == false)
		{
			fprintf(stderr,"输出失败!\n");
			exit(EXIT_FAILURE);
		}
		printf("%4d", e);
	}


	putchar('\n');

	printf("将在A中出项B的元素删除后A的元素: \n");
	DelElem(&A, B);  /* 将在顺序表A中出现B的元素删除 */
    	for(i = 0; i < A.length; i++)
	{
		
		if(GetElem(A, i+1, &e) == false)
		{
			fprintf(stderr,"输出失败!\n");
			exit(EXIT_FAILURE);
		}
		printf("%4d", e);
	}

	
	putchar('\n');

	return 0;
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
