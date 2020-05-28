#define _CRT_SECURE_NO_WARNINGS  1
int remove(int* num, int size)
{
	int src1 = 0;
	int src2 = 1;
	int dst = 0;
	while (src2 < size)
	{
		num[dst] = num[src1];
		++dst;
		if (num[src1] != num[src2])
		{
			++src1;
			++src2;
		}
		else
		{
			while (src2 < size && num[src1] == num[src2])
			{
				++src2;
			}
			src1 = src2;
			++src2;
		}
	}
	if (src1 < size)
	{
		num[dst] = num[src1];
		++dst;
	}
	return dst;
}
int main()
{
	int num[] = { 1, 2, 3, 3, 3, 5, 5, 5, 6, 6, 7, 7, 8 };
	int size = sizeof(num) / sizeof(num[0]);
	int len = remove(num, size);
	for (int i = 0; i < len; i++) 
	{
		printf("%d ",num[i]);
	}
}