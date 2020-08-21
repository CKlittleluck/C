#define _CRT_SECURE_NO_WARNINGS  1
#include"test.h"
#include<string.h>
#include<malloc.h>


void PrintArray(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

// 插入排序
void InsertSort(int array[], int size)
{
	for (int i = 1; i < size; ++i)
	{
		int key = array[i];
		int end = i - 1;
		while (end >= 0 && key < array[end])
		{
			array[end + 1] = array[end];
			end--;
		}
		array[end + 1] = key;
	}
}


// 希尔排序
void ShellSort(int array[], int size)
{
	int gap = size;
	while (gap > 0)
	{
		gap = gap / 3 + 1;
		for (int i = gap; i < size; ++i)
		{
			int key = array[i];
			int end = i - gap;
			while (end >= 0 && key < array[end])
			{
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = key;
		}
		gap--;
	}
}

// 选择排序
void swap(int *left, int *right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}
void SelectSort1(int array[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int maxpoint = 0;
		for (int j = 1; j < size - i; ++j)
		{
			if (array[j] > array[maxpoint])
			{
				maxpoint = j;
			}
			if (maxpoint != size - 1 - i)
			{
				swap(&array[maxpoint], &array[size - 1 - i]);
			}

		}
	}
}

void SelectSort2(int array[], int size)
{
	int begin = 0;
	int end = size - 1;
	while (begin < end)
	{
		int minpos = begin;
		int maxpos = begin;
		int j = begin + 1;
		while (j <= end)
		{
			if (array[j] > array[maxpos])
				maxpos = j;
			if (array[j] < array[minpos])
				minpos = j;
			j++;
		}
		if (maxpos != end)
		{
			swap(&array[maxpos], &array[end]);
		}
		if (minpos == end)
		{
			minpos = maxpos;
		}
		if (minpos != begin)
		{
			swap(&array[minpos], &array[begin]);
		}
		begin++;
		end--;
	}
}

// 堆排序
void AdjustDwon(int array[], int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && array[child + 1] > array[child])
		{
			child += 1;
		}
		if (array[child] > array[parent])
		{
			swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}
	}
}
void HeapSort(int array[], int size)
{
	int end = size - 1;
	for (int root = (size - 2) / 2; root >= 0; root--)
	{
		AdjustDwon(array, size, root);
	}
	while (end)
	{
		swap(&array[0], &array[end]);
		AdjustDwon(array, end, 0);
		end--;
	}
}


// 冒泡排序
void BubbleSort(int array[], int size)
{
	int flag = 0;
	for (int i = 0; i < size - i-1; ++i)
	{
		flag = 0;
		for (int j = 0; j < size - 1; ++j)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				flag = 1;
			}
		}
		if (!flag)
		{
			return;
		}
	}

}

// 快速排序
// 快速排序hoare版本
int PartSort1(int array[], int left, int right)
{
	int begin = left;
	int end = right - 1;
	int key = array[right - 1];
	while (begin < end)
	{
		while (begin < end && array[begin] <= key)
			begin++;
		while (begin < end && array[end] >= key)
			end--;
		if (begin < end)
		{
			swap(&array[begin], &array[end]);
		}
	}
	if (end != right - 1)
	{
		swap(&array[begin], &array[right - 1]);
	}

	return begin;
}

// 快速排序挖坑法
int PartSort2(int array[], int left, int right)
{
	int begin = left;
	int end = right - 1;
	int key = array[right - 1];
	while (begin < end)
	{
		while (begin < end && array[begin] <= key)
			begin++;
		if (begin < end)
		{
			array[end] = array[begin];
			end--;
		}
		while (begin < end && array[end] >= key)
			end--;
		if (begin < end)
		{
			array[begin] = array[end];
			begin++;
		}
		
	}
	if (end != right - 1)
	{
		array[begin] = key;
	}

	return begin;
}


// 快速排序前后指针法
int PartSort3(int array[], int left, int right)
{
	int cur = left;
	int prev = cur - 1;
	int key = array[right - 1];
	while (cur < right)
	{
		if (array[cur] < key && ++prev != cur)
			swap(&array[cur], &array[prev]);
		cur++;
	}
	if (++prev != right - 1)
		swap(&array[right - 1], &array[prev]);
	return prev;
}


