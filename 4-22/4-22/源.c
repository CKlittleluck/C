#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<assert.h>

//´íÎóÊ¹ÓÃmemcpyº¯Êı
void * my_memcpy(void * dest, const void * src, size_t count)
{
	void * ret = dest;
	assert(dest);
	assert(src);
	while (count--)
	{
		*(char *)dest = *(char *)src;
		++(char *)dest;
		++(char *)src;
	}
	return(ret);
}
int main()
{
	int i = 0;
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	my_memcpy(arr+2, arr, 20);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}