#include<iostream>
using namespace std;

#include <vector>
#include <string>

void TestVector()
{
	vector<int> v1;
	vector<int> v2(10.5);
	for (size_t i = 0; i < v2.size(); ++i)
	{
		cout << v2[i] << " ";
	}
	cout << endl;

	int array[] = { 1, 2, 4, 5, 6, 7, 8 };
	vector<int> v3(array, array + sizeof(array) / sizeof(array[0]));

	//正向遍历
	vector<int>::iterator it = v3.begin();
	while (it != v3.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	string s("kangkang");
	vector<char> v4(s.begin(), s.end());

	vector<int> v5(v3);

	//反向遍历
	//vector<int>::reverse_iterator rit = v5.rbegin();

	auto rit = v5.rbegin();
	while (rit != v5.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	vector<int> v6{ 1, 2, 4, 5, 6, 7, 8 };
	for (auto& e : v6)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	return 0;
}