#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int sz = array.size();
		vector<int> dp(sz + 1, 0);
		int ret = array[0];
		for (int i = 1; i <= sz; i++){
			dp[i] = max(array[i - 1], dp[i - 1] + array[i - 1]);
			ret = max(dp[i], ret);
		}
		return ret;
	}
};