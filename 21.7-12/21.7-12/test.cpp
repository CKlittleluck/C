#include <iostream>
#include <vector>
using namespace std;

int direct[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

void dfs(vector<vector<char>> &map, int m, int n, int x, int y, vector<vector<bool>> &flag, size_t &count)
{
	if (flag[x][y])
	{
		return;
	}

	if ('#' == map[x][y])
	{
		return;
	}

	++count;
	flag[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + direct[i][0];
		int ny = y + direct[i][1];
		if (nx >= 0 && nx < m && ny >= 0 && ny < n)
		{
			dfs(map, m, n, nx, ny, flag, count);
		}
	}
}


int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		vector<vector<char>> map(m, vector<char>(n));
		int x = 0, y = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
				if ('@' == map[i][j])
				{
					x = i;
					y = j;
				}
			}
		}
		vector<vector<bool>> flag(m, vector<bool>(n));
		size_t count = 0;
		dfs(map, m, n, x, y, flag, count);
		cout << count << endl;
	}
	return 0;
}