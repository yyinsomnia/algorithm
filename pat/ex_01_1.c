#include <stdio.h>
#include <stdlib.h>

int max_sum_sequecnce(int A[], int N)
{
	int sum_now, sum_want, i;
	sum_now = sum_want = 0;
	i = 0;
	while (i < N) {
		sum_want += A[i++];
		if (sum_want < 0) {
			sum_want = 0;
		} else if (sum_want > sum_now) {
			sum_now = sum_want;
		}
				
	}
	return sum_now;
}

int main(void)
{
	int K, i, sum;
	int *A;
	scanf("%d", &K);
	A = malloc(sizeof(int) * K);
	for (i = 0; i < K; i++) {
		scanf("%d", A + i);
	}
	
	sum = max_sum_sequecnce(A, K);
	printf("%d", sum);
	
	return 0;
}