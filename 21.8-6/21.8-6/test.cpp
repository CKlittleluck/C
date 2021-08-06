#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0, maxcount = 0;
		/*while(n)
		{
		if(n & 1)
		{
		count++;
		maxcount = max(count, maxcount);
		}
		else
		count = 0;
		n = n >> 1;
		}*/

		for (int i = 0; i < 32; i++)
		{
			if (n & (1 << i))
			{
				count++;
				maxcount = max(count, maxcount);
			}
			else
				count = 0;
		}
		cout << maxcount << endl;
	}
	return 0;
}