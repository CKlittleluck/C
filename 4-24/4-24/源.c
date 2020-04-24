#define _CRT_SECURE_NO_WARNINGS  1
//求出0～100000之间的所有“水仙花数”并输出。
//#include<math.h>
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 100000; i++)
//	{
//		int n = 1;
//		int sum = 0;
//		int tmp = i;
//		while (tmp / 10)
//		{
//			n++;
//			tmp /= 10;
//		}
//		tmp = i;
//		while (tmp)
//		{
//			sum += pow(tmp % 10, n);
//			tmp /= 10;
//		}
//		if (sum == i)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//打印菱形
//int main()
//{
//	for(int i = 0; i < 7; i++) 
//	{
//		for (int j = 0; j < 7 - i; j++) 
//		{
//			printf(" ");
//		}
//		for (int k = 0; k < 2 * i + 1; k++) 
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	for (int l = 1; l <= 6; l++)
//	{
//		for (int m = 0; m < l + 1; m++) 
//		{
//			printf(" ");
//		}
//		for (int n = 0; n < 13 - l * 2; n++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//		return 0;
//}


//int main()
//{
//	int money = 0;
//	scanf("%d", &money);
//	int total = money;
//	int empty = money;
//	while (empty >= 2)
//	{
//		total += empty / 2;
//		empty = empty / 2 + empty % 2;
//	}
//	printf("%d\n", total);
//	return 0;
//}

//int main()
//{
//	unsigned char a = 200;
//	unsigned char b = 100;
//	unsigned char c = 0;
//	c = a + b;
//	printf("%d %d", a + b, c);
//	return 0;
//}
