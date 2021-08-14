#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		if (str1.size() > str2.size())
		{
			swap(str1, str2);
		}
		int len1 = str1.size();
		int len2 = str2.size();
		int i, j, start = 0, max = 0;
		vector<vector<int>> vec(len1 + 1, vector<int>(len2 + 1, 0));
		for (i = 1; i <= len1; i++)
		{
			for (j = 1; j <= len2; j++)
			{
				if (str1[i - 1] == str2[j - 1])
					vec[i][j] = vec[i - 1][j - 1] + 1;
				if (vec[i][j] > max)
				{
					max = vec[i][j];
					start = i - max;
				}
			}
		}
		cout << str1.substr(start, max) << endl;
	}
	return 0;
}