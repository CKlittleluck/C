#include <iostream>
#include <string>
using namespace std;

#if 0
class This
{
	This()
	{
	}

	int& operator++()
	{
		*this += 1;
		return *this;
	}

	int operator++(int)
	{
		int temp = *this;
		++ *this;

		return temp;
	}
};
#endif

#include <queue>

#if 0
int main()
{
	int a[] = { 0, 4, 1, 2, 3, 6, 5, 8, 7 };
	int b = sizeof(a) / sizeof(int);
	cout << b << endl;
	priority_queue<int> pq(a, a + b);
	cout << pq.size() << endl;

	//cout << pq.top() << endl;

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	return 0;
}
#endif


#if 0
#include<map>
int main()
{
	map<string, int> m;
	m["ck"] = 1;
	m["yy"] = 2;
	m["dd"] = 3;
	pair<string, int> p("jj", 4);

	m.insert(p);

	cout << m.size() << endl;

	map<string, int>::iterator it = m.begin();
	for (; it != m.end(); ++it)
	{
		cout << it->first<<" ";
		cout << it->second << endl;
	}

	it->second = 100;
	int num2 = m["yy"];
	cout << num2 << endl;

	it = m.find("yy");
	if (it != m.end())
	{
		cout << it->second << endl;
	}
	return 0;
}


class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		for (int i = 0; i < array.size(); i++)
		{
			for (int j = 0; j < array[0].size(); j++)
			{
				if (target == array[i][j])
					return true;
			}
		}
		return false;
	}
};


class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		for (auto x : array)
		{
			for (auto j : x)
			{
				if (target == j)
					return true;
			}
		}
		return false;
	}
};

#endif

int main()
{
	//char a[][6] = { "aJsd", "s0", "1234", "sAuDX", "AzS13" };
	//printf("a = %d", a[2][4]);
	//printf("b = %d", a[3][3]);

	int a = 10;
	int b = a++;
	cout << b << endl;
}


class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int col = array[0].size();
		int row = array.size();

		int w = col - 1;
		int h = 0;
		while (w >= 0 && h < row)
		{
			if (target > array[h][w])
				h++;
			else if (target < array[h][w])
				w--;
			else
				return true;
		}
		return false;
	}
};

class Solution {
public:
	bool Search(vector<int> arr, int target)
	{
		int left = 0;
		int right = arr.size() - 1;

		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (arr[mid] == target)
				return true;
			else if (arr[mid] < target)
				return left = mid + 1;
			else
				return right = mid - 1;
		}
		return false;
	}
	bool Find(int target, vector<vector<int> > array) {
		for (auto i : array)
		{
			if (Search(i, target))
				return true;
		}
		return false;
	}
};
