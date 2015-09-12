#define BASE 10
#define MAX 20

void sort_radix(int *a, int n)
{
	int i, b[MAX], m, exp;
	m = a[0];
	for (i = 1; i < n; i++) {
		if (a[i] > m) {
			m = a[i];
		}
	}
	
	exp = 1;
	while (m / exp > 1) {
		int bucket[BASE] = {0};
		
		for (i = 0; i < n; i++) {
			bucket[(a[i] / exp) % BASE]++;
		}
		
		for (i = 1; i < BASE; i ++) {
			bucket[i] += bucket[i - 1];
		}
		
		for (i = n - 1; i >= 0; i--) ｛
			b[--bucket[(a[i] / exp) % BASE]] = a[i];
		｝
		
		for (i = 0; i < n; i++) {
			a[i] = b[i];
		}
		exp *= BASE;
	}
}