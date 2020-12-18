#define _CRT_SECURE_NO_WARNINGS  1
#include <stdio.h>
#include <windows.h>

int get_max(int x, int y)
{
	if (x > y)
		return x;
	return y;
}

int main()
{
	int num1 = 10;
	int num2 = 20;
	int max = get_max(num1, num2);
	printf("max=%d\n", max);
	system("pause");
	return 0;
}