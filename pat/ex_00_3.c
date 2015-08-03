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
	
	if (N <= M) {
		M = M % N;
	}
	
	int *A = malloc(sizeof(int) * N);
	
	for (i = 0; i < N; i++) {
		scanf("%d", A + i);
	}
	i = 0;
	/**
	 * 如果p从0开始在while中会落到1，那么同理可得继续循环肯定会从1落到2
	 * 这样肯定一趟外循环跑完.M,N两数互质，while循环次数为两数最小公倍数除以M
	 */
	for (p = 0; p < M; p++) {
		if (i == N - 1) {
			break;
		}
		walkman = locate(p, M, N);
		
		while (walkman != p) {
			swap(A + p, A + walkman);
			i++;
			walkman = locate(walkman, M, N);
		}
	}
	
	for (i = 0; i < N - 1; i++) {
		printf("%d ", A[i]);
	}
	printf("%d", A[N - 1]);
	
	return 0;
	
}