class Bonus {
public:
	int getMost(vector<vector<int> > board) {
		// write code here
		int row = board.size();
		int col = board[0].size();

		vector<vector<int>> allprice(row, vector<int>(col, 0));
		allprice[0][0] = board[0][0];

		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (i == 0 && j == 0)
					continue;

				if (i == 0)
				{
					allprice[i][j] = allprice[i][j - 1] + board[i][j];
				}
				else if (j == 0)
				{
					allprice[i][j] = allprice[i - 1][j] + board[i][j];
				}
				else
					allprice[i][j] = max(allprice[i][j - 1], allprice[i - 1][j]) + board[i][j];
			}
		}
		return allprice[row - 1][col - 1];
	}
};