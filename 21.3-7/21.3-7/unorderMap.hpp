#pragma noce
#include "HashBacket.hpp"



namespace bite
{
	template<class T, class V>
	class unordered_map
	{
		typedef pair<K, V> ValueType;
		struct KOFV
		{
			const K& operator()(const ValueType& data)
			{
				return data.first;
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

		V& operator[](const K& key)
		{
			return (*(_ht.InsertUnique(make_pair(key, V()))).first).second;

		}

		iterator find(const K& key)
		{
			return _ht.Find(make_pair(key, V()));
		}

		pair<iterator, bool> insert(const ValueType& data)
		{
			return _ht.InsertUnique(data);
		}

		size_t erase(const K& key)
		{
			return _ht.EraseUnique(make_pair(key, V()));
		}

		void clear()
		{
			_ht.clear();
		}

		void swap(unordered_map<K, V>& m)
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

