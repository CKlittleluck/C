class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		int row = triangle.size();
		int col = triangle[0].size();
		vector<vector<int>> minsum(triangle);
		for (int i = 1; i < row; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				if (j == 0)
					minsum[i][j] = minsum[i - 1][j] + triangle[i][j];
				else if (j == i)
					minsum[i][j] = minsum[i - 1][j - 1] + triangle[i][j];
				else
					minsum[i][j] = min(minsum[i - 1][j] + triangle[i][j], minsum[i - 1][j - 1] + triangle[i][j]);
			}
		}
		int ret = minsum[row - 1][0];
		for (int i = 0; i < row; i++)
		{
			ret = min(ret, minsum[row - 1][i]);
		}
		return ret;
	}
};

