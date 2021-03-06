#pragma once
#include <vector>
template<class T>
struct HashNode
{
	HashNode(const T&x = T())
	:next(nullptr)
	, data(x)
	{}

	HashNode<T>* next;
	T data;
};

template<class T>
class HashBucket
{
	typedef HashNode<T> Node;
public:
	HashBucket(size_t capacity = 10)
		:table(10)
		, _size(0)
	{}

	bool InsertUnique(const T& data)
	{
		size_t bncketNo = HashFunc(data);

		Node* cur = table[bucketNo];
		while (cur)
		{
			if (data == cur->data)
			{
				return false;
			}
			cur = cur->next;
		}

		cur = new Node(data);
		cur->next = table[bucktNo];
		table[buckNo] = cur;
		_size++;
	}

	bool InsertEqual(const T& data)
	{
		size_t bncketNo = HashFunc(data);

		Node* cur = new Node(data);
		cur->next = table[bucktNo];
		table[buckNo] = cur;
		_size++;
		return true;
	}

	Node* Find(const T& data)
	{
		size_t bucketNo = HashFunc(data);
		Node* cur = table[bucketNo];
		while (cur)
		{
			if (data == cur->data)
				return cur;
			cur = cur->next;
		}
		return nullptr;
	}


	bool EraseUnique(const T& data)
	{
		size_t bucketNo = HashFunc(data);
		Node* cur = table[bucketNo];
		Node* prev = nullptr;
		while (cur)
		{
			if (cur->data == data)
			{

				if (prev == nullptr)
				{
					table[bucketNo] = cur->next;
				}
				else
				{
					prev->next = cur->next;
				}
				delete cur;
				_size--;
				return true;
			}
			else
			{
				prev = cur;
				cur = cur->next;
			}
		}

		return false;
	}

	bool EraseEquel(const T& data)
	{
		return 0;
	}


	size_t size() const
	{
		return _size;
	}

	bool Empty()const
	{
		return _size == 0;
	}

	void PrintHashBucket()
	{
		for (size_t i = 0; i < table.capacity(); ++i)
		{
			cout << "[" << i << "]";
			Node* cur = table[i];
			while (cur)
			{
				cout << cur->data << "--->";
				cur = cur->next;
			}

			cout << "null" << endl;
		}
	}

private:
	size_t HashFunc(const T& data)
	{
		return data % table.capacity();
	}



private:
	std::vector<Node*> table;
	size_t _size;
};

#include<iostream>
using namespace std;

void TestHashBucket()
{
	HashBucket<int> ht;

	int array[] = { 1, 4, 5, 6, 7, 9 };
	for (auto e : array)
	{
		ht.InsertUnique(e);
	}
	cout << ht.size() << endl;
}