class Solution {
public:
	/**
	*	正数数组中的最小不可组成和
	*	输入：正数数组arr
	*	返回：正数数组中的最小不可组成和
	*/
	int getFirstUnFormedNum(vector<int> arr, int len) {
		int sum = 0;
		int min = arr[0];
		int i, j;
		for (i = 0; i < len; i++)
		{
			sum += arr[i];
			if (arr[i] < min)
			{
				min = arr[i];
			}
		}

		std::vector<int> dp(sum + 1, 0);
		for (i = 0; i < len; i++)
		{
			for (int j = sum; j >= arr[i]; j--)
			{
				if (dp[j] < dp[j - arr[i]] + arr[i])
				{
					dp[j] = dp[j - arr[i]] + arr[i];
				}
				else
				{
					dp[j] = dp[j];
				}
			}
		}

		for (i = min; i <= sum; i++)
		{
			if (i != dp[i])
			{
				return i;
			}
		}
		return sum + 1;
	}
};