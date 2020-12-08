#include<iostream>
#include<vector>
#include<string>
using namespace std;

//两种排序方法
//int main()
//{
//	int n;
//	cin >> n;
//	vector<string> v;
//	v.resize(n);
//	for (auto &str : v)
//		cin >> str;
//	bool lensym = true, lexsym = true;
//	for (size_t i = 1; i < v.size(); ++i)
//	{
//		if (v[i - 1].size() >= v[i].size())
//		{
//			lensym = false;
//			break;
//		}
//	}
//
//	for (size_t i = 1; i < v.size(); ++i)
//	{
//		if (v[i - 1] >= v[i])
//		{
//			lexsym = false;
//			break;
//		}
//	}
//
//	if (lensym && lexsym)
//		cout << "both" << endl;
//
//	else if (!lensym && lexsym) 
//		cout << "lexicographically" << endl; 
//	else if (lensym && !lexsym) 
//		cout << "lengths" << endl; 
//	else if (!lensym&&!lexsym) 
//		cout << "none" << endl;
//	return 0;
//}


//求最小公倍数
int gcd(int a, int b)
{
	int r;
	while (r = a%b)
	{
		a = b;
		b = r;
	}
	return b;
}

int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		cout << (a*b) / gcd(a, b) << endl;
	}
	return 0;
}