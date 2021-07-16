#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string m, n;
	while (cin >> m >> n)
	{
		vector<vector<int>> map(m.size() + 1, vector<int>(n.size() + 1));
		for (size_t i = 1; i <= m.size(); ++i)
		{
			for (size_t j = 1; j <= n.size(); ++j)
			{
				if (m[i - 1] == n[j - 1])
					map[i][j] = map[i - 1][j - 1] + 1;
				else
					map[i][j] = max(map[i - 1][j], map[i][j - 1]);
			}
		}
		cout << map[m.size()][n.size()] << endl;
	}
	return 0;
}