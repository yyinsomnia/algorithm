#include <stdio.h>
#include <stdlib.h>


typedef struct _graph_struct graph;
typedef struct _graph_struct *graph_p;

typedef struct _queue_struct queue;

#define INFINITE (32767)

queue *queue_create(int N);
void queue_destory(queue *q);
graph *queue_en(queue *q, int ele);
int queue_de(queue *q);
int is_queue_empty(queue *q);
int is_queue_full(queue *q);


graph *graph_create(int N);
void graph_destory(graph *g);
graph *graph_insert_edge(graph *g_ptr, int soure, int sink);

static int locate(int start, int offset, int size)
{
	int index = start + offset;
	if (size > index) {
		return index;
	} else {
		return index - size;
	}
}

struct _graph_struct
{
	int vertex_num;
	int edge_num;
	
	int **matrix;
	
};

struct _queue_struct
{
	int capacity;
	int head;
	int tail;
	int size;
	int *Array;
};


queue *queue_create(int N)
{
	queue *q = malloc(sizeof(struct _queue_struct));
	q->capacity = N;
	q->head = 1;
	q->tail = 0;
	q->size = 0;
	q->Array = malloc(sizeof(int) * N);
}


void queue_destory(queue *q)
{
	free(q->Array);
	free(q);
}

queue *queue_empty(queue *q)
{
	q->head = 1;
	q->tail = 0;
	q->size = 0;
}


graph *queue_en(queue *q, int ele)
{
	int tail;
	if (is_queue_full(q)) {
		printf("Error, Queue Full!");
		exit(0);
	}
	q->tail = locate(q->tail, 1, q->capacity);
	q->Array[q->tail] = ele;
	q->size++;
}


int queue_de(queue *q)
{
	if (is_queue_empty(q)) {
		printf("Error, Queue Empty!");
		exit(0);
	}
	int res = q->Array[q->head];
	q->head = locate(q->head, 1, q->capacity);
	q->size--;
	return res;
}

int is_queue_empty(queue *q)
{
	return q->size == 0;
}

int is_queue_full(queue *q)
{
	return q->size == q->capacity;
}

graph *graph_create(int N)
{
	int i, j;
	graph_p g_ptr = malloc(sizeof(struct _graph_struct));
	g_ptr->vertex_num = N;
	g_ptr->edge_num = 0;
	g_ptr->matrix = malloc(sizeof(int *) * N);
	for (i = 0; i < N; i++) {
		g_ptr->matrix[i] = malloc(sizeof(int) * N);
	}
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (i == j) {
				g_ptr->matrix[i][j] = 0;
			} else {
				g_ptr->matrix[i][j] = INFINITE;
			}
		}
	}

	return g_ptr;
}

void graph_destory(graph *g_ptr)
{
	free(g_ptr->matrix);
	free(g_ptr);
}


graph *graph_insert_edge(graph *g_ptr, int source, int sink)
{
	g_ptr->matrix[source][sink] = 1;
	g_ptr->matrix[sink][source] = 1;
	g_ptr->edge_num++;
	return g_ptr;
}

int graph_edge_visited(int source, int sink, int **visited)
{
	return visited[source][sink];
}

void graph_visit_edge(int source, int sink, int **visited)
{
	visited[source][sink] = 1;
}

int **visited_create(int N)
{
	int A[N][N];
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			A[i][j] = 0;
		}
	}
}

void **visited_destory(int **visited, int N)
{
	int i, j;
	for (i = 0; i < N; i++) {
		free(visited[i]);
	}
	free(visited);
}



int DFS(graph *g_ptr, int source, int *visited, int *component, int component_idx)
{
	int i;
	for (i = 0; i < g_ptr->vertex_num; i++) {
		if (source != i && !visited[i] && g_ptr->matrix[source][i] != INFINITE) {
			component[component_idx++] = i;
			visited[i] = 1;
			component_idx = DFS(g_ptr, i, visited, component, component_idx);
		}
	}
	return component_idx;
}

int BFS(graph *g_ptr, queue *q_ptr, int *visited, int *component, int component_idx)
{
	int i, source;
	if (!is_queue_empty(q_ptr)) {
		source = queue_de(q_ptr);
		for (i = 0; i < g_ptr->vertex_num; i++) {
			if (source != i && !visited[i] && g_ptr->matrix[source][i] != INFINITE) {
				component[component_idx++] = i;
				visited[i] = 1;
				queue_en(q_ptr, i);
			}
		}
		component_idx = BFS(g_ptr, q_ptr, visited, component, component_idx);
	}
	return component_idx;
}



int main(void)
{
	int N, E, i, source, sink, component_idx;
	
	scanf("%d %d", &N, &E);
	
	graph *g_ptr = graph_create(N);
	
	for (i = 0; i < E; i++) {
		scanf("%d %d", &source, &sink);
		graph_insert_edge(g_ptr, source, sink);
	}
	
	
	int visited[N];	
	for (i = 0; i < N; i++) {
		visited[i] = 0;
	}
	
	int component[N];
	
	for (source = 0; source < N; source++) {
		component_idx = 0;
		if (visited[source]) {continue;}
		component[component_idx++] = source;
		visited[source] = 1;
		component_idx = DFS(g_ptr, source, visited, component, component_idx);
		printf("{ ");
		for (i = 0; i < component_idx; i++) {
			printf("%d ", component[i]);
		}
		printf("}");
		printf("\n");
	}
	for (i = 0; i < N; i++) {
		visited[i] = 0;
	}
	queue *q_ptr = queue_create(N);
	for (source = 0; source < N; source++) {
		q_ptr = queue_empty(q_ptr);
		component_idx = 0;
		if (visited[source]) {continue;}
		component[component_idx++] = source;
		visited[source] = 1;
		queue_en(q_ptr, source);
		component_idx = BFS(g_ptr, q_ptr, visited, component, component_idx);
		printf("{ ");
		for (i = 0; i < component_idx; i++) {
			printf("%d ", component[i]);
		}
		printf("}");
		printf("\n");
	}
		
	
	return 0;
}