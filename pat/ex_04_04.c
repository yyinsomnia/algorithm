#include <stdio.h>
#include <stdlib.h>

#define Error( Str )        FatalError( Str )
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )

typedef int ElementType;

#ifndef _AvlTree_H

struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

AvlTree MakeEmpty(AvlTree T);
Position Find(ElementType X, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(ElementType X, AvlTree T);
AvlTree Delete(ElementType X, AvlTree T);
ElementType Retieve(Position P);
#endif 

struct AvlNode
{
	ElementType Element;
	AvlTree Left;
	AvlTree Right;
	int Height;
};

static int Max(int x, int y)
{
	return x >= y ? x : y;
}

static int Height(Position P)
{
	if (P == NULL) 
	{
		return -1;
	}
	else
	{
		return P->Height;
	}
}

static Position SingleRotateWithLeft(Position K2)
{
	Position K1;
	K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;
	K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Height = Max(Height(K1->Left), K2->Height) + 1;

	return K1;
}

static Position SingleRotateWithRight(Position K2)
{
	Position K1;
	K1 = K2->Right;
	K2->Right = K1->Left;
	K1->Left = K2;
	K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Height = Max(K2->Height, Height(K1->Right)) + 1;

	return K1;
}

static Position DoubleRotateWithLeft(Position K3)
{
	K3->Left = SingleRotateWithRight(K3->Left);
	return SingleRotateWithLeft(K3);
}

static Position DoubleRotateWithRight(Position K3)
{
	K3->Right = SingleRotateWithLeft(K3->Right);
	return SingleRotateWithRight(K3);
}


int main(void)
{
	int N, ele, i;
	AvlTree T;
	T = NULL;
	scanf("%d", &N);
	for (i = 0; i < N; i ++) {
		scanf("%d", &ele);
		T = Insert((ElementType) ele, T);
	}

	printf("%d", T->Element);
	return 0;
}

AvlTree MakeEmpty(AvlTree T)
{
	if (T != NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;	
}

Position Find(ElementType X, AvlTree T)
{
	if (T == NULL)
	{
		return NULL;
	}
	else if (X < T->Element)
	{
		return Find(X, T->Left);
	}
	else if (X > T->Element)
	{
		return Find(X, T->Right);
	}
	else
	{
		return T;
	}
}

Position FindMin(AvlTree T)
{
	if (T != NULL)
	{	
		while (T->Left != NULL)
		{
			T = T->Left;
		}
	}
	
	return T;
}

Position FindMax(AvlTree T)
{
	if (T == NULL)
	{
		return NULL;
	}
	else if (T->Right == NULL)
	{
		return T;
	}
	else
	{
		return FindMax(T->Right);
	}
}

AvlTree Insert(ElementType X, AvlTree T)
{
	if (T == NULL)
	{
		T = malloc(sizeof(struct AvlNode));
		if (T == NULL) {
			FatalError("Out of space!");
		}
		T->Element = X;
		T->Left = T->Right = NULL;
		T->Height = 0;
	}
	else if (X < T->Element)
	{
		T->Left = Insert(X, T->Left);
		if (Height(T->Left) - Height(T->Right) == 2)
		{
			if (X < T->Left->Element)
				T = SingleRotateWithLeft(T);
			else
				T = DoubleRotateWithLeft(T);
		}
	}
	else if (X > T->Element)
	{
		T->Right = Insert(X, T->Right);
		if (Height(T->Right) - Height(T->Left) == 2)
		{
			if (X > T->Right->Element)
				T = SingleRotateWithRight(T);
			else
				T = DoubleRotateWithRight(T);
		}
	}
	else 
	{
		;
	}

	T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
	return T;
}











