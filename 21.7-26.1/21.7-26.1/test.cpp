#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		int count[256] = { 0 };
		for (int i = 0; i < numbers.size(); i++)
		{
			count[numbers[i]]++;
		}
		for (int i = 0; i < sizeof(count); ++i)
		{
			if (count[i] > numbers.size() / 2)
			{
				return count[i];
			}
			else
			{
				return 0;
			}
		}
	}
};


int main()
{
	vector<int> numbers;
	class Solution a;
	int ret = a.MoreThanHalfNum_Solution(numbers);
}