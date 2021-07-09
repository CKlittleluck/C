#include <iostream>
#include <stdio.h>

using namespace std;
long long NowCoder(int from, int to)
{
	long long arry[80] = { 0 };
	arry[0] = 1;
	arry[1] = 1;
	arry[2] = 2;
	for (int i = 3; i < 80; i++)
	{
		arry[i] = arry[i - 1] + arry[i - 2];
	}

	long long count = 0;
	for (int i = from - 1; i <= to - 1; i++)
	{
		count += arry[i];
	}
	return count;
}

int main()
{
	int from, to;
	while (cin >> from >> to)
	{
		long long ans = NowCoder(from, to);
		cout << ans << endl;
	}
	return 0;
}