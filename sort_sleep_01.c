void sort_sleep(int a[], int n)
{
	while (--n > 1 && !fork()); //fork()==0 is the child, so just master loop
	sleep(n = atoi(a[n]));
	printf("%d\n", n);
	wait(0);
	return 0;
}