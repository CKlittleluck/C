#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void _printf(vector<int> &v)
{
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;
}


int main()
{
	/*vector<int> v(4, 100);
	cout << v.size() << endl;
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << endl;
		++it;
	}*/

	int arry[8] = { 3, 6, 1, 2, 5, 9, 4, 7 };
	vector<int> v1(arry, arry + sizeof(arry) / sizeof(arry[0]));

	v1.push_back(8); 

	vector<int>::iterator pos = find(v1.begin(), v1.end(), 6);
	v1.insert(pos,0);

	//v1.erase(pos);

	_printf(v1);

	vector<int> v2;
	v2.swap(v1);


	_printf(v2);

	for (auto x : v2)
	{
		cout << x << endl;
	}

	return 0;
}