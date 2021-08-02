#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int H, W;
	int res = 0;
	cin >> H >> W;
	vector<vector<int>> v(W);
	for (auto & e : v)
	{
		e.resize(H, 1);
	}
	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < H; j++)
		{
			if (v[i][j] == 1)
			{
				res++;
				if ((i + 2) < W)
				{
					v[i + 2][j] = 0;
				}
				if ((j + 2) < H)
				{
					v[i][j + 2] = 0;
				}
			}
		}
	}
	cout << res << endl;
}