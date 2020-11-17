#include<iostream>
using namespace std;


class Solution
{
public:
	bool IsValidchar(char ch)
	{
		if ((ch >= 'a' && ch <= 'z') ||
			(ch >= '0' && ch <= '9'))
		{
			return true;
		}
		return false;
	}


	bool isPalindrome(string s)
	{
		if (s.empty())
		{
			return true;
		}
		for (auto& e : s)
		{
			if (e >= 'A' && e <= 'Z')
				e += 32;
		}

		size_t begin = 0, end = s.size() - 1;
		while (begin < end)
		{
			if (IsValidchar(s[begin]))
				break;
			begin++;
		}

		while (begin < end)
		{
			if (IsValidchar(s[end]))
				break;
			end--;
		}

		if (begin != end)
		{
			if (s[begin] != s[end])
				return false;

			begin++;
			end--;
		}
	return true;
	}
};


//×Ö·û´®Ïà¼Ó
class Solution
{
public:
	string addStrings(string num1,string num2)
	{
		if (num1.size() < num2.size())
		{
			num1.swap(num2);
			//swap(num1,num2);
		}

		string strRet(num1.size() + 1, '0');

		char step = 0;
		for (int iLidx = num1.size() - 1, iRidx = num2.size() - 1;
			iLidx >= 0;
			--iLidx, --iRidx)
		{
			char ch = num1[iLidx] - '0' + step;
			if (iRidx >= 0)
				ch += num2[iRidx] - '0';
			step = 0;
			if (ch >= 10)
			{
				step = 1;
				ch -= 10;
			}

			strRet[iLidx + 1] += ch;
		}

		if (step == 1)
			strRet[0] = 1;
		else
			strRet.erase(strRet.begin());
		return strRet;
	}
};



int main()
{
	string s1("0");
	string s2("0");
	Solution s;
	string strRet = s.addStrings(s1, s2);
	return 0;
}


