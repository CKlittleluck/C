#define _CRT_SECURE_NO_WARNINGS  1class Solution {
public:
	int StrToInt(string str) 
	{
		const int len = str.length();
		if (len == 0) 
			return 0;
		int i = 0;
		while (i < len && str[i] == ' ') 
		{ 
			++i;
		} 
		// 排除开头的空格
		if (i == len) 
			return 0;
		if (!isdigit(str[i]) && str[i] != '+' && str[i] != '-') 
			return 0;
		bool neg = str[i] == '-' ? true : false;
		i = isdigit(str[i]) ? i : i + 1;
		long long ans = 0L;

		while (i < len && isdigit(str[i]))
		{
			ans = ans * 10 + (str[i++] - '0');

			if (!neg && ans > INT_MAX) 
			{
				ans = INT_MAX;
				break;
			}
			if (neg && ans > 1L + INT_MAX) 
			{
				ans = 1L + INT_MAX;
				break;
			}
		}
		if (i != len) 
			return 0; // 不要此处，就是atoi()库函数的实现
		return !neg ? static_cast<int>(ans) : static_cast<int>(-ans);
	}
};


class Solution {
public:
	int StrToInt(string str) {
		int sum = 0;
		int flag = 1;
		if (str.empty())
		{
			return 0;
		}

		if (str[0] == '-')
		{
			flag = -1;
			str[0] = '0';
		}
		if (str[0] == '+')
		{
			flag = 1;
			str[0] = '0';
		}

		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] < '0' || str[i] > '9')
			{
				sum = 0;
				break;
			}

			sum = sum * 10 + str[i] - '0';
		}
		return sum * flag;
	}
};