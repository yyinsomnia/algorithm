#include <stdio.h>
#include <stdlib.h>

int is_sequence_legal(int *A, int size)
{
	int i, key, min, max;
	//It is assumed that the keys are numbered from 1 to M.
	min = 1;
	max = size;
	
	key = A[size - 1];
	for (i = 1; i < size; i++) {
		if (A[i] > max || A[i] < min) {
			return 0;
		}
		
		if (A[i] < A[i - 1]) {
			max = A[i - 1] - 1;
		} else {
			min = A[i - 1];
		}
		if (max < min) {
			return 0;
		}
		
	}
	return 1;
}

int main(void)
{
	int M, N, i, j, res;
	int **A;
	
	scanf("%d %d", &N , &M);
	A = (int **) malloc(sizeof(int *) * N);
	for (i = 0; i < N; i++) {
		A[i] = (int *) malloc(sizeof(int) * M);
		for (j = 0; j < M; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	for (i = 0; i < N; i++) {
		res = is_sequence_legal(A[i], M);
		if (res) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	
	return 0;	
}