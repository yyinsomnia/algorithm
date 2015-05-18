#define Cutoff ( 3 )

ElementType Medium3(ElementType A[], int Left, int Right)
{
	int Center = (Left +  Right) / 2;
	if (A[Left] > A[Center])
		Swap(&A[Left], &A[Center]);
	if (A[Left] > A[Right])
		Swap(&A[Left], A[Right]);
	if (A[Center] > A[Right])
		Swap(&A[Center], &A[Right]);

	Swap(&A[Center], &A[Right - 1]);
	return A[Right - 1];
}


void Qsort(ElementType A[], int Left, int Right)
{
	int i, j;
	ElementType Pivot;
	if (Left + Cutoff <= Right)
	{
		ElementType Medium3(ElementType A[], int Left, int Right);
		Pivot = Medium3();

		i = Left;
		j = Right - 1;

		while (A[++i] < Pivot){}
		while (A[--j] > Pivot){}

		for ( ; ; )
		{
			if (i < j)
			{
				Swap(&A[i], &A[j]);
			}
			else 
			{
				break;
			}
		}
		Swap(&A[i], &A[Right - 1]);
		Qsort(A, Left, i - 1);
		Qsort(A, i + 1, Right);
	}
	else
	{
		Insertion(A + Left, Right - Left + 1);
	}
}

void QuickSort(ElementType A[], int N)
{
	Qsort(A, 0, N - 1);
}