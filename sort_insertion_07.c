void InsertionSort(ElementType A[], int n)
{
	int P, j;
	for (P = 1; P < n; P++) {
		ElementType Tmp = A[P];
		for (j = P; j > 0 && A[j - 1] > Tmp; j--) {
			A[j] = A[j - 1];
		}
		A[j] = Tmp;
	}
}