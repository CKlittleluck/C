#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#define PRINT(X) printf("the value of " #X " is %d\n", X)
int main()
{
	printf("hello world\n");
	printf("hello " "world\n");
	printf("hel" "lo " "world\n");

	int a = 10;
	int b = 20;
	PRINT(a);
	PRINT(b);
	return 0;
}