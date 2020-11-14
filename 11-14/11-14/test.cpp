#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stdio.h>


class Solution
{
public:
	int FindKthLargest(vector<int>& nums, int k)
	{
		priority_queue<int> p(nums.begin(), nums.end());
	for (int i = 0; i < k - 1; ++i)
	{
		p.pop();
	}
	return p.top();
};





int main()
{
	return 0;
}