#include <iostream>
#include <string>
#include <unordered_set>
#include <stdio.h>
using namespace std;
int main()
{
	string name;
	while (getline(cin, name))
	{
		unordered_set<string> s;
		int i = 0, end = 0;
		while (i < name.size())
		{
			if ('\"' == name[i])
			{
				end = name.find('\"', i + 1);
				s.insert(name.substr(i + 1, end - i - 1));
				i = end + 2;
			}
			else
			{
				end = name.find(',', i + 1);
				if (end == string::npos)
				{
					s.insert(name.substr(i, name.size()));
					break;
				}
				s.insert(name.substr(i, end - i));
				i = end + 1;
			}
		}

		getline(cin, name);
		if (s.find(name) == s.end())
		{
			printf("Important!\n");
		}
		else
		{
			printf("Ignore\n");
		}
	}
	return 0;
}