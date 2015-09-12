#define MAX 20
#define BASE 10

void radix_sort(int *a, int n)
{
	int i, b[MAX], m = a[0], exp = 1;
	
	for (i = 0; i < n; i++) {
		if (a[i] > m) {
			m = a[i];
		}
	}
	
	while (m / exp > 0) {
		int bucket[BASE] = {0};
		
		for (i = 0; i < BASE; i++) {
			bucket[(a[i] / exp) % BASE]++;
		}
		
		for (i = 1; i < BASE; i++) {
			bucket[i] += bucket[i-1]; 
		}
		
		for (i = n - 1; i >= 0; i--) { //it does matter , it makes the sort stable!!
			b[--bucket[(a[i] / exp) % BASE]] = a[i]; //it does matter, must --bucket! 
		}
		
		for (i = 0; i < n; i++) {
			a[i] = b [i]
		}
		
		exp *= BASE;
	}
}