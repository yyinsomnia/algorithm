#include <stdio.h>
#include <stdlib.h>

#define Error( Str )        FatalError( Str )
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )

typedef int ElementType;
#define MinTableSize (1)

#ifndef _HashQuard_H

typedef unsigned int Index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
void DestoryTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable);
ElementType Retrieve(Position P, HashTable H);
HashTable Rehash(HashTable H);

#endif

enum KindOfEntry {Legitimate, Empty, Deleted};

struct HashEntry
{
	ElementType Element;
	enum KindOfEntry Info;
};

typedef struct HashEntry Cell;

struct HashTbl
{
	int TableSize;
	Cell *TheCell;
};

ElementType Hash(ElementType key, int size)
{
	return key % size;
}

static int NextPrime( int N )
{
    int i;

    if( N % 2 == 0 )
        N++;
    for( ; ; N += 2 )
    {
        for( i = 3; i * i <= N; i += 2 )
            if( N % i == 0 )
                goto ContOuter;  /* Sorry about this! */
        return N;
      ContOuter: ;
    }
}

HashTable InitializeTable(int TableSize)
{
	HashTable H;
	int i;
	
	if (TableSize < MinTableSize) {
		Error("Table size too small");
		return NULL;
	}
	
	H = malloc(sizeof(struct HashTbl));
	if (H == NULL) {
		FatalError("Out of space!!!");
	}
	
	H->TableSize = NextPrime(TableSize);
	
	H->TheCell = malloc(sizeof(Cell) * H->TableSize);
	if (H->TheCell == NULL) {
		FatalError("Out of space!!");
	}
	for (i = 0; i < H->TableSize; i++) {
		H->TheCell[i].Info = Empty;
	}
	
	return H;
}

Position Find(ElementType  Key, HashTable H)
{
	Position CurrentPos;
	int CollisionNum;
	
	CollisionNum = 0;
	CurrentPos = Hash(Key, H->TableSize);
	while (H->TheCell[CurrentPos].Info != Empty && H->TheCell[CurrentPos].Element != Key) { //may infinite loop?
		CurrentPos += 2 * ++CollisionNum - 1;
		if (CurrentPos >= H->TableSize) {
			CurrentPos -= H->TableSize;
		}		
	}
	return CurrentPos;
}

void Insert(ElementType Key, HashTable H)
{
	Position Pos;
	
	Pos = Find(Key, H);
	if (H->TheCell[Pos].Info != Legitimate) {
		H->TheCell[Pos].Info = Legitimate;
		H->TheCell[Pos].Element = Key;
	}
}

int main(void)
{
	int M, N, i; //M is the ht size
	ElementType *A, Tmp;
	HashTable ht;
	
	
	scanf("%d %d", &M, &N);
	ht = InitializeTable(M);
	A = malloc(sizeof(ElementType) * N);
	for (i = 0; i < N; i++) {
		scanf("%d", A + i);
	}
	
	for (i = 0; i < N; i++) {
		Insert(A[i], ht);
	}
	
	for (i = 0; i < N; i++) {
		Tmp = Find(A[i], ht);
		if (Tmp >= 0) {
			printf("%d ", Tmp);
		} else {
			printf("- ");
		}
	}
	return 0;
}