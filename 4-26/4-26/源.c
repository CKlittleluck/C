#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
//��С������
//void  test(int a, int b)
//{
//	int i = 1;
//	for (i = 1; ; i++)
//	{
//		if (i % a == 0 && i % b == 0)
//		{
//			printf("%d", i);
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	printf("����������ֵ��");
//	scanf("%d %d", &a, &b);
//	test(a, b);
//	return 0;
//}

//ģ��qsort�Ĺ���ʵ��һ��ͨ�õ�ð������
//void myqsort(void * base, size_t nitems, size_t size, int(*compar)(const void *, const void *))
//{
//	int i, j;
//	char * st = (char *)base; 
//	char tmp[16]; 
//
//	for (i = 0; i < nitems - 1; i++)
//	{
//		for (j = 0; j < nitems - 1 - i; j++) 
//		{
//			if (compar(st + j * size, st + (j + 1) * size)) 
//			{
//				memcpy(tmp, st + j * size, size);
//				memcpy(st + j * size, st + (j + 1) * size, size);
//				memcpy(st + (j + 1) * size, tmp, size);
//			}
//		}
//	}
//}


//����һ���������飬ʵ��һ�������������������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�����ż��λ������ĺ�벿�֡�


//void swap_arr(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	int tmp = 0;
//	while (left<right)
//	{
//		while ((left<right) && (arr[left] % 2 == 0))
//		{
//			left++;
//		}
//		while ((left<right) && (arr[right] % 2 == 1))
//		{
//			right--;
//		}
//		if (left<right)
//		{
//			tmp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = tmp;
//		}
//	}
//}
//int main()
//{
//	int i = 0;
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	swap_arr(arr, sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}