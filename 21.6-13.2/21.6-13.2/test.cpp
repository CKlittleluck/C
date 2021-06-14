#include <iostream>
#include <vector>
using namespace std;

int row, col;
vector<vector<int>> maze;
vector<vector<int>> path_tmp;
vector<vector<int>> path_best;

void MazeTrack(int i, int j)
{
	maze[i][j] = 1;
	path_tmp.push_back({ i, j });

	if (i == row - 1 && j == col - 1)
	{
		if (path_best.empty() || path_best.size() > path_tmp.size())
		{
			path_best = path_tmp;
		}
	}

	if (j + 1 < col && maze[i][j + 1] == 0)
		MazeTrack(i, j + 1);

	if (j - 1 >= 0 && maze[i][j + 1] == 0)
		MazeTrack(i, j - 1);

	if (i - 1 >= 0 && maze[i - 1][j] == 0)
		MazeTrack(i - 1, j);

	if (i + 1 <= row && maze[i + 1][j] == 0)
		MazeTrack(i + 1, j);

	maze[i][j] = 0;
	path_tmp.pop_back();
}




int main()
{
	while (cin >> row >> col)
	{
		path_tmp.clear();
		path_best.clear();
		maze = vector<vector<int>>(row, vector<int>(col, 0));
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				cin >> maze[i][j];
			}
		}
	}
	MazeTrack(0, 0);

	for (int i = 0; i < path_best.size(); ++i)
	{
		cout << "(" << path_best[i][0] << "," << path_best[i][1] << ")" << endl;
	}

	return 0;
}