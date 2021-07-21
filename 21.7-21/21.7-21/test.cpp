#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	long long sum = 0;
	while (cin >> n)
	{
		vector<int> v(3 * n);
		for (int i = 0; i < 3 * n; i++)
		{
			cin >> v[i];
		}
		std::sort(v.begin(), v.end());
		for (int i = 0; i < n; i++)
		{
			sum += v[v.size() - 2 * (i + 1)];
		}
		cout << sum << endl;
	}
}