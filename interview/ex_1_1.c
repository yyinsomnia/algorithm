#include <stdio.h>

#define STR_MAX_LEN 1000

int is_all_diff(const char *s)
{
	short A[256] = {0};
	char *p = s;
	
	while (*p != '\0') {
		if (A[*p] == 0) {
			A[*p] = 1;
		} else {
			return 0;
		}
		p = p + 1;
	}
	return 1;
}

int main(void)
{
	char s[STR_MAX_LEN];
	scanf("%s", s);
	
	int r;
	r = is_all_diff(s);
	if (r == 1) {
		printf("all diff");
	} else {
		printf("not all diff");
	}
	return 0;
}
