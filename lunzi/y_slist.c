#include "y_common.h"
#include "y_slist.h"

struct YSListNode
{
	YElementType data;
	YSListPosition next;
};

YSList 
y_slist_make_empty(YSList list)
{
	if (list != NULL) {
		y_slist_delete_list(list);
	}
	list = malloc(sizeof(struct YSListNode));
	if (list == NULL) {
		y_fatal_error("Out of memory!");
	}
	list->next = NULL;
	return list;
}

int 
y_slist_is_empty(YSList list)
{
	return list->next == NULL;
}


int 
y_slist_is_last(YSListPosition position, YSList list)
{
	return position->next == NULL;
}

YSListPosition 
y_slist_find(YElementType data, YSList list)
{
	YSListPosition position;
	position = list->next;
	
	while (position != NULL && position->data != data) {
		position = position->next;
	}
	return position;
}

YSListPosition 
y_slist_find_prev(YElementType data, YSList list)
{
	YSListPosition prev_position;
	prev_position = list;
	
	while (prev_position->next != NULL && prev_position->next->data != data) {
		prev_position = prev_position->next;
	}
	return prev_position;
}

void 
y_slist_insert(YElementType data, YSList list, YSListPosition position)
{
	YSListPosition tmp_position;
	
	tmp_position = malloc(sizeof(struct YSListNode));
	if (tmp_position == NULL) {
		y_fatal_error("Out of space!!!");
	}
	tmp_position->data = data;
	tmp_position->next = position->next;
	position->next = tmp_position;
}

void 
y_slist_delete(YElementType data, YSList list)
{
	YSListPosition prev_position, tmp_position;
	prev_position = y_slist_find_prev(data, list);
	
	if (!y_sllist_is_last(prev_position, list)) {
		tmp_position = prev_position->next;
		prev_position->next = tmp_position->next;
		free(tmp_position);
	}
}

void 
y_slist_delete_list(YSList list)
{
	YSListPosition position, tmp_position;
	
	position = list->next;
	list->next = NULL
	while (position != NULL) {
		tmp_position = position->next
		free(position);
		position = tmp_position;
	}
}

YSListPosition 
y_slist_header(YSList list)
{
	return list;
}


YSListPosition 
y_slist_first(YSList list)
{
	return list->next;
}

YSListPosition 
y_slist_advance(YSListPosition position)
{
	return position->next;
}

YElementType 
y_slist_retrieve(YSListPosition position)
{
	return position->data;
}

YSList 
y_slist_reverse(YSList list)
{
	YSListPosition prev_position, position, next_position;
	prev_position = NULL;
	position = y_slist_first(list);
	next_position = position->next;
	
	while (position != NULL) {
		position->next = prev_position;
		prev_position = position;
		position = next_position;
		next_position = next_position->next;
	}
	
	list->next = prev_position;
	return list;
}