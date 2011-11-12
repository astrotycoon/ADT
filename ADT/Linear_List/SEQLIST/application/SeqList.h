/*********************************************************************
*	文件名: SeqList.h
*
*	文件描述: 顺序表头文件
*
*	创建人: Astrol  2011年9月4日
*
*	版本号: 1.0
*	
*	修改记录: 			
**********************************************************************/

#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include <bool.h>	/* C99特性 */

#define LISTSIZE 100	/* 存储空间初始分配量 */
typedef int DataType;	/* DataType类型根据实际情况而定,这里假设为int */
typedef struct
{
	DataType list[LISTSIZE];
	int length;	/* 线性表当前长度 */
}SeqList;

typedef SeqList * LinkList; /* LinkList为指向顺序表的指针 */

/* 顺序表的基本操作 */

/*====================================================================
*	操作目的: 初始化顺序表
*
*	初始条件: 无
*
*	操作结果: 建立一个空的线性表
*
*	函数参数: 
*		SeqList *L	带初始化的线性表
*	
*	返回值: 无
======================================================================*/
void InitList(SeqList *L);

/*====================================================================
*	操作目的: 判断顺序表是否为空
*
*	初始条件: 线性表L已存在
*
*	操作结果: 若L为空表, 则返回true, 否则返回false
*
*	函数参数:
*		SeqList L 待判断的线性表
*
*	返回值:
*		bool 是否为空
======================================================================*/
bool ListEmpty(SeqList L);

/*====================================================================
*	操作目的: 得到顺序表的第i个元素
*
*	初始条件: 线性表L已存在, 1<= i <= ListLength(L)
*
*	操作结果: 用e返回L中第i个数据元素的值
*
*	函数参数: 
*		SeqList L	线性表L
*		int i		数据元素的位置
*		DataType *e	第i个数据元素的值
*
*	返回值:
*		bool 操作是否成功
======================================================================*/
bool GetElem(SeqList L, int i, DataType *e);

/*====================================================================
*	操作目的: 得到顺序表指定元素的位置
*
*	初始条件: 线性表L已存在
*
*	操作结果: 返回L中第一个与e满足关系compare()的数据元素的位序
*			若这样的元素不存在返回false
*		
*	函数参数: 
*		SeqList L	线性表L
*		DataType e	数据元素e
*		int (*fp)(DataType, DataType) 用于比较关系的函数指针
*
*	返回值:
*		int 	与e满足关系compare()的数据元素的位序
*		符合compare()关系返回0,否则返回-1
======================================================================*/
int LocateList(SeqList L, DataType e, int (*fp)(DataType, DataType) );

/*====================================================================
*	操作目的: 在顺序表的指定位置插入节点,插入位置i表示在第i个元素
*			之前插入
*
*
*	初始条件: 线性表L已存在, 1<= i <= ListLength(L) + 1
*
*	操作结果: 在L中第i个位置之前插入新的数据元素e,L的长度加+1
*
*	函数参数: 
*		SeqList *L 	线性表L
*		int i		插入位置
*		DataType e	待插入的数据元素
*
*	返回值:
*		bool	操作是否成功
======================================================================*/
bool ListInsert(SeqList *L, int i, DataType e);

/*====================================================================
*	操作目的: 删除顺序表的第i个结点
*
*	初始条件: 线性表L已存在且非空,1<= i <= ListLength(L)
*
*	操作结果: 删除L的第i个数据元素,并用e返回其值, L的长度减1
*
*	函数参数:
*		SeqList *L	线性表L
*		int i		删除位置
*		DataType *e	被删除的数据元素的值
*
*	返回值:
*		bool	操作是否成功
======================================================================*/
bool ListDelete(SeqList *L, int i, DataType *e);

/*====================================================================
*	操作目的: 得到线性表的长度
*
*	初始条件: 线性表L已存在
*
*	操作结果: 返回L中数据元素的个数
*
*	函数参数:
*		SeqList L	线性表L
*
*	返回值:
*		int 	数据元素的个数
======================================================================*/
int ListLength(SeqList L);

/*====================================================================
*	操作目的: 清空顺序表
*
*	初始条件: 线性表L已存在
*
*	操作结果：将L置为空表
*
*	函数参数：
*		SeqList *L 	线性表L
*
*	返回值:
*		无
======================================================================*/
void ClearList(SeqList *L);

/*====================================================================
*	操作目的: 得到线性表指定数据元素的前驱
*
*	初始条件: 线性表L已存在
*
*	操作结果: 若cur_e是L的数据元素，且不是第一个,则用pre_e返回它的
*			前驱,否则操作失败,pre_e无定义
*
*	函数参数:
*		SeqList L	线性表L
*		DataType cur_e	数据元素cur_e
*		DataType *pre_e	前驱数据元素
*
*	返回值:
*		bool	操作是否成功
=======================================================================*/
bool PriorElem(SeqList L, DataType cur_e, DataType *pre_e);

/*=====================================================================
*	操作目的: 得到线性表指定数据元素的后继
*
*	初始条件: 线性表L已存在
*
*	操作结果: 若cur_e是L的数据元素,且不是最后一个,则用next_e返回它的
*			后继,否则操作失败,pre_e无定义
*
*	函数参数:
*		SeqList L	线性表L
*		DataTyoe cur_e 	数据元素cur_e
*		DataType *pre_e 后继数据元素
*
*	返回值:
*		bool	操作是否成功
========================================================================*/
bool NextElem(SeqList L, DataType cur_e, DataType *pre_e);

/*======================================================================
*	操作目的: 遍历顺序表
*
*	初始条件: 线性表L已存在
*
*	操作结果: 依次对L的每个元素调用函数fp
*
*	函数参数:
*		SeqList L	线性表L
*		void (*fp)(DataType) 访问每个数据元素的函数指针
*
*	返回值:
*		无
========================================================================*/
void ListTraverse(SeqList L, void (*fp)(DataType) );	
#endif
