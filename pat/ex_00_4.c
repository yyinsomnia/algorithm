#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void str_count_num(int A[], char *s, int len)
{
	int i, v;
	for (i = 0; i < len; i++) {
		v = s[i] - '0';
		A[v]++;
	}
}

void int_count_num(int A[], long long int v)
{
	int y;
	while (v > 0) {
		y = v % 10;
		A[y]++;
		v = v / 10;
	}
}

int main(void)
{
	char *s;
	long long int a;
	int i;
	int A[10] = {0};
	int B[10] = {0};
	scanf("%s", s);
	str_count_num(A, s, strlen(s));
	a = atol(s);
	a = a << 1;
	int_count_num(B, a);
	for (i = 0; i < 10; i++) {
		if (A[i] != B[i]) {
			printf("No\n");
			printf("%lld", a);
			return 0;
		}
	}
	
	printf("Yes\n");
	printf("%lld", a);
	return 0;
}