#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
//void print(int *p, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//{
//		printf("%d ", *(p + i));
//	}
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);
//	return 0;
//}

//×Ö·û´®ÄæÐò
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//void reverse_string(char* arr)
//{
//	char tmp = arr[0];
//	int len = my_strlen(arr);
//	arr[0] = arr[len - 1];
//	arr[len - 1] = '\0';
//    if (my_strlen(arr+1) >=2)
//		reverse_string(arr+1);
//	arr[len - 1] = tmp;
//}
//int main()
//{
//	char arr[] = "abcdefg";
//	reverse_string(arr);
//	printf("%s\n", arr);
//	return 0;
//}