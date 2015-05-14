void MSort(ElementType A[], ElementType TmpArray[], int Left, int Right)
{
	if (Left < Right)
	{
		int Center = (Left + Right) / 2;
		MSort(A, TmpArray, Left, Center);
		MSort(A, TmpArray, Center + 1, Right);
		Merge(A, TmpArray, Left, Center + 1, Right);
	}
}

void Merge(ElementType A[], ElementType TmpArray[], int Lpos, int Rpos, int RightEnd)
{
	int i, TmpPos, LeftEnd, NumElements;

	TmpPos = Lpos;
	LeftEnd = Rpos - 1;
	NumElements = RightEnd - Lpos + 1;

	while (Lpos <= LeftEnd && Rpos <= RightEnd)
	{
		if (A[Lpos] <= A[Rpos])
		{
			A[TmpPos++] = A[Lpos++];
		}
		else 
		{
			A[TmpPos++] = A[Rpos++];
		}
	}

	while (Lpos <= LeftEnd)
		A[TmpPos++] = A[Lpos++];
	while (Rpos <= RightEnd)
		A[TmpPos++] = A[Rpos++];

	for (i = 0; i < NumElements; i++, RightEnd--)
	{
		A[RightEnd] = TmpArray[RightEnd];
	}
}

void MergeSort(ElementType A[], int N)
{
	ElementType *TmpArray = malloc(N * sizeof(ElementType));

	MSort(A, TmpArray, 0, N - 1);
}