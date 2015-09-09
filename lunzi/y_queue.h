struct YQueueRecord;
typedef struct YQueueRecord *YQueue;

int y_queue_is_empty(YQueue queue);

int y_queue_is_full(YQueue queue);

YQueue y_queue_create(int max_elements);

void y_queue_dispose(YQueue queue);

void y_queue_make_empty(YQueue queue);

void y_queue_enqueue(YElementType data, YQueue queue);

void y_queue_dequeue(YQueue queue);

YElementType y_queue_front(YQueue queue);

YElementType y_queue_front_dequeue(YQueue queue);