#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int findMinimum(int n, vector<int> left, vector<int> right) {
	int left_sum = 0, left_min = INT_MAX;
	int right_sum = 0, right_min = INT_MAX;
	int sum = 0;
	for (int i = 0; i < n; i++){
		if (left[i] * right[i] == 0)
			sum += left[i] + right[i];
		else{
			left_sum += left[i];
			right_sum += right[i];
			left_min = min(left_min, left[i]);
			right_min = min(right_min, right[i]);
		}
	}
	return  left_min;
}

int main()
{
	int n; 
	vector <int> v1, v2;
	cin >> n;
	v1 = { 0, 7, 1, 6 };
	v2 = { 1, 5, 0, 6 };
	int ret = findMinimum(n, v1, v2);
	cout << ret << endl;
}