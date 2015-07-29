#include <stdio.h>

struct Node;
typedef struct Node *PtrNode

#ifndef _List_H

#endif

#ifndef _Graph_H

typedef struct graph *Graph;

Graph CreateGraph(int n);
void DisposeGraph(Graph g);
void AddEdgeToGraph(Graph g, int source, int purpose);





#endif

struct Node 
{
	int Id;
	Node *Next;
};


void SDS()
{

}