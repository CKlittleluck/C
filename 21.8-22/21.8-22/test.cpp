#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
using namespace std;


#if 0
int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	sort(v.begin(), v.end());
	auto it = unique(v.begin(), v.end());
	v.erase(it, v.end());

	for (auto e : v)
		cout << e << " ";
	cout << endl;
}
#endif



int main()
{
	vector<int> v = { 4, 1, 2, 3 };
	sort(v.begin(), v.end());

	do
	{
		cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << endl;
	} while (next_permutation(v.begin(), v.end()));
	cout << endl;

	sort(v.begin(), v.end(), greater<int>());
	do
	{
		cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << endl;
	} while (prev_permutation(v.begin(), v.end()));
}