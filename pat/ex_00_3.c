#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b)
{
	*b = *a ^ *b;
	*a = *a ^ *b;
	*b = *a ^ *b;
}


int locate(int start, int offset, int size)
{
	int index = start + offset;
	if (size > index) {
		return index;
	} else {
		return index - size;
	}
}


int main(void)
{
	int p, walkman, N, M, i;
	scanf("%d %d", &N, &M);

	int *A = malloc(sizeof(int) * N);
	
	for (i = 0; i < N; i++) {
		scanf("%d", A + i);
	}
	if ((N & 1) == 0) {
		i = 0;
		for (p = 0; p < M; p++) {
			if (i == N) {
				break;
			}
			walkman = locate(p, M, N);
			
			while (walkman != p) {
				swap(A + p, A + walkman);
				i++;
				walkman = locate(walkman, M, N);
			}
		}
	} else {
		p = 0;
		walkman = locate(p, M, N);
			
		while (walkman != p) {
			swap(A + p, A + walkman);
			walkman = locate(walkman, M, N);
		}
	}
	
	for (i = 0; i < N - 1; i++) {
		printf("%d ", A[i]);
	}
	printf("%d", A[N - 1]);
	
	return 0;
	
}