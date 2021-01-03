#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

	// ³¢ÊÔÓÃ»ØËİ
	int path = 0;
	bool backtracking(vector<int>& nums, int level, vector<bool>& used) {
		if (path == nums.size() - 1) {
			return true;
		}
		if (path > nums.size() - 1) {
			return false;
		}

		for (int i = nums[level]; i >= 1; i--) {
			if (false == used[path + i]) {
				return false;
			}
			path += i;
			used[path] = false;
			if (true == backtracking(nums, level + i, used)) {
				return true;
			}
			path -= i;
		}
		return false;
	}

	bool canJump(vector<int>& nums) {
		vector<bool> used(nums.size(), true);
		return backtracking(nums, 0, used);
	}
};

