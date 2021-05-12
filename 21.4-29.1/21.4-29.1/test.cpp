#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector <string> v;
	int n;
	cin >> n;
	v.resize(n);
	bool changdu = true, zidian = true;
	for (auto &str : v)
		cin >> str;
	for (int i = 1; i < n; i++)
	{
		if (v[i - 1].size() > v[i].size())
		{
			changdu = false;
			break;
		}
	}

	for (int i = 1; i < n; i++)
	{
		if (v[i - 1] > v[i])
		{
			zidian = false;
			break;
		}
	}

	if (changdu && zidian)
	{
		cout << "both" << endl;
	}
	else if (changdu)
	{
		cout << "lengths" << endl;
	}
	else if (zidian)
	{
		cout << "lexicographically" << endl;
	}
	else
	{
		cout << "none" << endl;
	}
	return 0;
}