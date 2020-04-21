#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<assert.h>

//模拟实现strstr
//char* my_strstr(const char* p1, const char* p2)
//{
//	assert(p1 && p2);
//	char *s1 = NULL;
//	char *s2 = NULL;
//	char *cur = (char*)p1;
//	if (*p2 == '\0')
//	{
//		return (char*)p1;
//	}
//	while (*cur)
//	{
//		s1 = cur;
//		s2 = (char*)p2;
//		while (*s1 && *s2 && (*s1 == *s2))
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return cur;
//		}
//		if (*s1 == '\0')
//		{
//			return NULL;
//		}
//		cur++;
//	}
//	return NULL;
//}
//int main()
//{
//	char *p1 = "abcdef";
//	char *p2 = "cd";
//	char *ret = my_strstr(p1, p2);
//	if (ret == NULL)
//	{
//		printf("找不到\n");
//	}
//	else
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}


//模拟实现memcpy
//void * my_memcpy(void * dest, const void * src, size_t count)
//{
//	void * ret = dest;
//	assert(dest);
//	assert(src);
//	while (count--)
//	{
//		*(char *)dest = *(char *)src;
//		++(char *)dest;
//		++(char *)src;
//	}
//	return(ret);
//}
//int main()
//{
//	int i = 0;
//	int arr1[] = { 1, 2, 3, 4, 5 };
//	int arr2[5] = { 0 };
//	my_memcpy(arr2, arr1, sizeof(arr1));
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	return 0;
//}


//模拟实现memmove
void* my_memmove(void * dest, const void * src, size_t count)
{
	void * ret = dest;
	if (dest <= src || (char *)dest >= ((char *)src + count))
	{
		while (count--) 
		{
			*(char *)dest = *(char *)src;
			++(char *)dest;
			++(char *)src;
		}
	}
	else 
	{
		dest = (char *)dest + count - 1;
		src = (char *)src + count - 1;
		while (count--)
		{
			*(char *)dest = *(char *)src;
			--(char *)dest ;
			--(char *)src;
		}
	}
		return(ret);
}
int main()
{
	int i = 0;
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	my_memmove(arr + 2, arr + 3, 20);
	for (i = 0; i < 10; i++)
		{
			printf("%d ", arr[i]);
		}
	return 0;
}