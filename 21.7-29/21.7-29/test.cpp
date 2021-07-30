#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string s, table = "0123456789ABCDEF";
	int a, b;
	cin >> a >> b;
	bool flag = false;

	if (a < 0)
	{
		a = 0 - a;
		flag = true;
	}

	while (a)
	{
		s += table[a % b];
		a /= b;
	}

	if (flag)
	{
		s += '-';
	}

	reverse(s.begin(), s.end());
	cout << s << endl;
	return 0;
}