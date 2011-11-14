#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/* on error, NULL is returned. Othersize the pointer to the new list_node */
extern list_node_t* list_node_create(void* data)
{
	list_node_t* node_ret = NULL;

	if ((node_ret =(list_node_t *)malloc(sizeof(list_node_t))) == NULL)
	{
		errno = ENOMEM;
		return NULL;
	}

	node_ret->data = data;
	node_ret->prev = NULL;
	node_ret->next = NULL;
	
	return node_ret;
}

/* on error, NULL is returned. Othersize the pointer to the new list */
extern list_t* list_create(void)
{
	list_t* list_ret = NULL;

	if ((list_ret = (list_t *)malloc(sizeof(list_t))) == NULL)
	{
		errno = ENOMEM;
		return NULL;
	}

	list_ret->len = 0;
	list_ret->head = NULL;
	list_ret->tail = NULL;
	list_ret->destroy = NULL;
	list_ret->mathc = NULL;
	list_ret->show = NULL;

	return list_ret;
}

extern void list_destroy(list_t* list)
{
	if (NULL == list)
	{
		errno = EINVAL;
		return;
	}

	size_t len = list->len;;
	list_node_t* next = NULL;
	list_node_t* current = list->head;

	while (len--)
	{
		next = current->next;
		if (list->destroy)
		{
			list->destroy(current->data);
		}
		LIST_FREE(current);
		current = next;
	}
	LIST_FREE(list);
}

extern list_node_t* list_prepend(list_t* list, list_node_t* node)
{
	if (NULL == list || NULL == data)
	{
		errno = EINVAL; 
		return NULL;
	}

	if (list->len)
	{
		node->next = list->head;
		node->prev = NULL;
		list->head->prev = node;
		list->head = node;
	}
	else
	{
		list->head = list->tail = node;
		node->prev = node->next = NULL;	
	}
	
	++list->len;

	return node;
}
	
extern list_node_t* list_append(list_t* list, list_node_t* node)
{
	if (NULL == list || NULL == node)
	{
		errno = EINVAL;
		return NULL;
	}

	if (list->len)
	{
		node->next = NULL;
		node->prev = list->tail;
		list->tail->next = node;
		list->tail = node;
	}
	else
	{
		list->head = list->tail = node;
		node->prev = node->next = NULL;
	}
	
	++list->len;
	
	return node;

}

/* insert data into list "list" in the order after "node", if "node" is NULL
 * the data is inserted as the head */
extern bool list_insert_node_at_front(list_t* list, list_node_t* node, const void* data)
{
	if (NULL == list)
	{
		errno = EINVAL;
		return false;
	}

	list_node_t* newnode = NULL;
	if ((newnode = (list_node_t *)malloc(list_node_t)) == NULL)
	{
		errno = ENOMEM;
		return false;
	} 
	newnode->data = data;

	if (node)
	{
		
	}
	else
	{}
	++list->len;
	return false;
	

}
