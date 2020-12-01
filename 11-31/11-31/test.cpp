#include<iostream>
using namespace std;
#include<algorithm>
#include<string>

//int main()
//{
//	int a, b, c, d;
//	cin >> a >> b;
//	if (a >= b)
//		c = a;
//	else
//		c = b;
//	for (int i = 1; i <= c; ++i)
//	{
//		d = c * i;
//		if ((d%a == 0) && (d%b == 0))
//		{
//			cout << d << endl;
//			break;
//		}
//		else
//			++i;
//	}
//	return 0;
//}



//统计回文
bool IScircleText(const string &s)
{
	size_t begin = 0;
	size_t end = s.size() - 1;
	while (begin < end)
	{
		if (s[begin] != s[end])
		{
			return false;
		}
		++begin;
		--end;
	}
	return true;
}

int main()
{
	std::string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	size_t count = 0;
	for (size_t i = 0; i <= s1.size(); ++i)
	{
		string str = s1;
		str.insert(i, s2);
		if (IScircleText(str))
			++count;
	}
	cout << count << endl;
	return 0;
}


