typedef int ElementType;

void sort_bubble(ElementType a[], int n)
{
	int i, j, tmp;
	for (i = n - 1; i >= 0; i--) {
		for (j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) {
				tmp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = tmp;
			}
		}
	}
}