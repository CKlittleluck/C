#include <iostream>
#include <string>
#include <set>
#include <stdio.h>
using namespace std;

int main()
{
	int n;
	string id, op;
	while (cin >> n)
	{
		set <string> s;
		size_t MaxCon = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> id >> op;
			if ("connect" == op)
				s.insert(id);
			else
				s.erase(id);

			MaxCon = max(MaxCon, s.size());
		}
		cout << MaxCon << endl;
	}
	return 0;
}