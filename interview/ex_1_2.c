#include <stdio.h>
#include <stdlib.h>
#define STR_MAX_LEN 100

void reverse(char *str)
{
	char *tmp;
	int i = 0, j = 0;
	
	while (*(str + i) != '\0') {
		i++;
	}
	
	tmp = malloc(sizeof(char) * i);
	
	while (i--) {
		tmp[j++] = str[i - 1];
	}
	
	free(str);
	str = tmp;
}

int main(void)
{
	char s[STR_MAX_LEN];
	scanf("%s", s);
	
	reverse(s);
	printf("%s", s);
	return 0;
}