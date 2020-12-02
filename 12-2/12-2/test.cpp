#include<iostream>
#include<string>
using namespace std;

//
//int main()
//{
//	int w,h,res = 0;
//	cin >> w >> h;
//	vector<vector<int>> a;
//	a.resize(w);
//	for (auto & e : a)
//		e.resize(h, 1);
//	for (int i = 0; i < w; i++)
//	{
//		for (int j = 0; j < h; j++)
//		{
//			if (a[i][j] == 1)
//			{
//				res++;
//				if ((i + 2) < w)
//					a[i + 2][j] = 0;
//				if ((j + 2) < h)
//					a[i][j + 2] = 0;
//			}
//		}
//	}
//	cout << res;
//	return 0;
//}


//int main()
//{
//	int c0=0 ;
//	int n =0;
//	string s, table = "0123456789ABCDEF";
//	size_t i;
//	int begin = 0,end = s.size() - 1;
//	int m;
//	cin >> m ;
//	bool flag = false;
//	if (m < 0)
//	{
//		m = 0 - m;
//		flag = true;
//	}
//	while (m)
//	{
//		s += table[m%2];
//		m /= 2;
//	}
//	if (flag)
//		s += '-';
//	reverse(s.begin(), s.end());
//	while (begin < end)
//	{
//		if (s[begin] == 0)
//		{
//			c0 = 2 * c0;
//			n += 1;
//			++begin;
//		}
//		else
//		{
//			c0 += 1;
//			c0 = 2 * c0;
//			n += 2;
//			++begin;
//		}
//	}
//		cout << n << c0 << endl;
//		return 0;
//	}


//#include<stdio.h>
//#include <stdlib.h>//用到rand()函数
//#include<time.h>   //用到clock()函数
//int main()
//{
//	int begintime, endtime;
//	//int a[1002];
//	begintime = clock(); //计时开始
//				/*string s, table = "0123456789ABCDEF";
//				size_t i;
//				int begin = 0,end = s.size() - 1;
//				int m;
//				cin >> m ;
//				bool flag = false;
//				if (m < 0)
//				{
//					m = 0 - m;
//					flag = true;
//				}
//				while (m)
//				{
//					s += table[m%2];
//					m /= 2;
//				}
//				if (flag)
//					s += '-';
//				reverse(s.begin(), s.end());
//				cout << s << endl;*/
//	endtime = clock(); //计时结束
//	printf("\n\nRunning Time：%dms\n", endtime - begintime);
//	return 0;
//}



//字符串转成整数
class Solution
{
public:
	int strtoint(string str)
	{
		if (str.empty())
			return 0;
		int symbol = 1;
		if (str[0] == '-')
		{
			symbol = -1;
			str[0] = '0';
		}
		else if (str[0] == '+')
		{
			symbol = 1;
			str[0] = '0';
		}
		int sum = 0;
		for (int i = 0;i<str.size())
	}
}