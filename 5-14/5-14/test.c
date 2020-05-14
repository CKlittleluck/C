#define _CRT_SECURE_NO_WARNINGS  1
#include <stdio.h>
#define MAX(X, Y) ((X)>(Y)?(X):(Y))
int Max(int x, int y)
{
	return (x > y ? x : y);
}
int main()
{
	int a = 10;
	int b = 20;
	int max = Max(a, b);
	printf("max = %d\n", max);
	max = MAX(a, b);
	printf("max = %d\n", max); 
		return 0;
}