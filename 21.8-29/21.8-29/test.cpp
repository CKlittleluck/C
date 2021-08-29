#include <iostream>
#include <vector>
using namespace std;


void Cout(vector<int>& nums)
{
	for (auto x : nums)
	{
		cout << x << " ";
	}
	cout << endl;
}

#if 0
void bubblesort(vector<int>& nums)
{
	bool falg = false;
	int size = nums.size();
	for (int i = 0; i < size; i++)
	{
		falg = false;
		for (int j = 0; j < size - i - 1; j++)
		{
			if (nums[j + 1] < nums[j])
			{
				swap(nums[j], nums[j + 1]);
				falg = true;
			}
		}
		if (!falg)
		{
			break;
		}
	}
}
#endif


#if 0
void selectionSort(vector<int>& nums)
{
	int size = nums.size();
	int min = 0;
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
		swap(nums[min], nums[i]);
	}
}
# endif


#if 0
void insertionSort(vector<int>& nums)
{
	int size = nums.size();
	for (int i = 1; i < size; i++)
	{
		if (nums[i] < nums[i - 1])
		{
			int j = i - 1;
			int x = nums[i];
			while (j >= 0 && x < nums[j])
			{
				nums[j + 1] = nums[j];
				j--;
			}
			nums[j + 1] = x;
		}
	}
}
#endif

#if 0
void quickSort(vector<int>& nums, int low, int hight)
{
	if (low >= hight)
	{
		return;
	}
	int left = low;
	int right = hight;

	int key = nums[left];
	while (left < right)
	{
		while (left < right && nums[right] > key)
		{
			right--;
		}
		if (left < right)
		{
			nums[left++] = nums[right];
		}

		while (left < right && nums[left] < key)
		{
			left++;
		}
		if (left < right)
		{
			nums[right--] = nums[left];
		}

		nums[left] = key;

		quickSort(nums, low, left - 1);
		quickSort(nums, left +1, hight);
	}
}
#endif


#if 0
void shellSortCore(vector<int>& nums, int gap, int i)
{
	int inser = nums[i];
	int j;

	for (j = i - gap; j >= 0 && inser < nums[j]; j -= gap)
	{
		nums[j + gap] = nums[j];
	}
	nums[j + gap] = inser;
}


void shellsort(vector<int>& nums)
{
	int len = nums.size();
	for (int gap = len / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < len; i++)
		{
			shellSortCore(nums, gap, i);
		}
	}
}


int main()
{
	vector<int> nums = { 1, 4, 6, 8, 4, 2, 5, 8, 0, 7, 3, 2, 9 };
	shellsort(nums);
	Cout(nums);
}
#endif

#include <algorithm>
int list_length(vector<int>& nums)
{
	int ret = nums[0];
	for (int i = 1; i < nums.size(); ++i)
	{
		nums[i] = max(nums[i - 1] + nums[i], nums[i]);
		ret = max(nums[i], ret);
	}
	return ret;
}