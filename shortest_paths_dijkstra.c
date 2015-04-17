/**
 * the first problem is how to store the DAG with weight.
 * define the vertex number is n and edge number is m.
 * so we can use the two-dimensional matrix to store it.
 *
 */

 unsigned int **p_weight;
 unsigned int *p_shortest;
 unsigned int *p_priority_queue;
 unsigned int *p_priority_queue_count;
 int *p_prev;
 int *p_n;
 int *p_m;

 unsigned int *dijkstra(unsigned int **weight, int n, int m, int s, int t) //what will it be if I start the queue from 1 but not 0?
 {
 	//init 
 	p_weight = weight;

 	unsigned int shortest[n] = {0xFFFFFFFF};
 	shortest[s] = 0;
 	p_shortest = shortest;

	int prev[n] = {-1};
	p_prev = prev;
 	
 	unsigned int priority_queue[n];
 	p_priority_queue = priority_queue;
 	unsigned int priority_queue_count = 0;
 	p_priority_queue_count = &priority_queue_count;
 	int i = n;
 	while (i--) {
 		insert_priority_queue(i);
 	}

 	int doudou;
 	while ((doudou = extract_priority_min()) != -1) {
 		int *row = *(p_weight + doudou);
 		for (i = 0; i < n; i++) {
 			if (*(row + i) > 0) {
 				int shortest_before_relax = shortest[i];
 				relax(doudou, i);
 				if (shortest[i] < shortest_before_relax) {
 					decrease_priority_queue();
 				}
 			}
 		}
 	}


 }


 void insert_priority_queue(unsigned int n)
 {
 	*(p_priority_queue + (*p_priority_queue_count++)) = n;
 }

 int extract_priority_min()
 {
 	int min = 0xFFFFFFFF;
 	int min_index = 0;
 	int count = *p_priority_queue_count;
 	if (count == 0) {
 		return -1;
 	}

 	int i = count;
 	while (i--) {
 		if (*(p_shortest + i) <= min) {
 			min = *(p_shortest + i);
 			min_index = i;
 		}
 	}
 	//until now I find that use the unsigned int if I move the element, the vertex's index will change
 	//aaaaaaaaa!
 	//no no no it's ok the key changed but the value is the vertex
 	for (i = min_index; i < count; i++) {
 		*(p_priority_queue + i) = *(p_priority_queue + i + 1);
 	}
 	*p_priority_queue_count--;
 	return min;
 }


 void decrease_priority_queue()
 {

 }

 void relax (unsigned int u, unsigned int v) 
 {
 	if (*(p_shortest + u) + *(*(p_weight + u) + v) < *(p_shortest + v)) {
 		*(p_prev + v) = u;
 		*(p_shortest + v) = *(p_shortest + u) + *(*(p_weight + u) + v);
 	}

 }