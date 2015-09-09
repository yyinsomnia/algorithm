struct YSListNode;
typedef struct YSListNode *YPtrSListNode;
typedef YPtrSListNode YSList;
typedef YPtrSListNode YSListPosition;

YSList y_slist_make_empty(YSList list);

int y_slist_is_empty(YSList list);

int y_slist_is_last(YSListPosition position, YSList list);

YSListPosition y_slist_find(YElementType data, YSList list);

YSListPosition y_slist_find_prev(YElementType data, YSList list);

void y_slist_insert(YElementType data, YSList list, YSListPosition position);

void y_slist_delete(YElementType data, YSList list);

void y_slist_delete_list(YSList list);

YSListPosition y_slist_header(YSList list);

YSListPosition y_slist_first(YSList list);

YSListPosition y_slist_advance(YSListPosition position);

YElementType y_slist_retrieve(YSListPosition position);

YSList y_slist_reverse(YSList list);