#include <iostream>
using namespace std;
int gcb(int A, int B)
{
	int r;
	while (r = A % B)
	{
		A = B;
		B = r;
	}
	return B;
}

int main()
{
	int A, B;
	while (cin >> A >> B)
	{
		cout << A*B / gcb(A, B) << endl;
	}
	return 0;
}