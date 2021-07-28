class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		if (numbers.empty())
		{
			return 0;
		}

		sort(numbers.begin(), numbers.end());
		int Mid = numbers[numbers.size() / 2];

		int count = 0;
		for (int i = 0; i < numbers.size(); ++i)
		{
			if (numbers[i] == Mid)
			{
				count++;
			}
		}
		if (count > numbers.size() / 2)
		{
			return Mid;
		}
		else
			return 0;
	}
};