#include <iostream>
using namespace std;
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		int count = 0;
//		if (n <= 3)
//			count = 1;
//		cout << count << endl;
//	}
//}

#include <iostream>
using namespace std;
int get_num(int n)
{
	if (n <= 3)
		return 1;
	else
		return get_num(n - 1) + get_num(n - 2);
}
int main()
{
	int n;
	while (cin >> n)
	{
		int ret = get_num(n);
		cout << ret << endl;
	}
	return 0;
}


