#include <iostream>
using namespace std;

int main()
{
	double num;
	double perimeter;
	while (cin >> num >> perimeter)
	{
		if (num >= 6.28 * perimeter)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	return 0;
}