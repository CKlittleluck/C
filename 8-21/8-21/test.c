#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
//int main()
//{
//	int a[] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24 }, *q[4], k;
//	for (k = 0; k<4; k++){ q[k] = &a[k * 3]; }printf("%d\n", q[3][1]);
//	return 0;
//}

//

//int main()
//{
//	int a ;
//	printf("请输入需查找的数： ");
//	scanf("%d",&a);
//	int array[]= { 1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15 };
//	int size = sizeof(array) / sizeof(array[0]);
//	for (int i = 0; i < size; i++)
//	{
//		if (array[i] == a)
//		{
//			printf("找到了\n");
//		}
//		break;
//	}
//	printf("找不到\n");
//	return 0;
//}

int main()
{
	int a = 10;
	a += a *= a -= a / 3;
	printf("%d", a);
	return 0;
}