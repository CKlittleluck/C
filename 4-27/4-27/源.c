#define _CRT_SECURE_NO_WARNINGS  1
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
int main()
{
	//malloc(10*sizeof(int))
	int*p = (int*)calloc(10, sizeof(int));

	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		int i = 0;
		for (i = 0; i < 10; i++)
		{
			 *(p + i) = i;
		}
		for (i = 0; i < 10; i++)
		{
			printf("%d ", *(p + i));
		}
	}
	//释放空间
	//free函数是用来释放动态开辟的空间的
	free(p);
	p = NULL;
	return 0;
}