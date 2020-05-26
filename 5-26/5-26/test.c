#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
//{
//	int end1 = m - 1;
//	int end2 = n - 1;
//	int end = m + n - 1;
//
//	while (end1 >= 0 && end2 >= 0)
//	{
//		if (nums1[end1] > nums2[end2])
//		{
//			nums1[end--] = nums1[end1--];
//		}
//		else
//		{
//			nums1[end--] = nums2[end2--];
//		}
//	}
//	while (end1 >= 0)
//	{
//		nums1[end--] = nums1[end1--];
//	}
//
//	while (end2 >= 0)
//	{
//		nums1[end--] = nums2[end2--];
//	}
//}
//
//int main()
//{
//	int nums1[6] = { 1, 2, 3, 0, 0, 0 };
//	int nums2[3] = { 4, 5, 6 };
//	int m = 3;
//	int n = 3;
//	int i = 0;
//	int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
//	int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
//	merge(nums1, nums1Size, 3, nums2, nums2Size, 3);
//	for (i = 0; i < 6; i++)
//	{
//		printf("%d ", nums1[i]);
//	}
//	return 0;
//}


//数组形式的整数加法
int* addToArrayForm(int* A, int Asize, int k, int* returnsize)
{
	int size = Asize > 5 ? Asize + 1 : 5 + 1;
	int* ret = calloc(size, sizeof(int));
	int total = 0;
	int retIdx = size - 1;
	while (Asize > 0)
	{
		k += A[Asize - 1];
		ret[retIdx--] = k % 10;
		k /= 10;
		total++;
		Asize--;
	}
	while (k > 0)
	{
		ret[retIdx--] = k % 10;
		k /= 10;
		total++;
	}
	if (total < size)
	{
		memmove(ret, ret + (size - total), total*sizeof(int));
		*returnsize = total;
		return ret;
	}
}

int main()
{
	int A[] = { 1, 2, 0, 0 };
	int returnsize[] = { 0 };
	int k = 34;
	int Asize = sizeof(A) / sizeof(A[0]);
	int* b = addToArrayForm(A, 4, k, returnsize);
	for (int i = 0; i < *returnsize; i++)
	{
		printf("%d ", b[i]);
	}
}