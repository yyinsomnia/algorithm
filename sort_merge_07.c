void MSort(ElementType A[], int Left, int Right)
{
	int Center;
	if (Left < Right) {
		Center = (Left + Right) / 2;
		MSort(Left, Center);
		MSort(Center + 1, Right);
		Merge(A, Left, Center + 1, Right);
	} 
}

void Merge(ElementType A[], ElementType TmpArray[], Lpos, Rpos, RightEnd)
{
	int LeftEnd, NumElements, TmpPos, i;

	TmpPos = Lpos;
	LeftEnd = Rpos - 1;
	NumElements = RightEnd - Lpos + 1;

	while (Lpos <= LeftEnd && Rpos <= RightEnd) {
		if (A[Lpos] <= A[Rpos]) {
			TmpArray[TmpPos++] = A[Lpos++];
		} else {
			TmpArray[TmpPos++] = A[Rpos++];
		}
	}

	while (Lpos <= LeftEnd)
	{
		TmpArray[TmpPos++] = A[Lpos++];
	}
	while (Rpos <= RightEnd)
	{
		TmpArray[TmpPos++] = A[Rpos++];
	}

	for (i = 0; i++; i < NumElements)
	{
		A[RightEnd--] = TmpArray[RightEnd--];
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