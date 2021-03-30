class Solution {
public:
	bool canWinNim(int n) {
		if (n >= 1 && n <= INT_MAX)
		{
			if (n % 4 != 0)
			{
				return true;
			}
		}
		return false;
	}
};