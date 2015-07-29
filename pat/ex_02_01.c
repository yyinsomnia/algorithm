#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 100000




struct Node;
typedef struct Node *PtrToNode;
void SliceList(PtrToNode List, int N, int SubLen, PtrToNode* Heads);
PtrToNode ReversList(PtrToNode List);
PtrToNode MergeList(PtrToNode *Heads, int fenzu);


struct Node
{
	int ShowAddress;
	int ShowNextAddress;
	int Element;
	PtrToNode Next;
};

int main(void)
{

	int N, SubLen, HeadShowAddress, i, j, ShowAddress, Element,ShowNextAddress;
	PtrToNode A, HeadP, P, Q, Tmp, List;

	scanf("%d %d %d", &HeadShowAddress, &N, &SubLen);
	if (SubLen > N || SubLen <= 0) 
	{
		return 0;
	}
	A = malloc(N * sizeof(struct Node));

	PtrToNode AllPtr[MAX_NUM];

	for (i = 0; i < N; i++)
	{
		Tmp = A + i;
		scanf("%d %d %d", &ShowAddress, &Element, &ShowNextAddress);
		Tmp->ShowAddress = ShowAddress;
		Tmp->Element = Element;
		Tmp->ShowNextAddress = ShowNextAddress;
		Tmp->Next = NULL;
		AllPtr[ShowAddress] = Tmp;
		if (Tmp->ShowAddress < 0)
			return 0;
	}

	P = AllPtr[HeadShowAddress];
	while (P != NULL)
	{
		if (P->ShowNextAddress == -1 || AllPtr[P->ShowNextAddress] == NULL)
		{
			break;
		}
		else
		{
			P->Next = AllPtr[P->ShowNextAddress];
			P = P->Next;
		}
		
	}
	HeadP = AllPtr[HeadShowAddress];

	if (HeadP == NULL)
	{
		return 0;
	}

	Tmp = HeadP;
	for (i = 1; i < N; i++)
	{
		if (Tmp->Next == NULL)
		{	
			N = i;
			Tmp->ShowNextAddress = -1;
			break;
		}
		Tmp = Tmp->Next;
	}
	if (Tmp->ShowNextAddress != -1 || Tmp->Next != NULL || N < SubLen)
	{
		return 0;
	}

	P = HeadP;
	int fenzu, quanfenzu;
	fenzu = quanfenzu = N / SubLen;
	if (N % SubLen != 0) 
	{
		fenzu++;
	}
	if (SubLen > 1)
	{
		PtrToNode *Heads = malloc(fenzu * sizeof(PtrToNode));
		SliceList(HeadP, N, SubLen, Heads);

		for (i = 0; i < quanfenzu; i++)
		{
			Heads[i] = ReversList(Heads[i]);
		}

		List = MergeList(Heads, fenzu);
		free(Heads);
	}
	else 
	{
		List = HeadP;
	}
	

	P = List;


	while (P != NULL)
	{
		if (P->ShowNextAddress != -1)
			printf("%05d %d %05d\n", P->ShowAddress, P->Element, P->ShowNextAddress);
		else
			printf("%05d %d %d\n", P->ShowAddress, P->Element, P->ShowNextAddress);
		P = P->Next;
	}
	free(A);
	return 0;

}

void SliceList(PtrToNode List, int N, int SubLen, PtrToNode* Heads)
{
	int i, j;
	i = 0; j = 0;
	PtrToNode P, Tmp;
	P = List;
	*(Heads + j++) = List;

	while (P != NULL)
	{
		Tmp = P->Next;
		if (Tmp == NULL)
		{
			P->ShowNextAddress = -1;
		}
		else if ((i++) % SubLen == SubLen - 1)
		{
			*(Heads + j++) = Tmp;
			P->Next = NULL;
			P->ShowNextAddress = -1;
		}
		P = Tmp;
	}
}

// the fucking show address!!!
PtrToNode ReversList(PtrToNode List)
{
	PtrToNode Prev, P, Next;
	Prev = List;
	P = Prev->Next;
	Prev->Next = NULL;
	Prev->ShowNextAddress = -1;
	while (P != NULL)
	{
		Next = P->Next;
		P->Next = Prev;
		P->ShowNextAddress = Prev->ShowAddress;
		Prev = P;
		P = Next;
	}
	return Prev;
}

PtrToNode MergeList(PtrToNode Heads[], int fenzu)
{
	int i;
	PtrToNode Tmp;
	for (i = 0; i < fenzu - 1; i++)
	{
		Tmp = Heads[i];
		while (Tmp->Next != NULL) {Tmp = Tmp->Next;}
		Tmp->Next = Heads[i + 1];
		Tmp->ShowNextAddress = Heads[i + 1]->ShowAddress;
	}
	return Heads[0];
}



