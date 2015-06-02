#define Cutoff (3)

ElementType Median3(ElementType A[], int Left, int Right)
{
	int Center  = (Left + Right) / 2;
	if (A[Left] > A[Center])
		Swap(&A[Left], &A[Center]);
	if (A[Left] > A[Right])
		Swap(&A[Left], &A[Right]);
	if (A[Center] > A[Right])
		Swap(&A[Center], &A[Right]);
	Swap(&A[Center], &A[Right - 1]);
	return A[Right - 1];
}

void QSort(ElementType A[], int Left, int Right)
{
	int Povit, i , j;
	if (Left + Cutoff <= Right) {
		Povit = Median3(A, Left, Right);
		i = Left;
		j = Right - 1;
		for ( ; ; ) {
			while (A[++i] <= Povit) {};
			while (A[--j] >= Povit) {};
			if (i < j)
				Swap(&A[i], &A[j])
			else
				break;
		}
		Swap(&A[i], &A[Right - 1]);
		Qsort(A, Left, i - 1);
		Qsort(A, i + 1, Right);
	}
}

void QuickSort(ElementType A[], int n)
{
	Qsort(A, 0, n - 1);
}