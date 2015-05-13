void MSort(ElementType A[], ElementType TmpArray[], int Left, int Right)
{
	int Center;
	if (Left < Right)
	{
		Center = (Left + Right) / 2;
		MSort(A, TmpArray, Left, Center);
		MSort(A, TmpArray, Center + 1, Rigth);
		Merge(A, TmpArray, Left, Center + 1, Right);
	}
}

void Merge(ElementType A[], ElementType TmpArray, Lpos, Rpos, RightEnd)
{
	int i, LeftEnd, TmpPos, NumElements;

	LeftEnd = Rpos - 1;
	TmpPos = Lpos;
	NumElements = RightEnd - Lpos + 1;
	while (Lpos <= LeftEnd && Rpos <= RightEnd)
	{
		if (A[Lpos] <= A[Rpos])
			TmpArray[TmpPos++] = A[Lpos++];
		else
			TmpArray[TmpPos++] = A[Rpos++];
	}

	while (Lpos <= LeftEnd)
		TmpArray[TmpPos++] = A[Lpos++];
	while (Rpos <= RightEnd)
		TmpArray[TmpPos++] = A[Rpos++];

	for (i = 0; i < NumElements; i++, RightEnd--)
	{
		A[RightEnd] = TmpArray[RightEnd];
	}
}

void Mergesort(ElementType A[], int N)
{
	ElementType *TmpArray;
	TmpArray = malloc(N * sizeof(ElementType));

	if (TmpArray != NULL) 
	{
		MSort(A, TmpArray, 0, N - 1);
	}
	else 
	{
		FatalError("No space for tmp array!!!");
	}
}