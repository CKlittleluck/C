#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>
//int main()
//{
//	string s1;
//	string s2;
//	getline(cin, s1);
//	for (auto & ch:s1)
//	{
//		if (s2.find[ch] == -1)
//		{
//			s2.push_back(ch);
//		}
//	}
//	cout << s2 << endl;
//	return 0;
//}




//int main()
//{
//	string s1;
//	string s2;
//	getline(cin, s1);
//	int i = 0;
//	int max = 0;
//	int len = 0;
//
//	while (i < s1.size())
//	{
//		while (isdigit(s1[i]))
//		{
//			s2 += s1[i];
//			len++;
//			i++;
//		}
//		if (len > max)
//		{
//			max = len;
//		}
//		i++;
//	}
//	cout << s2 << endl;
//	return 0;
//}


int MoreThanHalfNum_Solution(vector<int> numbers);
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int count = 0;
		int size = numbers.size();
		int num = numbers.size() / 2;
		//auto it = numbers.begin();
		sort(numbers.begin(), numbers.end());
		for (int i = 0; i < size; i++)
		{
			if (numbers[num] == numbers[i])
				count++;
			if (count > num)
				return numbers[num];
		}
	}
};

int main()
{
	vector<int> v;
	MoreThanHalfNum_Solution(v);
	return 0;
}