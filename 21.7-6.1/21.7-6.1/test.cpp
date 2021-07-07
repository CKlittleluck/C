#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int border = -1;
	long long ans[100000];
	ans[0] = 1;
	ans[1] = 2;

	for (int i = 2; i < 100000; i++)
	{
		long long next = ans[i - 1] + ans[i - 2];
		if (border == -1 && next >= 1000000)
		{
			border = i + 1;
		}
		ans[i] = next % 1000000;
	}

	int n;
	while (cin >> n)
	{
		long long f = ans[n - 1];
		if (n >= border)
		{
			printf("%06d\n", f);
		}
		else
		{
			printf("%d\n", f);
		}
	}
	return 0;
}