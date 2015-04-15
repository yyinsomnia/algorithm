int *sort_selection(int *arr, int size)
{
	int start, i, min, min_index;
	min = 0x0FFFFFFF; //equal to 2147483647
	for (start = 0; start < size; start++) {
		for (i = start; i < size; i++) {
			if (*(arr + i) < min) {
				min = *(arr + i);
				min_index = i;
			}
		}
		*(arr + min_index) = *(arr + start);
		*(arr + start) = min;
	}
	return arr;
}