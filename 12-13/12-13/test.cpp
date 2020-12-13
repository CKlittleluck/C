#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


//24979-最近公共祖先
class Lca
{
public:
	int getLca(int a, int b)
	{
		while (a != b)
		{
			if (a > b)
				a /= 2;
			else
				b /= 2;
		}
		return a;
	}
};


//36910-求最大连续bit数
int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0, maxcount = 0;
		while (n)
		{
			if (n & 1)
			{
				++count;
				maxcount = max(count, maxcount);
			}
			else
			{
				count = 0;
			}
			n = n >> 1;
		}
		cout << maxcount << endl;
	}
	return 0;
}