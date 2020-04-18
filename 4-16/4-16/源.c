#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//
//void test1()
//{
//	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof arr[0], cmp_int);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int cmp_float(const void* e1, const void* e2)
//{
//	return ((int)(*(float*)e1 - *(float*)e2));
//}
//
//void test2()
//{
//	float a[] = { 9.0, 7.0, 8.0, 6.0, 4.0, 5.0 };
//	int sz = sizeof(a) / sizeof(a[0]);
//	qsort(a, sz, sizeof(a[0]), cmp_float);
//	int j = 0;
//	for (j = 0; j < sz; j++)
//	{
//		printf("%f ", a[j]);
//	}
//	printf("\n");
//}
//int main()
//{
//	test1();
//    test2();
//	return 0;
//}


//实现一个函数，可以左旋字符串中的k个字符。
//void left_reverse(const char* str, int a)
//{
//	int len = strlen(str);
//	int pos = a % len; 
//	char tmp[256] = { 0 }; 
//	strcpy(tmp, str + pos); 
//	strncat(tmp, str, pos); 
//	strcpy(str, tmp); 
//	printf("%s\n", str);
//}
//
//int main()
//{
//	int a = 0;
//	char str[100];
//	scanf("%s", &str);
//	scanf("%d", &a);
//	printf("%s\n", str);
//	left_reverse(str, a);
//	return 0;
//}

//杨氏矩阵

int findnum(int a[3][3], int x, int y, int f) 
{
	int i = 0, j = x - 1; 
	while (j >= 0 && i < y)
	{
		if (a[i][j] < f) 
		{
			i++;
		}
		else if (a[i][j] > f) 
		{
			j--;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	int a[3][3] = { 1, 3, 5, 3, 5, 7, 5, 7, 9 };
	if (findnum(a, 3, 3, 3))
	{
		printf("找到了\n");
	}
	else
	{
		printf("找不到\n");
	}
	return 0;
}