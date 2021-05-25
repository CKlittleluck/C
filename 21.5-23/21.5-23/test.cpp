#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int T, n, k;
	cin >> T;
	while (T--)
	{
		cin >> n >> k;
		int num = 2 * n;
		vector<int> card(num);
		for (int i = 0; i < num; ++i)
		{
			cin >> card[i];
		}

		while (k--)
		{
			vector<int> temp(card.begin(), card.end());
			for (int j = 0; j < n; ++j)
			{
				card[2 * j] = temp[j];
				card[2 * j + 1] = temp[j + n];
			}
		}
		for (int i = 0; i < num - 1; ++i)
		{
			cout << card[i] << " ";
		}
		cout << card[num - 1] << endl;
	}
	return 0;
}
