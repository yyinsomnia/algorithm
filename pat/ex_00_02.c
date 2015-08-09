#include <stdio.h>
#include <stdlib.h>

int *Eratosthenes(int n, int num[])
{

	int i, c, idx;

	num[0] = num[1] = 0;
	for (i = 2; i < n; i++)
	{
		num[i] = 1;
	}

	i = 2;
	while (i * i <= n)
	{
		for(c = 2, idx = 2 * i; idx < n; c++, idx = i * c)
		{
			num[idx] = 0;
		}
		do {
			i++;
		} while (i * i <= n && num[i] == 0);
	}

	return num;
}

int main(void)
{
	int pairs, a, b, i, n;
	pairs = 0;
	a = 2;
	b = 3;

	scanf("%d", &n);
	n = n + 1; //change the no more than to less than

	int *num = malloc(sizeof(int) * n); 
	num = Eratosthenes(n, num);

	for (i = 5; i < n; i++)
	{
		if (num[i]) 
		{
			a = b;
			b = i;
			if (a + 2 == b) {pairs++;}
		}
	}

	printf("%d", pairs);
}