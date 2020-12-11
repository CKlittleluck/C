#include <iostream>
#include <vector>
using namespace std;


//完美数
int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		for (int i = 1; i < n; ++i)
		{
			int s = 0;
			for (int j = 1; j < i; ++j)
			{
				if (i % j == 0)
					s = s + j;
			}
			if (s == i)
				++count;
		}
		cout << count << endl;
	}
	return 0;
}



//36915-求路径总数
int PathNum(int n, int m)
{
	if (n > 1 && m > 1)
	{
		return PathNum(n - 1, m) + PathNum(n, m - 1);
	}
	else if (((n >= 1) && (m == 1)) || ((n == 1) && (m >= 1)))
		return n + m;
	else
		return 0;
}


int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		cout << PathNum << endl;
	}
	return 0;
}

