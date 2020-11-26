#include<iostream>
#include<algorithm>
#include<vector>

#include<string>
using namespace std;


//Ì°ÐÄËã·¨
int main()
{
	int n;
	while (cin >> n)
	{
		long long sum = 0;
		vector<int> a;
		a.resize(3 * n);
		for (int i = 0; i < (3 * n); i++)
		{
			cin >> a[i];
		}

		std::sort(a.begin(), a.end());
		for (int i = n; i <= 3 * n - 2; i += 2)
		{
			sum += a[i];
		}
		cout << sum << endl;
	}
}

int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);

	int hashtable[256] = { 0 };
	for (size_t i = 0; i < s2.size(); ++i)
	{
		hashtable[s2[i]]++;
	}
	string ret;
	for (size_t i = 0; i < s1.size(); ++i)
	{
		if (hashtable[s1[i]] == 0)
			ret += s1[i];
	}

	cout << ret << endl;
	return 0;
}









