#include <stdio.h>
#include <stdlib.h>

#define cutoff (500000)
typedef int ElementType;


void InsertionSort(ElementType *A, int N)
{
	ElementType P, Tmp;
	int i;
	for (i = 1; i < N; i++) {
		Tmp = A[i];
		for (P = i; P >= 1 && A[P - 1] > Tmp; P = P - 1) {
			A[P] = A[P - 1];
		}
		A[P] = Tmp;
	}
}

void swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

int median3(ElementType *A, int start, int end)
{
	int center = start + (end - start) / 2;
	if (A[start] > A[center]) {
		swap(A + start, A + center);
	}
	if (A[start] > A[end]) {
		swap(A + start, A + end);
	}
	if (A[center] > A[end]) {
		swap(A + center, A + end);
	}
	swap(A + center, A + end - 1);
	return A[end - 1];
}

void QuickSort(ElementType *A, int start, int end)
{
	int pivot, median, i, j;
	if (start == end) {
		return;
	}
	if (start + cutoff < end) {
		pivot = median3(A, start, end);
		i = start; j = end - 1;
		for ( ; ; ) {
			while (A[++i] < pivot) {}
			while (A[--j] > pivot) {}
			if (i > j) {
				break;
			} else {
				swap(A + i, A + j);
			}
		}
		swap(A + i, A + end - 1);
		QuickSort(A, start, i - 1);
		QuickSort(A, i + 1, end);
		
	} else {
		InsertionSort(A + start, end - start + 1);
	}
	
}

void QSort(ElementType *A, int N)
{
	QuickSort(A, 0, N -1);
}

void InorderTraversal(ElementType *A, int *p_iA, ElementType *T, int iT, const int N)
{
	if (iT <= N) {
		InorderTraversal(A, p_iA, T, 2 * iT, N);
		T[iT] = A[(*p_iA)++];
		InorderTraversal(A, p_iA, T, 2 * iT + 1, N);	
	}
}

int main(void)
{
	int N, i;
	ElementType *A, *T;
	scanf("%d", &N);
	A = malloc(sizeof(ElementType) * N);
	//convenience for calculate the childs, the first one is T[1], childs are T[2*1] T[2*1+1]
	T = malloc(sizeof(ElementType) * (N + 1)); 
	if (A == NULL || T == NULL) {
		printf("no space!");
		exit(0);
	}
	
	for (i = 0; i < N; i++) {
		scanf("%d", A + i);
	}
	
	QSort(A, N);
	//int *p_iA = 0; !!!!!!
	int iA = 0;
	int iT = 1;
	InorderTraversal(A, &iA, T, iT, N);
	
	for (i = 1; i < N; i++) {
		printf("%d ", T[i]);
	}
	printf("%d", T[N]);
	return 0;
}

