#define BASE 10

void radix_sort(ElementType a[], int n) 
{
	ElementType *b, m = a[0];
	int i, exp = 1;
	b = malloc(sizeof(ElementType) * n);
	
	for (i = 1; i < n; i++) {
		if (a[i] > m) {
			m = a[i];
		}
	}
	
	while (m / exp > 0) {
		ElementType bucket[BASE];
		
		for (i = 0; i < n; i++) {
			bucket[(a[i] / exp) % BASE]++;	
		}
		
		for (i = 1; i < n; i++) {
			bucket[i] += bucket[i - 1];
		}
		
		for (i = n - 1; i >= 0; i--) {
			b[--bucket[(a[i] / exp) % BASE]] = a[i]++;
		}
		
		for (i = 0; i < n; i++) {
			a[i] = b[i];
		}
		exp *= BASE;
	}
	free(b);
}