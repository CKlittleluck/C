#include <iostream>
using namespace std;


class Solution 
{
public:
	int myAtoi(string s) 
{
		int i = 0;
		long long sum = 0;
		bool flag = false, symbol = true;//flag为读取标志，为真时读取数字.symbol为sum的符号：正true，负false
		while (i < s.length()){//判断是否超出限制
			if (!flag && s[i] != ' ') //如果没有开始读取且不是空格
			if (s[i] == '+' || s[i] == '-' || s[i] >= '0' && s[i] <= '9'){//就可以开始读数据
				flag = true;//置标志为真
				if (s[i] == '-') symbol = false, i++;//如果是符号则后面不用读了，直接跳
				else if (s[i] == '+') i++;//symbol默认true（正）不用赋值
			}
			else return 0;//第一个非空字符非法，返回0
			if (flag && !(s[i] >= '0' && s[i] <= '9')) if (!symbol) return -sum; else return sum;//如果读取的过程中遇到非法字符，则根据符号返回当前值
			if (flag) sum = sum * 10 + s[i] - '0';//那么接下来就是合法的，直接加
			if (sum > INT_MAX && symbol) return INT_MAX;//（**正**）超出最大值，返回最大值
			else if (sum > INT_MAX && !symbol) return INT_MIN;//（**负**）由于单独使用符号位，所以是以整数来表示的，超出正数上限，返回负数下限。
			i++;//向后遍历
		}
		if (!symbol) return -sum;//最后再根据符号返回值
		else return sum;
	}
};

