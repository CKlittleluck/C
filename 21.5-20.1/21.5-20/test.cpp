#include <iostream>
using namespace std;

int COUNT(int n)
{
	int sum = 0, count = 0;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (i % j == 0)
				sum += j;
		}
		if (sum == i)
			count++;
		sum = 0;
	}
	return count;
}

int main()
{
	int n, count;
	while (cin >> n)
	{
		count = COUNT(n);
		cout << count << endl;
	}
	return 0;
}