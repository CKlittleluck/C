#include <iostream>
#include <vector>
//#include <algorithm>
using namespace std;

#if 0
void bubblesolt(vector<int>& a, int n)
{
	bool flag = false;
	for (int i = 0; i < n - 1; ++i)
	{
		flag = false;
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				flag = true;
			}
		}
		if (!flag)
		{
			break;
		}
	}
}
#endif

void Cout(vector<int>& nums)
{
	for (auto x : nums)
	{
		cout << x << " ";
	}
	cout << endl;
}

#if 0
void selectionsort(vector<int>& nums)
{
	int min = 0;
	int size = nums.size();
	for (int i = 0; i < size; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (nums[j] < nums[min])
			{
				min = j;
			}
		}
		swap(nums[i], nums[min]);
	}
}

void insertionSort(vector<int> &nums)
{
	int size = nums.size();
	for (int i = 1; i < size; i++)
	{
		int j = 0;
		int x = 0;
		if (nums[i] < nums[i - 1])
		{
			j = i - 1;
			x = nums[i];

		}
		while(j >= 0 && x < nums[j])
		{
			nums[j + 1] = nums[j];
			j--;
		}
		nums[j + 1] = x;
	}
}

#endif


#if 0
void quickSort(vector<int>& nums, int begin, int end) {
	if (begin >= end) return;
	int low = begin, high = end, key = nums[begin];
	while (low < high) {
		while (low < high && nums[high] >= key) {
			high--;

		}
		if (low < high)  nums[low++] = nums[high];

		while (low < high && nums[low] <= key) {
			low++;

		}
		if (low < high)  nums[high--] = nums[low];
	}

	nums[low] = key;
	Cout(nums);

	quickSort(nums, begin, low - 1);
	quickSort(nums, low + 1, end);

}
#endif

#if 0 
void quickSort(vector<int>& a, int low, int high)
{
	if (low > high)
	{
		return;
	}

	int first = low;
	int last = high;

	int key = a[first];

	while (first < last)
	{
		while (first < last && a[last] > key)
		{
			last--;
		}
		if (first < last)
		{
			a[first++] = a[last];
		}

		while (first < last && a[first] <= key)
		{
			first++;
		}

		if (first < last)
		{
			a[last--] = a[first];
		}
	}

	a[first] = key;
	quickSort(a, low, first - 1);
	quickSort(a, first + 1, high);
}
#endif


void shellSortCore(vector<int>& nums, int gap, int i)
{
	int inserted = nums[i];
	int j;
	//  插入的时候按组进行插入
	for (j = i - gap; j >= 0 && inserted < nums[j]; j -= gap) {
		nums[j + gap] = nums[j];
	}
	nums[j + gap] = inserted;
}


void shellSort(vector<int>& nums)
{
	int len = nums.size();
	for (int gap = len / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < len; ++i)
		{
			shellSortCore(nums, gap, i);
		}
	}
}

int main()
{
	vector<int> v = { 8, 9, 1, 4, 2, 3, 6, 7, 5, 5 };
	shellSort(v);
	Cout(v);
}

