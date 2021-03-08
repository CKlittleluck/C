#pragma noce
#include "HashBacket.hpp"



namespace bite
{
	template<class T>
	class unordered_set
	{
		typedef K ValueType;
		struct KOFV
		{
			const K& operator()(const ValueType& data)
			{
				return data;
			}
		};

		typedef HashBucket<ValueType, KOFV> HTB;

	public:
		typename typedef HTB::iterator iterator;

	public:
		unordered_map()
			:_ht()
		{}

		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		bool empty()const
		{
			return _ht.Empty();
		}

		size_t size()const
		{
			return _ht.size();
		}

		iterator find(const K& key)
		{
			return _ht.Find(key);
		}

		pair<iterator, bool> insert(const ValueType& data)
		{
			return _ht.InsertUnique(data);
		}

		size_t erase(const K& key)
		{
			return _ht.EraseUnique(make_pair(key);
		}

		void clear()
		{
			_ht.clear();
		}

		void swap(unordered_set<K>& m)
		{
			_ht.Swap(m._ht);
		}

		size_t bucket_count() const
		{
			return _ht.BucketCount();
		}

		size_t bucket_size(size_t n)const
		{
			return _ht.BucketSize(n);
		}

	private:
		HTB _ht;
	};
}

