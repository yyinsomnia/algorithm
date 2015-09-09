typedef unsigned int YHashTableIndex;

struct YHashTableListNode;
typedef struct YHashTableListNode *YHashTablePosition;
struct YHashTableRecord;
typedef struct YHashTableRecord *YHashTable;

YHashTable y_hash_table_initialize(int table_size);

void y_hash_table_destroy(YHashTable hash_table);

YHashTablePosition y_hash_table_find(const char *key, YHashTable hash_table);

void y_hash_table_insert(const char *key, YHashTable hash_table);

YElementType y_hash_table_retrieve(YHashTablePosition position);