#include<iostream>
using namespace std;

#include<assert.h>

//函数模板
template<typename T>
void swap(T & left, T & right)
{
	T temp = left;
	left = right;
	right = temp;
}

template<typename T>
T Add(T left, T right)
{
	cout << typeid(T).name() << endl;
	return left + right;
}

//各种类型的数组
template<class T>
void PrintArray(T array[],size_t size)
{
	for (size_t i = 0; i < size; ++i)
		cout << array[i] << " ";
	cout << endl;
}


//模板类型的动态顺序表
//typedef int DataType;
template<class T>
class SeqList
{
public:
	SeqList(size_t capacity = 10)
		: _array(new T[capacity])
		, _capacity(capacity)
		, _size(0)
	{}

	void PushBack(const T& data);

	void PopBack()
	{
		if (!Empty())
		{
			--_size;
		}
	}
	
	bool Empty()const
	{
		return _size == 0;
	}
	
	size_t Size()const
	{
		return _size;
	}

	size_t Capacity()const
	{
		return _capacity;
	}


	~SeqList()
	{
		if (_array)
		{
			delete[] _array;
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}

	T& operator[](size_t index)
	{
		assert(index < _size);
		return _array[index];
	}

	const T& operator[](size_t index)const
	{
		assert(index < _size);
		return _array[index];
	}



private:
	T* _array;
	size_t _capacity;
	size_t _size;
};

template<class T>
void SeqList<T>::PushBack(const T& data)
{
	if (_size == _capacity)
	{
		//扩容
	}

	//Push
	_array[_size++] = data;

}

class Date
{
public:
	Date(int year = 2020, int month = 2, int day = 2)
		: _year(year)
		, _month(month)
		, _day(day)

	{}


	
private:
	int _year;
	int _month;
	int _day;
};



int main()
{
	//对函数模板进行实例化

	//隐式实例化
	Add(10,20);
	Add(1.2, 12.3);
	Add('1', '2');
	//显示实例化
	Add<int>(1.2, 2);

	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	PrintArray(array, sizeof(array) / sizeof(array[0]));
	
	SeqList<int> s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);

	cout << s1.Size() << endl;
	cout << s1.Capacity() << endl;

	const SeqList<int> s0;
	s0[1];

	SeqList<double> s2;
	SeqList<Date> s3;

	return 0;
}



