#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
	int f = 0, f1 = 1, f2;
	int left, right, N;
	cin >> N;
	while (1)
	{
		f2 = f + f1;
		f = f1;
		f1 = f2;
		if (f < N)
		{
			left = f;
		}
		else
		{
			right = f;
			break;
		}
	}
	cout << min(N - left, right - N);
	return 0;
}