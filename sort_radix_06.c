#include <stdlib.h>
#define BASE 10

void sort_radix(int *a, int n)
{
	int m = a[0], i, j, exp = 1;
	int *b = malloc(sizeof(int) * n);
	
	for (i = 1; i < n; i++) {
		if (a[i] > m) {
			m = a[i];
		}
	}
	
	while (m / exp > 0) {
		int bucket[BASE] = {0};
		
		for (i = 0; i < n; i++) {
			bucket[(m / exp) % BASE]++;
		}
		
		for (i = 1; i < BASE; i++) {
			bucket[i] += bucket[i - 1];
		}
		
		for (i = n - 1; i >= 0; i--) {
			b[--bucket[(a[i] / exp) % BASE]] = a[i];
		}
		
		for (i = 0; i < n; i++) {
			a[i] = b[i];
		}
		
		exp *= BASE;
	}
	
}