#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#define MAX(X, Y)     ((X)>(Y)?(X):(Y))
int main()
{
	int a = 10;
	int b = 11;

	int max = MAX(a++, b++);
	//int max = ((a++) > (b++) ? (a++) : (b++));

	printf("%d\n", max);
	printf("%d\n", a);
	printf("%d\n", b);
	return 0;
}
