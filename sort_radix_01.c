#include <stdio.h>
#define MAX 20
#define BASE 10

void radix_sort(int *a, int n)
{
	int i, b[MAX], m = a[0], exp = 1;
	
	for (i = 1; i < n; i++) {
		if (a[i] > m) {
			m = a[i];
		}
	}
	
	while (m / exp > 0) {
		int bucket[BASE] = {0};
		
		for (i = 0; i < n; i++) {
			bucket[(a[i] / exp) % BASE]++; 
		}
		
		for (i = 1; i < BASE; i++) {
			bucket[i] += bucket[i - 1]; // so bucket[i] means the count eq or lt a[i]
		}
		
		for (i = n - 1; i >= 0; i--) { //think, why from n-1 but not 0, I think it don't matter!
			b[--bucket[(a[i] / exp) % BASE]] = a[i];
		}
		
		for (i = 0; i < n; i++) {
			a[i] = b [i]
		}
	}
}

