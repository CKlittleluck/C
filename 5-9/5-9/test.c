#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
enum State
{
	VALID,
	INVALID
};
enum State state = INVALID;

int my_atoi(char *str)
{
	int flag = 1;
	long long ret = 0;
	state = INVALID;
	while (isspace(*str))
	{
		str++;
	}
	if (*str == '\0')
	{
		return 0;
	}
	if (*str == '+')
	{
		str++;
	}
	else if (*str == '-')
	{
		flag = -1;
		str++;
	}
	while (isdigit(*str))
	{
		ret = ret * 10 + flag * (*str - '0');
		if ((ret > INT_MAX) || (ret < INT_MIN))
		{
			return 0;
		}
		str++;
	}
	if (*str == '\0')
	{
		state = VALID;
		return(int)ret;
	}
	else
	{
		return(int)ret;
	}
}
int main()
{
	char* p = "-1212212121212";
	printf("%d\n", my_atoi(p));
	return 0;
}

