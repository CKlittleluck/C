#include<iostream>
using namespace std;



//反转字母

class Solutio
{
public:
	string reverseOnlyLetters(string s)
	{
		if (s.empty())
			return s;
		size_t begin = 0, end = s.size() - 1;
		while (begin < end)
		{
			while (begin < end)
			{
				if (isalpha(s[begin]))
					break;
				++begin;
			}
			while (begin < end)
			{
				if (isalpha(s[end]))
					break;
				--end;
			}
			if (begin != end)
			{
				swap(s[begin], s[end]);
				begin++;
				end--;
			}
		}
		return s;
	}
};


//找第一次出现不重复的字符
class Solution
{
public:
	int firstUniqChar(string s)
	{
		size_t count[256] = { 0 };
		for (auto e : s)
		{
			count[e]++;
		}

		for (size_t i = 0; i < s.size(); ++i)
		{
			if (count[s[i]] == 1)
				return i;
		}
		return -1;

	}
};