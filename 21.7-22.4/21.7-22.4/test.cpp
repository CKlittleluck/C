#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str1;
	int count = 0;
	while (getline(cin, str1))
	{
		char* pleft = (char*)str1.c_str();
		char* pright = pleft + str1.size() - 1;
		for (int i = 0; i < str1.size(); ++i)
		{
			while (*pright != ' ')
			{
				if (pleft == pright)
				{
					count++;
					break;
				}
				--pright;
				count++;
			}
			break;
		}
		cout << count << endl;
	}
	return 0;
}



int main()
{
	string str1;
	while (getline(cin, str1))
	{
		ssize_t pos = str1.rfind(' ');
		cout << str1.size() - pos - 1;
	}
	return 0;
}