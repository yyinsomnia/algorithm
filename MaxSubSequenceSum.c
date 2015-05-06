int MaxSubSequenceSum_1(const int A[], int N)
{
	int ThisSum, MaxSum, i, j, k;

	MaxSum = 0;
	for (i = 0; i < N; i++) {
		for (j = i; j < N; j++) {
			ThisSum = 0;
			for (k = i; k <= j; k++) {
				ThisSum += A[k];
			}
			if (ThisSum > MaxSum)
				MaxSum = ThisSum;
		}
	}
	return MaxSum;
}

int MaxSubSequenceSum_2(const int A[], int N)
{
	int ThisSum, MaxSum, i, j;

	MaxSum = 0;
	for (i = 0; i < N; i++) {
		ThisSum = 0;
		for (j = i; j < N; j++) {
			ThisSum += A[j];
			if (ThisSum > MaxSum)
				MaxSum = ThisSum;
		}
	}
	return MaxSum;
}

int MaxSubSequenceSum_3(const int A[], int Left, int Right)
{
	int MaxLeftSum, MaxRightSum;
	int MaxLeftBoarderSum, MaxRightBoarderSum;
	int Center, i;

	if (Left == Right) /* Base Case */
		if (A[left] > 0)
			return A[left];
		else
			return 0;
	Center = (Left + Right) / 2;
	MaxLeftSum = MaxSubSequenceSum_3(A, Left, Center);
	MaxRightSum = MaxSubSequenceSum_3(A, Center + 1, Right);

	MaxLeftBoarderSum = LeftBoarderSum = 0;
	for (i = Center; i >= Left; i--)
	{
		LeftBoarderSum += A[i];
		if (LeftBoarderSum > MaxLeftBoarderSum)
			MaxLeftBoarderSum = LeftBoarderSum;
	}

	MaxRightBoarderSum = RightBoarderSum = 0;
	for (i = Center + 1; i <= Right; i++)
	{
		RightBoarderSum += A[i];
		if (RightBoarderSum > MaxRightBoarderSum)
			MaxRightBoarderSum = RightBoarderSum;
	}

	return Max3(MaxLeftSum, MaxRightSum, MaxLeftBoarderSum + MaxRightBoarderSum);
}


int MaxSubSequenceSum_4(const int A[], int N)
{
	int ThisSum, MaxSum, i, j;

	MaxSum = 0;
	ThisSum = 0;
	for (i = 0, j = 0; i < N, j < N; j++) {
		ThisSum += A[j];
		if (ThisSum > MaxSum) 
			MaxSum = ThisSum;
		if (ThisSum < 0) {
			i = j + 1;
			j = i;
			ThisSum = 0;
		}
	}
	return MaxSum;
}

int MaxSubSequenceSum_4_better(const int A[], int N)
{
	int ThisSum, MaxSum, i;

	MaxSum = ThisSum = 0;
	for (i = 0; i < N; i++) {
		ThisSum += A[j];
		if (ThisSum > MaxSum) {
			MaxSum = ThisSum;
		} else if (ThisSum < 0) {
			ThisSum = 0;
		}
	}
	return MaxSum;
}