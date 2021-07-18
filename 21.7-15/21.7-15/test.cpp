#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define N 20

int Count(const vector<string> &map, int x, int y, char ch)
{
	int maxc = 0;
	int dir[4][2][2] = {
		{ { -1, 0 }, { 1, 0 } },
		{ { 0, -1 }, { 0, 1 } },
		{ { -1, -1 }, { 1, 1 } },
		{ { -1, 1 }, { 1, -1 } }
	};
	for (int i = 0; i < 4; ++i)
	{
		int c = 0;
		for (int j = 0; j < 2; ++j)
		{
			int nx = x, ny = y;
			while (nx >= 0 && nx < N && ny >= 0 && ny < N && map[nx][ny] == ch)
			{
				nx += dir[i][j][0];
				ny += dir[i][j][1];
				++c;
			}
		}
		maxc = (maxc > c ? maxc : c);
	}
	return maxc - 1;
}


bool sover(const vector<string> &map)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (map[i][j] == '*' || map[i][j] == '+')
			{
				if (Count(map, i, j, map[i][j]) >= 5)
				{
					return true;
				}
			}
		}
	}
	return false;
}


int main()
{
	string str;
	while (cin >> str)
	{
		vector<string> map(N);
		map[0] = str;
		for (int i = 1; i < N; ++i)
		{
			cin >> map[i];
		}

		cout << (sover(map) ? "Yes" : "No") << endl;
	}
	return 0;
}