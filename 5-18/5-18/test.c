#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>

unsigned long long Fib(int n)
{
	unsigned long long first = 1;
	unsigned long long second = 1;
	unsigned long long ret = 1;
	for (int i = 2; i < n; i++)
	{
		ret = first + second;
		first = second;
		second = ret;
	}
	return ret;
}
int main()
{
	printf("%d\n", Fib(10));
	return 0;
}