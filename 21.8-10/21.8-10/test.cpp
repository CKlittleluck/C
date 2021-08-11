#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> vec(n);
		vec[0] = vec[1] = 1;
		for (int i = 2; i < n; i++)
		{
			vec[i] = vec[i - 1] + vec[i - 2];
		}
		cout << vec[n - 1] << endl;
	}
	return 0;
}



#include <iostream>
#include <string>

using namespace std;

bool match(const char* str1, const char* str2)
{
	if (*str1 == '\0' && *str2 == '\0')
		return true;
	if (*str1 == '\0' || *str2 == '\0')
		return false;
	if (*str1 == '?')
		return match(str1 + 1, str2 + 1);
	else if (*str1 == '*')
		return  match(str1 + 1, str2 + 1) || match(str1, str2 + 1) || match(str1 + 1, str2);
	else if (*str1 == *str2)
		return match(str1 + 1, str2 + 1);
	return false;
}

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		bool flag = match(str1.c_str(), str2.c_str());
		if (flag)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}