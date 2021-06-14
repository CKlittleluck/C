#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int f_arry[10000] = { 0, 1, 2 };
	for (int i = 3; i < 10001; i++)
	{
		f_arry[i] = f_arry[i - 1] + f_arry[i - 2];
		f_arry[i] %= 10000;
	}

	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			int num;
			cin >> num;
			printf("%04d", f_arry[num]);
		}
		cout << endl;
	}
	return 0;
}