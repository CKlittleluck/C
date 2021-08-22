#include <iostream>
#include <vector>
#include <list>
#include <set>
using namespace std;

#if 0 
int main()
{
	int a[] = { 7,1, 2, 3, 4,4, 5, 5,6 };

	/*vector<int> v(a,a + sizeof(a)/sizeof(a[0]));
	cout << a << endl;
	cout << a + sizeof(a) / sizeof(a[0]) << endl;
	for (auto x : v)
	{
		cout << x << endl;
	}*/

	list<int> L(a, a + sizeof(a) / sizeof(a[0]));
	L.unique();
	L.sort();
	list<int>::iterator it = find(L.begin(), L.end(),6);
	L.erase(it);
	list<int> L1(L);
	L.merge(L1);
	for (auto x : L)
	{
		cout << x << endl;
	}
	return 0;
}
#endif

int main()
{
	int arry[] = { 1, 3, 5, 9, 2, 4, 6, 8, 0, 1, 3, 5, 9, 2, 4, 6, 8, 0 };
	set<int> s(arry, arry + sizeof(arry) / sizeof(arry[0]));


	/*for (auto x : s)
	{
	cout << x << endl;
	}*/


	//set<int> s1(s);
	//set<int> s2(s.begin(), s.end());
	set<int>::iterator it;
	pair<set<int> ::iterator, bool> ret = s.insert(7);

	it = s.find(7);
	cout << *it << endl;

	s.erase(7);
	cout << s.count(8) << endl;

}

