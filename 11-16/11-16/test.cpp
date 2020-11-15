#include<iostream>
using namespace std;
#include<string>
#include<algorithm>

void test1()
{
	string s("12345");
	int value = atoi(s.c_str());

	string s1("kangkangjiayou");
	char* p = (char*)s1.c_str();
	*p = 'H';
	cout << sizeof(string) << endl;

	string s1("qingqingjiayou");
	if (s < s1)
		cout << "s < s1" << endl;
	else 
		cout << "s >= s1" << endl;
}



void test2()
{
	string s("kangkang");
	reverse(s.begin(), s.end());
	sort(s.begin(), s.end());
	cout << s << endl;
}

void test()
{
	string s("kangkangjiayou");

	//1
	for (size_t i = 0; i < s.size(); ++i)
		cout << s[i] << " ";
	cout << endl;

	//2
	for (auto e : s)
		cout << e << " ";
	cout << endl;

	//3 迭代器
	string::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//4 反向迭代器
	//string::reverse_iterator rit = s.rbegin();
	auto rit = s.rbegin();
	while (rit != s.rend)
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}


int main()
{
	test1();
	return 0;
}