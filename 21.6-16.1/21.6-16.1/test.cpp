#include <iostream>
using namespace std;

#define ADD(x,y) ((x) + (y))
#define CMP(x,y) ((x) > (y))

int main()
{
	double a, b, c;
	while (cin >> a >> b >> c)
	{
		if (CMP(ADD(a, b), c) && CMP(ADD(a, c), b) && CMP(ADD(b, c), a))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}