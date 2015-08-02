#include <stdio.h>

typedef int graphElementT;
typedef int Vertex;
typedef struct graphCDT *graphADT;

vertexTag * GraphAddVertex(graphElementT t);
edgeTag * GraphAddEdge();

graphADT GraphCreate();
GraphDestroy(graphADT g);


typedef struct vertexTag 
{
	graphElementT element;
	struct edgeTag *edges;
	struct vertexTag *next;
} vertexT;


typedef struct edgeTag 
{
	struct vertexTag *connectsTo;
	DistType	Dist;
	PriceType   Price;
	struct edgeTag *next;
} edgeT;

typedef struct graphCDT
{
	vertexT *vertices;
} graphCDT;


typedef int DistType;
typedef int PriceType;

struct TableEntry
{
	List		Header;
	char 		Know;
	DistType	Dist;
	PriceType   Price;
	Vertex 		Path;

};

struct TableAdjacentNode
{
	DistType				EdgeLen;
	PriceType 				Price;
	PtrTableAdjacentNode  	Next;
}

#define NotAVertext (-1)
typedef struct TableEntry Table[NumVertex];




graphADT GraphCreate()
{
	
}


void 
InitTable(Vertex Start, Graph G, Table T)
{
	int i;

	ReadGraph(G, T);
	for (i = 0; i < NumVertex; i++)
	{
		T[i].Know = False;
		T[i].Dist = Infinity;
		T[i].Price = Infinity;
		T[i].Path = NotAVertext;
	}
	T[Start].Dist = 0;
	T[Start].Price = 0;
}

void
PrintPath(Vertex V, Table T)
{
	if (T[V].Path != NotAVertext)
	{
		PrintPath(T[V].Path, T);
		printf(" to");
	}
	printf("%d", V);
}

void Dijkstra(Table T)
{
	Vertex V,W;
	List L;
	Position P;
	DistType TmpDist;

	for ( ; ; )
	{
		V = FindSmallestUnknowDistanceV();
		if (V == NotAVertext)
			break;
		T[V].Know = True;

		P = ListFirst(T[V].Header);
		while (P != NULL)
		{
			if (!T[P->Vertex].Know)
			{
				TmpDist = T[V].Dist + P->EdgeLen;
				if (TmpDist < T[P->Vertex].Dist) 
				{
					T[P->Vertex].Dist = TmpDist;
					T[P->Vertex].Price = T[V].Price + P->Price;
					T[P->Vertex].Path = V;
				} 
				else if (TmpDist == T[P->Vertex].Dist)
				{
					if (T[V].Price + P->Price < T[P->Vertex].Price)
					{
						T[P->Vertex].Dist = TmpDist;
						T[P->Vertex].Price = T[V].Price + P->Price;
						T[P->Vertex].Path = V;
					}
				}
			}
			P = P->Next;
		}
	}

}




