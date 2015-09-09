#include "y_common.h"
#include "y_queue.h"

#define YMinQueueSize (5)

struct YQueueRecord
{
	int capacity;
	int front;
	int rear;
	int size;
	YElementType *arData;
};

int 
y_queue_is_empty(YQueue queue)
{
	return queue->size == 0;
}

int 
y_queue_is_full(YQueue queue)
{
	return queue->size == queue->capacity;
}

YQueue 
y_queue_create(int max_elements)
{
	YQueue queue;
	
	if (max_elements < YMinQueueSize) {
		y_error("Queue size is too small");
	}
	
	queue = malloc(sizeof(struct YQueueRecord));
	if (queue == NULL) {
		y_fatal_error("Out of space!!!");
	}
	queue->arData = malloc(sizeof(YElementType) * max_elements);
	if (queue->arData == NULL) {
		y_fatal_error("Out of space!!!");
	}
	queue->capacity = max_elements;
	y_queue_make_empty(queue);
	
	return queue;
}

void 
y_queue_dispose(YQueue queue)
{
	if (queue != NULL) {
		free(queue->arData);
		free(queue);
	}
}

void 
y_queue_make_empty(YQueue queue)
{
	queue->front = 1;
	queue->rear = 0;
	queue->size = 0;
}

//next index
static int
y_queue_succ(int index, YQueue queue)
{
	if (++index == queue->size) {
		index = 0;
	}
	return index;
}

void 
y_queue_enqueue(YElementType data, YQueue queue)
{
	if (y_queue_is_full(queue)) {
		y_error("Full queue");
	} else {
		//queue->arData[queue->size++] = data; //it's wrong!
		queue->size++;
		queue->rear = y_queue_succ(queue->rear, queue);
		queue->arData[queue->rear] = data;
	}
}

void 
y_queue_dequeue(YQueue queue)
{
	if (y_queue_is_empty(queue)) {
		y_error("Empty queue");
	} else {
		queue->size--;
		queue->front = y_queue_succ(queue->front, queue);
	}
}

YElementType 
y_queue_front(YQueue queue)
{
	if (y_queue_is_empty(queue)) {
		y_error("Empty queue");
	} else {
		return queue->arData[queue->front];	
	}
}

YElementType 
y_queue_front_dequeue(YQueue queue)
{
	YElementType data;
	if (y_queue_is_empty(queue)) {
		y_error("Empty queue");
	} else {
		queue->size--;
		data = queue->arData[queue->front];
		queue->front = y_queue_succ(queue->front, queue);
		
		return data;	
	}
}