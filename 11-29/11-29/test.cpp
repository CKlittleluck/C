#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>


//class Solution {
//public:
//	int StrToInt(string str) {
//		int length = str.length();
//		if (length < 1)
//		{
//			return 0;
//		}
//	}
//};


//int func() 
//{ 
//	int i, j, k = 0; 
//	for (i = 0, j = -1; j = 0; i++, j++) 
//	{ k++; } 
//	return k; 
//}
//int main() 
//{ 
//	cout << (func()); 
//}


//字符串中找出连续最长的数字串

int main()
{
	string str, res, cur;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			cur += str[i];
		}
		else
		{
			if (res.size() < cur.size())
			{
				res = cur;
			}
			else
				cur.clear();
		}
	}
	cout << res;
	return 0;
}


//数组中出现次数超过一半的数字
//1
class Solution{
public:
	int _solution(vector<int> numbers)
	{
		if (numbers.empty())
			return 0;
		sort(numbers.begin(), numbers.end());
		int mid = numbers[numbers.size() / 2];

		int count = 0;
		for (int i = 0; i < numbers.size(); ++i)
		{
			if (numbers[i] == mid)
				count++;
		}
		return (count > numbers.size() / 2) ? mid : 0;
	}
};


//2
class solution{
public:
	int _solution(vector<int> numbers)
	{
		if (numbers.empty())
			return 0;

		int result = numbers[0];
		int time = 1;

		for (int i = 1; i < numbers.size(); ++i)
		{
			if (time == 0)
			{
				result = numbers[i];
				time = 1;
			}
			else if (numbers[i] == result)
			{
				++time;
			}
			else{
				--time;
			}
		}

		time = 0;
		for (int i = 0; i < numbers.size(); ++i)
		{
			if (numbers[i] == result)
				++time;
		}
		return(time > numbers.size() / 2) ? result : 0;
	}
};
