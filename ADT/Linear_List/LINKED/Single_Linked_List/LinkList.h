/*********************************************************************
*	文件名: LinkList.h
*
*	文件描述: 线性表(带头结点的单链表)头文件
*
*	创建人: Astrol  2011-9-10 10:13:07
*
*	版本号: 1.0 
*
*	修改记录:
**********************************************************************/

#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include <stdbool.h>  	/* C99特性 */

typedef int DataType;  	/* DataType类型根据实际情况而定,这里假设为int */
typedef struct Node
{
	DataType data;
	struct Node *next; /* 指向后继元素 */
}ListNode, *LinkList;	/* LinkList为指向ListNode的指针 */

/* 单链表的基本操作 */

/*====================================================================
*	操作目的: 初始化单链表
*
*	初始条件: 无
*
*	操作结果: 建立一个空单链表,为头结点分配存储空间,头结点的指针域
*			为空
*
*	函数参数: 
*		LinkList *head	待初始化的单链表
*
*	返回值: 
*		无
======================================================================*/
void InitList(LinkList *head);


/*====================================================================
*	操作目的: 判断单链表是否为空
*
*	初始条件: 单链表head已存在
*	
*	操作结果: 若L为空表,则返回true,否则返回false
*
*	函数参数: 
*		LinkList head	待判断的单链表
*
*	返回值:
*		bool 是否为空
======================================================================*/
bool ListEmpty(LinkList head);


/*====================================================================
*	操作目的: 得到单链表的第i个元素
*
*	初始条件: 单链表head已存在,1<= i <=ListLength(head)
*
*	操作结果: 用e返回head中第i个数据元素的值
*
*	函数参数:
*		LinkList head	单链表head
*		int i		数据元素的位置
*		DataType *e	第i个数据元素的值
*	返回值:
*		bool	操作是否成功
======================================================================*/
bool GetElem(LinkList head, int i, DataType *e);


/*====================================================================
*       操作目的: 得到单链表指定元素的结点指针
*
*       初始条件: 单链表head已存在
*
*       操作结果: 返回head中第一个与e满足关系compare()的数据元素的位序
*                       若这样的元素不存在返回false
*
*       函数参数:
*               LinkList head 	线性表head
*               DataType e      数据元素e
*               int (*fp)(DataType, DataType) 用于比较关系的函数指针
*
*       返回值:
*               LinkList     与e满足关系compare()的数据元素的结点指针
*               符合compare()关系返回0,否则返回-1
======================================================================*/
LinkList LocateList(LinkList head, DataType e, int (*fp)(DataType, DataType) );


/*====================================================================
*       操作目的: 得到单链表指定元素的位置
*
*       初始条件: 单链表head已存在
*
*       操作结果: 返回head中第一个与e满足关系compare()的数据元素的位序
*                       若这样的元素不存在返回false
*
*       函数参数:
*               LinkList head 	线性表head
*               DataType e      数据元素e
*               int (*fp)(DataType, DataType) 用于比较关系的函数指针
*
*       返回值:
*               int     与e满足关系compare()的数据元素的位置
*               符合compare()关系返回0,否则返回-1
======================================================================*/
int LocatePos(LinkList head, DataType e, int (*fp)(DataType, DataType) );


/*====================================================================
*       操作目的: 在单链表的指定位置插入节点,插入位置i表示在第i个元素
*                       之前插入
*
*
*       初始条件: 单链表head已存在, 1<= i <= ListLength(L) + 1
*
*       操作结果: 在head中第i个位置之前插入新的数据元素e,head的长度加+1
*
*       函数参数:
*               LinkList *head	单链表head
*               int i           插入位置
*               DataType e      待插入的数据元素
*
*       返回值:
*               bool    操作是否成功
======================================================================*/
bool ListInsert(LinkList *head, int i, DataType e);


/*====================================================================
*       操作目的: 删除单链表的第i个结点
*
*       初始条件: 单链表head已存在且非空,1<= i <= ListLength(head)
*
*       操作结果: 删除head的第i个数据元素,并用e返回其值, head的长度减1
*
*       函数参数:
*               LinkList *head	单链表head
*               int i           删除位置
*               DataType *e     被删除的数据元素的值
*
*       返回值:
*               bool    操作是否成功
======================================================================*/
bool ListDelete(LinkList *head, int i, DataType *e);


/*====================================================================
*       操作目的: 得到单链表的长度
*
*       初始条件: 单链表head已存在
*
*       操作结果: 返回head中数据元素的个数
*
*       函数参数:
*               LinkList head	单链表head
*
*       返回值:
*               int     数据元素的个数
======================================================================*/
int ListLength(LinkList head);


/*====================================================================
*       操作目的: 清空单链表
*
*       初始条件: 单链表head已存在
*
*       操作结果：将head置为空表
*
*       函数参数：
*               LinkList *head      线性表L
*
*       返回值:
*               无
======================================================================*/
void ClearList(LinkList *head);


/*====================================================================
*       操作目的: 遍历单链表
*
*       初始条件: 单链表head已存在
*
*       操作结果: 依次对head的每个元素调用函数fp
*
*       函数参数:
*               LinkList head	单链表head
*               void (*fp)(DataType) 访问每个数据元素的函数指针
*
*       返回值:
*               无
======================================================================*/
void ListTraverse( LinkList head, void (*fp)(DataType) );

#endif
