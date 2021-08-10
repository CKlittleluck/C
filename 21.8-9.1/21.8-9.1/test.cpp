#include <iostream>
#include <string>
#include <vector>
using namespace std;
void Divide(const string &str)
{
	vector<string> vec;
	string tmp = "";
	bool flag = false;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ' && !flag)
		{
			vec.push_back(tmp);
			tmp = "";
		}
		else if (str[i] == '"')
		{
			flag = !flag;
		}
		else
		{
			tmp += str[i];
		}
	}
	vec.push_back(tmp);
	cout << vec.size() << endl;
	for (auto x : vec)
	{
		cout << x << endl;
	}
}

int main()
{
	string str;
	while (getline(cin, str))
	{
		Divide(str);
	}
	return 0;
}