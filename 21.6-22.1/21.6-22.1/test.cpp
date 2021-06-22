#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	while (cin >> n)
	{
		if (n == 0)
		{
			return 0;
		}

		int count = 0;
		while (n > 1)
		{
			count++;
			n = n / 3 + (n % 3 > 0);
		}
		cout << count << endl;
	}
	return 0;
}