#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include <assert.h>


//1
//模拟实现strlen
//int my_strlen(const char* str)
//{
//	if (*str == '\0')
//	{
//		return 0;
//	}
//	else
//		return 1 + my_strlen(str + 1);
//}
//int main()
//{
//	char arr[] = "asdfghj";
//	int ret = my_strlen(arr);
//	printf("%d ", ret);
//	return 0;
//}


//2
//模拟实现strcpy
//char* my_strcpy(char* dest, char* src)
//{
//	char* ret = dest;
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "ABCD";
//	my_strcpy(arr1, arr2);
//	printf("%s", arr1);
//	return 0;
//}


//3
//模拟实现strcmp
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//		{
//			return 0;
//		}
//		str1++;
//		str2++;
//	}
//	if (*str1 > *str2)
//		return 1;
//	else
//		return -1;
//}
//int main()
//{
//	char arr1[] = "abcde";
//	char arr2[] = "abcdf";
//	int ret = my_strcmp(arr1, arr2);
//	printf("%d", ret);
//	return 0;
//}

//4
//模拟实现strcat
//char* my_strcat(char* arr1, const char* arr2)
//{
//	char *ret = arr1;
//	assert(arr1 && arr2);
//	while (*arr1)
//	{
//		*arr1++;
//	}
//	while(*arr1++ = *arr2++)
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[20] = "我爱学习";
//	char arr2[] = "真棒";
//	my_strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}





