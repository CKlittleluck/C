#include <iostream>
#include <string>
using namespace std;

bool IsCircleText(const string& str)
{
	size_t begin = 0;
	size_t end = str.size() - 1;
	while (begin < end)
	{
		if (str[begin] != str[end])
		{
			return false;
		}
		++begin;
		--end;
	}
	return true;
}

int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	size_t count = 0;
	for (size_t i = 0; i <= str1.size(); ++i)
	{
		string str = str1;
		str.insert(i, str2);
		if (IsCircleText(str))
		{
			++count;
		}
	}
	cout << count << endl;
	return 0;
	return 0;
}