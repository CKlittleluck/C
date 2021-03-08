#pragma once

template<class T,class DToInt>
struct HashBucketIterator
{
	typedef HashNode<T> Node;
	typedef HashBucketIterator<T, DToInt> Self;

	HashBucketIterator(Node* pNode = nullptr, HashBucket<T, DToInt>* _ht = nullptr)

		:_pNode(pNode)
		, _ht(ht)
	{}

	T& operator*()
	{
		return _pNode->data;
	}

	T* operator->()
	{
		return &(operator*());
	}

	Self& operator++()
	{
		Next();
		return *this;
	}

	Self& operator++(int)
	{
		Self temp(*this)
		Next();
		return temp;
	}

	bool operator != (const Self& s)
	{
		return !(*this == s);
	}

	bool operator == (const Self& s)
	{
		return _pNode == s._pNode && _ht == s._ht;
	}

	void Next()
	{
		if (_pNode->next)
		{
			_pNode = _pNode->next;
		}
		else
		{
			size_t bucketNo = ht->HashFunc(_pNode->data) + 1;
			for (; bucketNo < _ht->BucketCount(); ++bucketNo)
			{
				if (_ht->table[bucketNo])
				{
					_pNode = _ht->table[bucketNo];
					return;
				}
			}
			_pNode = nullptr;
		}
	}

	size_t BucketCount()const
	{
		return table.capacity();
	}

	size_t BucketSize(size_t bucketNo)const
	{
		if (bucketNo >= BucketCount())
			return 0;
		Node* cur = table[bucketNo];
		size_t count = 0;

		while (cur)
		{
			count++;
			cu = cur->next;
		}
		return count;
	}

	size_t Bucket(const T& data)
	{
		return HashFunc(data, BucketCount());
	}


		Node* _pNode;
		HashBucket<T, DToInt>* _ht;
};