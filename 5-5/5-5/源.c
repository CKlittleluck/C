#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>

//ģ��ʵ��strncpy
//char* my_strncpy(char* dst, const char* src, int n)
//{
//	int i;
//	for (i = 0; src[i] && i < n; i++)
//	{
//		dst[i] = src[i];
//	}
//	if (i < n)
//	{
//		dst[i] = 0;
//	}
//	return dst;
//}
//int main()
//{
//	int n = 2;
//	char dst[] = "abcdef";
//	char src[] = "def";
//	char* ret = my_strncpy(dst, src, n);
//	printf("%s ", ret);
//	return 0;
//}

//ģ��ʵ��strncat
//char* my_strncat(char* dst, const char* src, int n)
//{
//	char * tmp = dst;
//	while (*dst)
//	{
//		dst++;
//	}
//	int i;
//	for (i = 0; src[i] && i < n; i++)
//	{
//		dst[i] = src[i];
//	}
//	dst[i] = 0;
//	return tmp;
//}
//
//int main()
//{
//	char dst[10] = "abcdef";
//	char src[] = "def";
//	char* ret = my_strncat(dst, src, 3);
//	printf("%s ", ret);
//	return 0;
//}


//һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ���дһ�������ҳ�������ֻ����һ�ε����֡�

void Find_single_num(int arr[], int sz, int* p1,int* p2)
{
	int i = 0;
	int pos = 0;
	int ret = 0;
	for (i = 0; i < sz; i++)
	{
		ret ^= arr[i];
	}
	for (pos = 0; pos < 32; pos++)
	{
		if (((ret >> pos) & 1) == 1)
		{
			break;
		}
	}
	for (i = 0; i < sz; i++)
	{
		if (((arr[i] >> pos) & 1) == 1)
		{
			*p1 ^= arr[i];
		}
		else
		{
			*p2 ^= arr[i];
		}
	}
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 6, 7,};
	int num1 = 0;
	int num2 = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	Find_single_num(arr, sz, &num1, &num2);
	printf("%d %d\n", num1, num2);
	return 0;
}