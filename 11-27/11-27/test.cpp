#include<iostream>
using namespace std;
#include<string>;

//bool huiwen(string s)
//{
//	int begin = 0;
//	int end = s.size() - 1;
//	while (begin < end)
//	{
//		if (s[begin] != s[end])
//			return false;
//		else
//		{
//			++begin;
//			--end;
//		}
//	}
//	return true;
//}
//
//int main()
//{
//	int count = 0;
//	string s;
//	string s1;
//	char b;
//	int size = s.size();
//	cin >> s >> b;
//	for (int i = 0; i <size; i++)
//	{
//		s1.insert = (i, b);
//		if (huiwen(s))
//			count++;
//	}
//	cout << count << endl;
//}





int main()
{
	int sum = 0;
	int max = 0;
	int a[100] = { 0 };
	cin >> a[100];
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		while (a[i] >= 0)
		{
			sum += a[i];
		}
		if (sum >= max)
		{
			max = sum;
		}
	}
	cout << max << endl;
	return 0;
}