/*********************************************************************
*	文件名: LinkList.c
*
*	文件描述: 实现单链表的操作函数
*
*	创建人: Astrol  2011-9-10 14:43:59
*
*	版本号: 1.3
*
*	修改记录:
*
* (一)	2011-9-10 18:43:08
*	将函数ListInsert()中
*	
*	while(p)
*	{
*		if(k != i)
*		{
*			p = p->next;
*			k++;
*		}
*		else
*		{
*			q = (LinkList)malloc(sizeof(ListNode));
*			q->data = e;			      
*			q->next = p->next;		     
*			p->next = q;			    
*			return true;
*		}
*	}
*改成如下:
*	while( p && k < i)
*	{
*		p = p->next;
*		k++;
*	}
*	
*	if( !p || k > i)
*		return false;
*	
*	q = (LinkList)malloc(sizeof(ListNode));
*	q->data = e;			       
*	q->next = p->next;		       
*	p->next = q;			       
*
*	return true;
*改变原因: 改变前每次循环都要比较k和i的值,很浪费资源
*	   改变后一次性到达i处,省去了比较的过程
*
* (二)	2011-9-10 18:54:50
*	将函数ListInsert()中
*	if(i < 1 || i > ListLength(*head) + 1)
*改变如下:
*	if(i < 1 || i > ListLength(*head))
*改变原因:单链表不像顺序表
*
* (三)	2011-9-10 19:29:54
*	将函数GetElem()、ListInsert()和ListDelete()中的
*	if(i < 1 || i > ListLength(*head))删除
*改变原因
*	while(p && k < i)之后的if( !p || k > i)已解决了这个问题
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "LinkList.h"

/* 初始化单链表 */
void InitList(LinkList *head)
{
	if( (*head = (LinkList)malloc(sizeof(ListNode))) == NULL )
		exit(-1);
	(*head)->next = NULL; /* 动态生成一个头结点,并且指针域为空 */
}

/* 判断单链表是否为空 */
bool ListEmpty(LinkList head)
{
	if(head->next == NULL)/* 判断单链表的指针域是否为空 */
		return true;  /* 为空返回true,否则返回false */
	else
		return false;
}

/* 得到单链表的第i个元素 */
bool GetElem(LinkList head, int i, DataType *e)
{
	assert(head->next != NULL);
	
	LinkList p = NULL;
	int k;

	p = head->next;/* p指向第一个结点 */
	k = 1;         /* k是计时器 */

//	if(i < 1 || i > ListLength(head))
//		return false; /* 参数有误 */

	while(p && k < i) /* while( p != NULL && k < i)*/
	{
		p = p->next; /* p指向下一个结点 */
		k++;
	}
	
	if( !p || k > i)
		return false; /* 第i个元素不存在 */
	*e = p->data;  /* 获取第i个元素 */
	
	return true;
}

/* 得到单链表指定元素的节点指针 */
LinkList LocateList(LinkList head, DataType e, int (*fp)(DataType, DataType) )
{
	assert(head->next != NULL);
	
	LinkList p = NULL;

	p = head->next; /* p指向第一个结点 */

	while(p) /* while(p != NULL) */
	{
		if( 0 == (*fp)(e, p->data) ) /* 如果符合条件返回结点p */
			return p;
		else
			p = p->next;
	}

	return NULL;	
}


/* 得到单链表指定元素的位置 */
int LocatePos(LinkList head, DataType e, int (*fp)(DataType, DataType) )
{
	assert(head->next != NULL);

	LinkList p = NULL;
	int i;

	p = head->next;
	i = 1;

	while(p) /* while(p != NULL) */
	{
		if( 0 == (*fp)(e, p->data)) /* 如果符合条件返回结点p */
			return i;
		else
		{
			p = p->next;
			i++;
		}	
	}

	return 0;
} 

/* 在单链表的指定位置插入指定元素 */
//bool ListInsert(LinkList *head, int i, DataType e)
//{
//	assert((*head)->next != NULL);

//	LinkList p = NULL;
//	LinkList q = NULL;
//	int k;
//
//	if(i < 1 || i > ListLength(*head) + 1)
//	if(i < 1 || i > ListLength(*head))
//		return false;
//
//	p = (*head)->next; /* p指向第一个结点 */
//	p = *head; /* p指向第一个结点 */
//	k = 1;		/* k为计数器 */
//
//	while(p) /* while(p != NULL) */
//	{
//		if(k != i)
//		{
//			p = p->next;
//			k++;
//		}
//		else
//		{
//			q = (LinkList)malloc(sizeof(ListNode));/* 为q分配空间 */
//			q->data = e;			       /* 为q->data赋值 */
//			q->next = p->next;		       /* 新插入的元素q的指针域指向下一个元素 */
//			p->next = q;			       /* p指向新插入的元素 q*/
//			return true;
//		}
//	}
//	while( p && k < i)/* 寻找第i个结点 */
//	while( p->next && k < i)/* 寻找第i个结点 */
//	{
//		p = p->next;
//		k++;
//	}
//	
//	if( !p || k > i)
//	if( !(p->next) || k > i)
//		return false;
//	
//	if((q = (LinkList)malloc(sizeof(ListNode))) == NULL);/* 为q分配空间 */
//		exit(-1);
//	q->data = e;			       /* 为q->data赋值 */
//	q->next = p->next;		       /* 新插入的元素q的指针域指向下一个元素 */
//	p->next = q;			       /* p指向新插入的元素 q*/
//
//	return true;
//}	

/* 删除单链表的第i个结点 */
bool ListDelete(LinkList *head, int i, DataType *e)
{
	assert((*head)->next != NULL);

	LinkList p = NULL;
	LinkList q = NULL;
	int k;

//	if(i < 1 || i >　ListLength(*head))
//		return false;

	p = (*head)->next; /* p指向第一个结点 */
	k = 1;             /* k为计数器 */

	
	while( p && k < i - 1) /* 寻找第i-1个结点 */
	{
		p = p->next;
		k++;
	}
	
	if( !p || k > i -1)
		return false;
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);

	return true;
}

/* 得到单链表的长度 */
int ListLength(LinkList head)
{
	assert(head->next != NULL);

	LinkList p = NULL;
	int count;

	p = head->next;  /* p指向第一个结点 */
	count = 0;

	while(p)
	{
		p = p->next;
		count++;
	}
	
	return count;
}	

/* 清空单链表 */
void ClearList(LinkList *head)
{
	assert((*head)->next != NULL);

	LinkList p = NULL;
	LinkList q = NULL;

	p = (*head)->next; /* p指向第一个结点 */
	
	while(p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	
	(*head)->next = NULL; /* 头结点指针域为空 */
}

/* 遍历单链表 */
void ListTraverse( LinkList head, void (*fp)(DataType) )	
{
	assert(head->next != NULL);

	LinkList p = NULL;

	p = head->next;  /* p指向第一个结点 */

	while(p)
	{
		(*fp)(p->data);
		p = p->next;
	}
}


bool ListInsert(LinkList *head, int i, DataType e)
{
	assert(*head != NULL);

	LinkList p = NULL;
	LinkList q = NULL;
	int k;
	
	p = *head;
	k = 1;

	while(p->next && k > 1)
	{
		p = p->next;
		k++;
	}

	if(p || k > i)
		return false;
	if( (q = (LinkList)malloc(sizeof(ListNode))) == NULL)	
		exit(-1);

	q->data = e;
	q->next = p->next;
	p->next = q;

	return true;
}
