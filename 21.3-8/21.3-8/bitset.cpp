#include<iostream>
using namespace std;
#include<bitset>


int main()
{
	int array[] = { 1, 3, 7, 4, 12, 16, 19, 13, 22, 18 };
	bitset<23> bst;

	for (auto e : array)
	{
		bst.set(e);
	}

	cout << bst.count() << endl;
	cout << bst.size() << endl;

	if (bst.test(12))
	{
		cout << "ÔÚ" << endl;
	}
	else
	{
		cout << "²»ÔÚ" << endl;
	}

	bst.reset(12);


	return 0;
}