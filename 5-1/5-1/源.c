#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
char* my_strncpy(char* dst, const char* src, size_t n)
{
		int i;
		for (i = 0; src[i] && i < n; i++)
		{
			dst[i] = src[i];
		}

		if (i < n)
		{
			dst[i] = 0;
		}
		return dst;
}
int main()
{
	int n = 0;
	char dst[] = "abcdef";
	char src[] = "acred";
	char* ret = my_strncpy(dst, src, 3);
	printf("%s ", ret);
	return 0;
}