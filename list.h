#ifndef __LIST_H__
#ifndef __LIST_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifndef LIST_MALLOC
	#define LIST_MALLOC malloc
#endif

#ifndef LIST_FREE
	#define LIST_FREE free
#endif

#include <stddef.h>

/* list_node_t struct */
typedef struct list_node
{
	void* data;
	struct list_node* prev;
	struct list_node* next;
}list_node_t;

/* list_t struct */
typedef struct list
{
	size_t len;
	list_node_t* head;
	list_node_t* tail;
	void (*destroy)(void* data);
	void (*match)(void* data1, void* data2);
	void (*show)(void* data)
}list_t;

/* list_iterator_t direction */
typedef enum
{
	LIST_HEAD,
	LIST_TAIL
}list_direction_t;

/* list_iterator_t struct */
typedef list_iterator
{
	list_node_t* next;
	list_direction_t direction;
}list_iterator_t;

/* list_node_t prototypes */
extern list_node_t* list_node_create(void* data);

/* list_t prototypes */
extern list_t* list_create(void);

extern void list_destroy(list_t* list);

extern list_node_t* list_prepend(list_t* list, list_node_t* node);
extern list_node_t* list_append(list_t* list, list_node_t* node);

extern bool list_insert_node_at_front(list_t* list, list_node_t* node, const void* data);
extern bool list_insett_node_at_later(list_t* list, list_node_t* node, const void* data);
extern bool list_insert_node_at_index(list_t* list, size_t index, const void* data);

extern bool list_delete_node(list_t* list, list_node_t* node);
extern bool list_delete_node_at_index(list_t* list, size_t index);

extern bool list_update_node(list_t* list, list_node_t* dst, list_node_t* src);
extern bool list_update_node_at_index(list_t* list, size_t index, list_node_t* node);

extern list_nodt_t* list_find_by_data(list_t* list, const void* data);
extern list_node_t* list_find_by_index(list_t* list, size_t index);

extern list_node_t* node_get_by_value(list_t* list, void* data);
extern list_node_t* node_get_by_index(list_t* list, size_t index);

/* list_iterater_t prototypes */
extern list_itetator_t* list_iterator_create(list_t* list, list_direction_t direaction);

extern list_iterator_t* list_iterator_create_fome_node(list_node_t* node, list_iterator_t direction);

extern list_node_t* list_iterator_next(list_iterator_t * iterator);

extern void list_iterator_destroy(list_iterator_t * iterator);

#define list_size(list) ((list)->size)
#ifdef __cplusplus
}
#endif
	
#endif	/* __LIST_H__*/
