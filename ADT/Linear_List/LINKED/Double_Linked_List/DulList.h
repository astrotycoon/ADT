/**********************************************************************
*	文件名: DulList.h
*
*	文件描述: 双向链表的头文件
*
*	创建人: Astrol 2011-10-18 0:01:15
*
*	版本号: 1.0
*
*	修改记录:
**********************************************************************/

#ifndef __DULLIST_H__
#define __DULLIST_H__

#include <stdbool.h>	/* C99特性 */

typedef int DataType;   /* DataType类型根据实际情况而定,这里假设为int */

/* 双向链表结构定义 */
typedef struct DulNode
{
	DataType data;
	struct DulNode *prior;	/* 直接前驱指针 */
	struct DulNode *next;	/* 直接后继指针 */
}DulNode, *DulList;	

/* 双向链表的各种操作 */

/* 双向链表的初始化操作 */
void InitList(DulList *head);

/* 判断双向链表是否为空 */
bool ListEmpty(DulList head);

/* 得到双向链表的第i个元素 */
bool GetElem(DulList head, int i, DataType *e);

/* 得到双向链表指定元素的结点指针 */
DulList LocateList(DulList head, DataType e, int (*fp)(DataType, DataType));

/* 得到双向链表指定元素的位置 */
int LocatePos(DulList head, DataType e, int (*fp)(DataType, DataType));

/* 插入操作 */
bool ListInsert(DulList *head, int i, DataType e);

/* 删除操作 */
bool ListDelete(DulList *head, int i, DataType *e);

/* 得到双向链表的长度 */
int ListLength(DulList head);

/* 清空双向链表 */
void ClearList(DulList *head);

/* 遍历双向链表 */
void ListTraverse(DulList head, void (*fp)(DataType));

#endif	/* __DULLIST_H__ */
