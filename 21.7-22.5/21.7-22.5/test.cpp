#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n + 1);
	v[n] = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	int count = 0;
	int i = 0;
	while (i < n)
	{
		if (v[i] < v[i + 1])
		{
			while (v[i] <= v[i + 1])
			{
				i++;
			}
			count++;
			i++;
		}
		else if (v[i] == v[i + 1])
		{
			i++;
		}
		else
		{
			while (v[i] >= v[i + 1])
			{
				i++;
			}
			count++;
			i++;
		}
	}
	cout << count << endl;
	return 0;
}