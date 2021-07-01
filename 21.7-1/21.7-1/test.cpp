#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void factorization(int a, vector<int> &factors)
{
	factors.clear();
	for (int i = 2; i * i <= a && a > 1; i++)
	{
		while (a % i == 0)
		{
			factors.push_back(i);
			a = a / i;
		}
	}
	if (a > 1)
	{
		factors.push_back(a);
	}
}


int main()
{
	vector<int> factors;
	int a;
	while (cin >> a)
	{
		factorization(a, factors);
		printf("%d = ", a);
		for (vector<int>::const_iterator p = factors.begin(); p != factors.end(); ++p)
		{
			printf("%d", *p);
			if (p != factors.end() - 1)
			{
				printf(" * ");
			}
		}
		printf("\n");
	}
}