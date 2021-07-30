#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<double> v;
	for (int i = 0; i < 4; ++i)
	{
		cin >> v[i];
	}
	double A = (v[0] + v[2]) / 2;
	double B = (v[1] + v[3]) / 2;
	double C = B - v[1];
	cout << A << " " << " " << B << " " << C;
	return 0;
}