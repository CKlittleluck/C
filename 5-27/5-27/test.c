#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
//Ðý×ªÊý×é
void reverse(int* nums, int begin, int end)
{
	while (begin < end)
	{
		int tmp = nums[begin];
		nums[begin] = nums[end];
		nums[end] = tmp;
		++begin;
		--end;
	}
}

void rotate(int* nums, int numsize, int k)
{
	if (k > numsize)
	{
		k %= numsize;
	}
	reverse(nums, 0, numsize - 1);
	reverse(nums, 0, k - 1);
	reverse(nums, k, numsize - 1);
}

int main()
{
	int nums[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int numsize = sizeof(nums) / sizeof(nums[0]);
	int k = 3;
	rotate(nums, numsize, k);
	for (int i = 0; i < numsize; i++)
	{
		printf("%d ", nums[i]);
	}
	return 0;
}