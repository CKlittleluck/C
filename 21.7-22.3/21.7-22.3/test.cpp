class Solution {
public:
	int firstUniqChar(string s) {
		int hashtable[256] = { 0 };
		for (int i = 0; i < s.size(); ++i)
		{
			hashtable[s[i]]++;
		}

		for (int i = 0; i < s.size(); ++i)
		{
			if (hashtable[s[i]] == 1)
			{
				return i;
			}
		}
		return -1;
	}
};