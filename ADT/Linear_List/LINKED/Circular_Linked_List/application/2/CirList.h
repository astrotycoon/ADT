/**********************************************************************
*	文件名: CirList.h
*
*	文件描述: 循环单链表(带头结点)头文件
*
*	创建人: Astrol 2011-10-17 20:34:11
*
*	版本号: 1.0
*
*	修改记录:
**********************************************************************/

#ifndef __CIRLIST_H__
#define __CIRLIST_H__

#include <stdbool.h>	/* C99特性 */

typedef int DataType;	/* DataType类型根据实际情况而定,这里假设为int */

/* 循环单链表结构定义 */
typedef struct _CirNode
{
	DataType data;
	struct _CirNode* prev;	/* 直接前驱指针 */
	struct _CirNode* next; 	/* 直接后继指针 */
}CirNode, *p_CirNode;

typedef struct _CirList
{
	p_CirNode head;		/* 指向表头 */
	p_CirNode tail;		/* 指向表尾 */
	int size;		/* 元素个数 */
}CirList,*p_CirList;

/* 循环单链表的各种操作 */

/* 初始化操作 */
void InitList(p_CirList list);

/* 判断是否为空 */
bool ListEmpty(CirList list);

/* 得到循环链表的第i个元素 */
bool GetElem(p_CirList list, int i, DataType* e);

/* 得到循环单链表指定元素的结点指针 */
p_CirNode LocateList(CirList list, DataType e, int (*fp)(DataType, DataType));

/* 得到循环链表指定元素的位置 */
int LocatePos(CirList list, DataType e, int (*fp)(DataType, DataType));

/* 插入操作 */
bool ListInsert(p_CirList list, int i, DataType e);

/* 删除操作 */
bool ListDelete(p_CirList list, int i, DataType* e);

/* 得到循环链表的长度 */
int ListLength(CirList list);

/* 清空循环链表 */
void ClearList(p_CirList list);

/* 遍历链表 */
void ListTraverse(CirList list, void (*fp)(DataType));
#endif	/* __CIRLIST_H__ */
