#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int sum = v[0];
	int max = v[0];

	for (int i = 1; i < n; ++i)
	{
		sum = std::max(sum + v[i], v[i]);
		if (sum > max)
			max = sum;
	}
	cout << max << endl;
	return 0;
}




int GetMax(int a, int b)//得到两个数的最大值 
{
	return (a) > (b) ? (a) : (b);
}
int main()
{
	int size;
	cin >> size;
	vector<int> nums(size);
	for (size_t i = 0; i < size; ++i)
		cin >> nums[i];

	int Sum = nums[0]; //临时最大值 
	int MAX = nums[0];

	for (int i = 1; i < size; i++)
	{
		Sum = GetMax(Sum + nums[i], nums[i]);//状态方程 
		if (Sum >= MAX)
			MAX = Sum;
	}
	cout << MAX << endl;
	return 0;
}

