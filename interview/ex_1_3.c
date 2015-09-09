#include <stdio.h>

#define STR_MAX_LEN 100
#define CHAR_NUM (256);

void char_count(const char *s, int A[])
{
	int i = 0;
	while (*(s + i) != '\0')) {
		A[*(s + i)]++;
		i++;
	}
}

int char_count_same(int A[], int B[], int n)
{
	int i = 0;
	while (i++ < n) {
		if (A[i] != B[i]) {
			return 0;
		}
	}
	return 1;
}

int main(void)
{
	char a[STR_MAX_LEN], b[STR_MAX_LEN];
	int a_count[CHAR_NUM] = {0}, b_count[CHAR_NUM] = {0};
	
	scanf("%s %s", a, b);
	char_count(a, a_count);
	char_count(b, b_count);
	
	int r;
	r = char_count_same(a_count, b_count, CHAR_NUM);
	
	if (r) {
		printf("yes");
	} else {
		printf("no");
	}
	
	return 0;
}