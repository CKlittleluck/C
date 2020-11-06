#include <iostream>
using namespace std;
#include <list>
#include <vector>
void TestList1()
{
	list<int> L1;
	list<int> L2(10, 5);
	for (auto e : L2)
		cout << e << " ";
	cout << endl;

	vector<int> v{ 1, 2, 3, 4, 5 };
	list<int> L3(v.begin(), v.end());
	list<int>::iterator it = L3.begin();
	while (it != L3.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;


	list<int> L4(L3);
	//list<int>::reverse_iterator rit = L4.rbegin();
	auto rit = L4.rbegin();
	while (rit != L4.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	list<int> L5{ 1, 2, 3, 4, 5 };

}

void TestList2()
{
	list<int> L;
	L.push_back(1);
	L.push_back(2);
	L.push_back(3);
	L.push_back(4);
	cout << L.front() << endl;
	cout << L.back() << endl;

	L.push_front(0);
	L.pop_front();
	L.pop_back();


	L.insert(find(L.begin(), L.end(), 3), 5);
	L.erase(find(L.begin(), L.end(), 5));
	L.erase(L.begin(), L.end());
}

bool gteater(int left, int right)
{
	return left > right;
}

bool less(int left, int right)
{
	return left < right;
}

bool Iseven(int data)
{
	return 0 == data % 2;
}


void TestList3()
{
	list<int> L{ 2, 2, 3, 4, 5, 6, 7, 8, 8, 9 };
	L.unique();

	L.sort();
	L.unique();

	L.sort(gteater);
	L.sort(less);
	L.reverse();
	L.remove(3);
	L.remove_if(Iseven);
}


int main()
{
	TestList3();
	return 0;
}
