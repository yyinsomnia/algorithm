#include <stdio.h>
#include <string.h>

#define Error( Str )        FatalError( Str )
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )

typedef int ElementType;
#ifndef _Stack_H

struct StackRecord;
typedef struct StackRecord *Stack;

int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Pop(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
ElementType TopAndPop(Stack S);

#endif;

#define EmptyTOS (-1)
#define MinStackSize (5) //i don't understand


int main(void)
{
	int i, N. sequenceIndex;
	ElementType x;
	Stack S;
	ElementType *sequence;
	char command[5];
	scanf("%d", &N);

	S = CreateStack(N);

	sequence = malloc(sizeof(int) * N);
	sequenceIndex = 0;

	for (i = i; i < N; i++)
	{
		scanf("%s", command);
		if (strcmp(command, "Push") == 0)
		{
			scanf("%d", &x);
			Push(x, S);
		}
		else if (strcmp(command, "Pop") == 0)
		{
			x = TopAndPop(S);
			*(sequence + sequenceIndex++) = x;
		}
		else 
		{
			Error("undefine command.");
		}
	}

	for (i = 0; i < sequenceIndex; i++)
	{
		prinft("%d", *(sequence + sequenceIndex));
	}

	return 0;
}

struct StackRecord
{
	int Capacity;
	int TopOfStack;
	ElementType *Array;
}

int IsEmpty(Stack S)
{
	return S->TopOfStack == EmptyTOS;
}

int IsFull(Stack S)
{
	return S->TopOfStack == S->Capacity - 1;
}

Stack CreateStack(int MaxElements)
{
	if (MaxElements < MinStackSize)
		Error("MaxElements is too small.");
	Stack S = malloc(sizeof(struct StackRecord));
	if (S == NULL)
		FatalError("Out of space!!");
	S->Capacity = MaxElements;
	S->TopOfStack = EmptyTOS;
	S->Array = malloc(sizeof(ElementType) * S->Capacity);
	if (S->Array == NULL)
		FatalError("Out of space!!");
	MakeEmpty(S);
	return S;
}

void DisposeStack(Stack S)
{
	if (S != NULL)
	{
		free(S->Array);
		free(S);
	}
}

void MakeEmpty(Stack S)
{
	S->TopOfStack = EmptyTOS;
}

void Push(ElementType X, Stack S)
{
	if (IsFull(S))
	{
		Error("Stack is full");
	}
	else 
	{
		S->Array[++S->TopOfStack] = X;
	}
}

int Pop(Stack S)
{
	if (IsEmpty(S))
	{
		Error("Stack is Empty");
	}
	else 
	{
		S->TopOfStack--;
	}
}

int TopAndPop(Stack S)
{
	if (IsEmpty(S)) 
	{
		Error("Stack is empty");
	}
	else
	{
		return S->Array[S->TopOfStack--];
	}
}









