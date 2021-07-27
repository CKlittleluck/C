#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string str1, str2, cur;
	cin >> str1;
	for (int i = 0; i <= str1.size(); ++i)
	{
		if (str1[i] >= '0' && str1[i] <= '9')
		{
			cur += str1[i];
		}
		else
		{
			if (str2.size() < cur.size())
			{
				str2 = cur;
			}
			else
			{
				cur.clear();
			}
		}
	}
	cout << str2 << endl;
	return 0;
}