void QuickSort(int array[], int left, int right)
{
	if (right - left < 12)
	{
		InsertSort(array + left, right - left);
	}
	else
	{
		int div = PartSort3(array, left, right);
		QuickSort(array, left, div);
		QuickSort(array, div + 1, right);
	}
}


 //快速排序 非递归实现
void QuickSortNonR(int array[], int size)
{
	int left = 0;
	int right = size;
	Stack s;
	StackInit(&s);
	StackPush(&s, right);
	StackPush(&s, left);

	while (!StackEmpty(&s))
	{
		left = StackTop(&s);
		StackPop(&s);

		right = StackTop(&s);
		StackPop(&s);

		if (right - left > 1)
		{
			int div = PartSort3(array, left, right);
			StackPush(&s, right);
			StackPush(&s, div + 1);

			StackPush(&s, div);
			StackPush(&s, left);
		}
	}
	StackDestory(&s);
}


// 归并排序递归实现
void MergeData(int array[], int left, int mid, int right, int temp[])
{
	int index1 = left, index2 = mid, index = left;
	while (index1 < mid && index2 < right)
	{
		if (array[index1] <= array[index2])
		{
			temp[index++] = array[index1++];
		}
		else
			temp[index++] = array[index2++];
	}
	while (index1 < mid)
	{
		temp[index++] = array[index1++];
	}
	while (index2 < right)
	{
		temp[index++] = array[index2++];
	}
}


void _MergeSort(int array[], int left, int right, int temp[])
{
	if (right - left > 1)
	{
		int mid = left + ((right - left) >> 1);
		_MergeSort(array, left, mid, temp);
		_MergeSort(array, mid, right, temp);
		MergeData(array, left, mid, right, temp);
		memcpy(array + left, temp + left, (right - left)*sizeof(array[left]));
	}
}

void MergeSort(int array[], int size)
{
	int *temp = (int*) malloc (size * sizeof(array[0]));
	if (NULL == temp)
		return;
	_MergeSort(array, 0, size, temp);
	free(temp);
}

// 归并排序非递归实现
void MergeSortNonR(int array[], int size)
{
	int gap = 1;
	int* temp = (int*)malloc(size * sizeof(array[0]));
	if (NULL == temp)
		return;

	while (gap < size)
	{
		for(int i = 0; i < size; i += 2 * gap)
		{
			int left = i;
			int mid = i + gap;
			int right = mid + gap;
			if (mid > size)
				mid = size;
			if (right > size)
				right = size;
			MergeData(array, left, mid, right, temp);
		}
		memcpy(array, temp, size * sizeof(array[0]));
		gap *= 2;
	}
}

// 计数排序
void CountSort(int array[], int size)
{
	int minvalue = array[0];
	int maxvalue = array[0];
	for (int i = 0; i < size; i++)
	{
		if (array[minvalue] > array[i])
			array[minvalue] = array[i];
		if (array[maxvalue] < array[i])
			array[maxvalue] = array[i];
	}
	int range = maxvalue - minvalue + 1;
	int *temp = (int*)malloc(range*sizeof(int));
	memset(temp, 0, sizeof(int)*range);
	for (int i = 0; i < size; ++i)
		temp[array[i] - minvalue]++;
	int index = 0;
	for (int i = 0; i < range; ++i)
	{
		while (temp[i]--)
		{
			array[index++] = i + minvalue;
		}
	}
	free(temp);
}


void TestSort()
{
	int array[] = { 4, 1, 0, 7, 2, 8, 6, 3, 9, 5 ,6};
	PrintArray(array, sizeof(array) / sizeof(array[0]));
	//InsertSort(array, sizeof(array) / sizeof(array[0]));
	//ShellSort1(array, sizeof(array) / sizeof(array[0]));
	//SelectSort2(array, sizeof(array) / sizeof(array[0]));
	//HeapSort(array, sizeof(array) / sizeof(array[0]));
	//BubbleSort(array, sizeof(array) / sizeof(array[0]));
	//QuickSort(array, 0,sizeof(array) / sizeof(array[0]));
	//MergeSort(array, sizeof(array) / sizeof(array[0]));
	//MergeSortNonR(array, sizeof(array) / sizeof(array[0]));
	CountSort(array, sizeof(array) / sizeof(array[0]));
	PrintArray(array, sizeof(array) / sizeof(array[0]));
}

int main()
{
	TestSort();
	return 0;
}