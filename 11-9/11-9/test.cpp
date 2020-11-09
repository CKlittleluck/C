#include <iostream>
using namespace std;
#include <list>

int main()
{
	list<int> L{ 1, 2, 3, 4, 5 };
	auto it = L.begin();
//pop_back()
	L.pop_back();
	cout << *it << endl;

//erase
	while (it != L.end())
	{
		it = L.erase(it);
		//++it;
	}
	return 0;
}

