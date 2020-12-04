#include<iostream>
using namespace std;
#include<algorithm>


//int main()
//{
//	int a,sum = 0, count;
//	cin >> a;
//	while (a)
//	{
//		if (a % 2 == 1)
//			++count;
//		else if (sum >= count)
//		{
//			sum = count;
//		}
//		a /= 2;
//		count = 0;
//	}
//	cout << sum << endl;
//	return 0;
//}


//int main()
//{
//	string s,table = "0123456789ABCDEF";
//	size_t i;
//	int m;
//	cin >> m;
//	while (m)
//	{
//		int count = 0, max = 0;
//		s += table[m % 2];
//		m /= 2;
//		for (i = 0; i < s.size(); i++)
//		{
//			if (s[i] == 0)
//				count = 0;
//			else
//			{
//				count++;
//				if (count > max)
//					max = count;
//			}
//		}
//		cout << count << endl;
//	}
//}

int main()
{
	int n;
	while (cin >> n)
	{
		int a = 0, Max = 0;
		while (n != 0)
		{
			if (n % 2 == 1)
			{
				++a;
			}
			else if (n % 2 == 0)
			{
				Max = max(a, Max);
				a = 0;
			}
			n = n / 2;
		}
		Max = max(a, Max);
		cout << Max << endl;
	}
	return 0;
}





