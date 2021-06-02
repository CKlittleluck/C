#include <iostream>
#include <vector>
using namespace std;

int ADD(int power, int k)
{
	while (int c = power % k)
	{
		power = k;
		k = c;
	}
	return k;
}


int main()
{
	int n, power;
	vector<int> num;
	while (cin >> n >> power)
	{
		num.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> num[i];
		}
		for (int k = 0; k < n; k++)
		{
			if (num[k] < power)
			{
				power += num[k];
			}
			else
			{
				power += ADD(power, num[k]);
			}
		}
		cout << power << endl;
	}
	return 0;
}