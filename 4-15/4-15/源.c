#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//int findround(const char * a, char * b)
//{
//	int ret = 0;
//	char tmp[256] = { 0 };
//	strcpy(tmp, a);
//	strcat(tmp, b);
//	if (strstr(tmp, b) != NULL)
//	{
//		return  1;
//	}
//	else
//		return 0;
//}
//int main()
//{
//	char a[] = "abcdef";
//	char b[] = "cdefab";
//	int ret = findround(a, b);
//	if (ret == 1)
//	{
//		printf("�ҵ���\n");
//	}
//	else 
//		printf("û��\n");
//	return 0;
//}



//ģ��ʵ�ֿ⺯��strlen
//int my_strlen(const char * str)
//{
//	int count = 0;
//	assert(str != NULL);
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	char string[] = "asdfghj";
//	printf("%d\n", my_strlen(string));
//	return 0;
//}

//ģ��ʵ�ֿ⺯��strcpy
char* my_strcpy(char * dest, const char * src)
{
	char * ret = dest;
	assert(NULL != dest);
	assert(NULL != src);
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
int main()
{
	char arr[20] = { 0 };
	char *p = "���Ϳ���";
	printf("%s\n", my_strcpy(arr, p));
	return 0;
}