#include <iostream>
#include<algorithm>
using namespace std;

//36884-查找组成一个偶数最接近的两个素数
bool Isprime(int n)
{
	int m = sqrt(n);
	for (int i = 2; i <= m; ++i)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int half;
	int n, i;
	while (cin >> n)
	{
		half = n / 2;
		for (i = half; i > 0; --i)
		{
			if (Isprime(i) && Isprime(n - i))
				break;
		}
		cout << i << endl << n - i << endl;
	}
	return 0;
}

