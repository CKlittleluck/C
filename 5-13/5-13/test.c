#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#define OFFSETOF(struct_name, member_name) (int)&(((struct_name*)0)->member_name)
struct s
{
	char c1;
	int a;
	char c2;
};
int main()
{
	printf("%d\n", OFFSETOF(struct s, c1));
	printf("%d\n", OFFSETOF(struct s, a));
	printf("%d\n", OFFSETOF(struct s, c2));
	return 0;
}
