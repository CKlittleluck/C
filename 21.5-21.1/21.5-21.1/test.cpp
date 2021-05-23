#include <iostream>
#include <string>
using namespace std;

string Reverse(string &str)
{
	if (str.empty())
		return 0;
	size_t start = 0;
	size_t end = str.size() - 1;
	while (start < end)
	{
		swap(str[start], str[end]);
		start++;
		end--;
	}
	return str;
}

int main()
{
	string str, res;
	getline(cin, str);
	res = Reverse(str);
	cout << res << endl;
	return 0;
}