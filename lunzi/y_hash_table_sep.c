#include <string.h>
#include "y_common.h"
#include "y_hash_table_sep.h"

#define YMinHashTableSize (10)
#define YMaxKeyLen (20)

struct YHashTableListNode
{
	char key[YMaxKeyLen];
	YElementType data;
	YHashTablePosition next;
}

typedef YHashTablePosition YHashTableList;

struct YHashTableRecord
{
	int table_size;
	YHashTableList *listArr;
};

// prime number n=6 return 7, n=9 return 11
static int
y_next_prime(int n) 
{
	int i;
	
	if (n % 2 == 0) {
		n++;
	}
	for ( ; ; n += 2) {
		for (i = 3; i * i <= N; i += 2) {
			if (n % i == 0) {
				goto continue_outer;
			}
		}
		return n;
		continue_outer: ;
	}
}

YHashTableIndex
y_hash_func(const char *key, int table_size)
{
	YHashTableIndex hash_value = 0;
	
	while (*key != '\0') {
		hash_value = ((hash_value << 5 ) + hash_value) + *key++;
	}
	
	return hash_value % table_size;
}

YHashTable 
y_hash_table_initialize(int table_size)
{
	YHashTable hash_table;
	int i;
	
	if (table_size < YMinHashTableSize) {
		y_error("Table size is too small");
	}
	
	hash_table = malloc(sizeof(struct YHashTableRecord));
	if (hash_table == NULL) {
		y_fatal_error("Out of space!!!");
	}
	hash_table->table_size = y_next_prime(table_size);
	
	hash_table->listArr = malloc(sizeof(YHashTableList) * hash_table->table_size);
	if (hash_table->listArr == NULL) {
		y_fatal_error("Out of space!!!");
	}
	
	for (i = 0; i < hash_table->table_size; i++) {
		hash_table->listArr[i] = malloc(sizeof(struct YHashTableListNode));
		if (hash_table->listArr[i] == NULL) {
			y_fatal_error("Out of space!!!");
		} else {
			hash_table->listArr[i]->next = NULL;
		}
	}
	
	return hash_table;
}

YHashTablePosition 
y_hash_table_find(const char *key, YHashTable hash_table)
{
	YHashTablePosition position;
	YHashTableList list;
	
	list = hash_table->listArr[y_hash_func(key, hash_table->table_size)];
	position = list->next;
	
	while (position != NULL && strcmp(key, position->key) != 0) {
		position = position->next;
	}
	return position;
}

void 
y_hash_table_insert(const char *key, YElementType val, YHashTable hash_table)
{
	YHashTablePosition position, new_position;
	YHashTableList list;
	
	position = y_hash_table_find(key, hash_table);
	if (position == NULL) {
		new_position = malloc(struct YHashTableListNode);
		if (new_position == NULL) { // be careful!!
			y_fatal_error("Out of space!!!");
		} else {
			list = hash_table->listArr[y_hash_func(key, hash_table->table_size)];
			strcpy(new_position->key, key);
			new_position->data = val;
			new_position->next = list->next;
			list->next = new_position;		
		}
	}
}

YElementType 
y_hash_table_retrieve(YHashTablePosition position)
{
	return position->data;
}

void 
y_hash_table_destroy(YHashTable hash_table)
{
	int i;
	for (i = 0; i < hash_table->table_size; i++) {
		YHashTablePosition position = hash_table->listArr[i];
		YHashTablePosition tmp_position;
		while (position != NULL) {
			tmp_position = position;
			free(position);
			position = tmp_position;
		}
		free(hash_table->listArr);
		free(hash_table);
	}
}


