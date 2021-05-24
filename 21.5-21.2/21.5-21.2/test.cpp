#include <iostream>
#include <vector>
#include <string>
using namespace std;


int GetMax(const string &str1, const string &str2)
{
	int len1 = str1.size();
	int len2 = str2.size();

	vector<vector<int>> msc(len1, vector<int>(len2, 0));
	int max = 0;
	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			if (str1[i] == str2[j])
			{
				if (i >= 1 && j >= 1)
				{
					msc[i][j] = msc[i - 1][j - 1] + 1;
				}
				else
					msc[i][j] = 1;
			}
			if (msc[i][j] > max)
				max = msc[i][j];
		}
	}
	return max;
}

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		int ret = GetMax(str1, str2);
		cout << ret << endl;
	}
	return 0;
}