//�� n ����Ʒ��һ����СΪ m �ı���.�������� A ��ʾÿ����Ʒ�Ĵ�С������ V ��ʾÿ����Ʒ�ļ�ֵ.
//�������װ�뱳�����ܼ�ֵ�Ƕ�� ?

public int backPackII(int m, int[] A, int[] V) {
	int n = A.size();
	if (n == 0 || m == 0)
	{
		return 0;
	}

	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (A[i - 1] < j)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - A[i - 1]] + v[i - 1]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	return dp[n][m];
}