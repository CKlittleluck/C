#include <iostream>
using namespace std;

int num(int n)
{
	int sum = 0;
	while (n > 1)
	{
		int result = n / 3;
		int reminder = n % 3;
		sum = sum + result;
		n = result + reminder;
		if (n == 2)
		{
			sum++;
			break;
		}
	}
	return sum;
}

int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
			return 0;
		int ret = num(n);
		cout << ret << endl;
	}
	return 0;
}