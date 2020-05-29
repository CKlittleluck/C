#define _CRT_SECURE_NO_WARNINGS  1
//原地移除数组中所有的元素val，要求时间复杂度为O(N)，空间复杂度为O(1)
#include<stdio.h>
int removeElement(int* nums, int numsSize, int val)
{
	int src = 0;
	int dst = 0;
	while (src < numsSize)
	{
		if (nums[src] != val)
		{
			nums[dst] = nums[src];
			src++;
			dst++;
		}
		else
		{
			src++;
		}
	}
		return dst;
}

int main()
{
	int num[] = { 1, 2, 3, 3, 3, 5, 5, 5, 6, 6, 7, 7, 8 };
	int size = sizeof(num) / sizeof(num[0]);
	int val = 5;
	int len = removeElement(num, size,val);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", num[i]);
	}
}