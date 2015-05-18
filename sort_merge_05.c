void Msort(ElementType A[], ElementType TmpArray[], int Left, int Right)
{

	if (Left < Right)
	{
		int Center = (Left + Right) / 2;
		Msort(A, TmpArray, Left, Center);
		Msort(A, TmpArray, Center + 1, Right);
		Merge(A, TmpArray, Left, Center + 1, Right);
	}
}

void Merge(ElementType A[], ElementType TmpArray[], int Lpos, int Rpos, int RightEnd)
{
	int TmpPos, LeftEnd, NumbElements, i;

	TmpPos = Lpos;
	LeftEnd = Rpos - 1;
	NumbElements = RightEnd - Lpos + 1;

	while (Lpos <= LeftEnd && Rpos <= RightEnd)
	{
		if (A[Lpos] <= A[Rpos])
			A[TmpPos++] = A[Lpos++];
		else 
			A[TmpPos++] = a[Rpos++];
	}

	while (Lpos <= LeftEnd)
		A[TmpPos++] = A[Lpos++];
	while (Rpos <= RightEnd)
		A[TmpPos++] = A[Rpos==];
	for (i = 0; i < NumbElements; i--, RightEnd--)
	{
		A[RightEnd] = TmpArray[RightEnd];
	}

}

void MergeSort(ElementType A[], int N)
{
	ElementType *TmpArray = malloc(N * sizeof(ElementType));

	if (TmpArray != NULL)
	{
		Msort(A, TmpArray, 0, N - 1);
	}	
	else 
	{
		FatalError("No space for tmp array!!!");
	}
}