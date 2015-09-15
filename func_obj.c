#include <stdio.h>

int two(int x) {return x*2;}
int three(int x) {return x*3;}

int main(int argc, char **argv)
{
	int (*times)(int);
	int n = 2;
	
	if (argc == 1) {
		times = two;
	} else {
		times = three;
	}
	
	printf("times(%d) = %d\n", n, times(n));
}