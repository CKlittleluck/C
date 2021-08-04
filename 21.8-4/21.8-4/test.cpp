class UnusualAdd {
public:
	int addAB(int A, int B) {
		if (A == 0)
			return B;
		if (B == 0)
			return A;
		int a = A ^ B;
		int b = (A & B) << 1;
		return addAB(a, b);
	}
};


#include <iostream>
using namespace std;

int pathnum(int n, int m)
{
	if (n == 0 || m == 0)
		return 1;
	return pathnum(n - 1, m) + pathnum(n, m - 1);
}

int main()
{
	int n, m;
	while (cin >> n >> m)
		cout << pathnum(n, m) << endl;
	return 0;
}