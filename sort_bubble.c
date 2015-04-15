int *sort_bubble(int *arr, int size)
{
	int i ,j; //int i = j = 0; is illegal
	int temp;
	for (i = size - 1; i >= 0; i--) {
		for (j = 0; j < i; j++) {
			if (*(arr + j) > *(arr + j + 1)) {
				temp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			}
		}
	}
	return arr;
}