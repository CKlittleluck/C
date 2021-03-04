#include "RBTree.hpp"

namespace bite
{
	template<class K, class V>
	class map
	{
		typedef pair<K, V> ValueType;

		class KOFV
		{
		public:
			const K& operator()(const ValueType& data) const
			{
				return data.first;
			}
		};

		typedef RBTree<ValueType, KOFV> RBTree;

		typedef RBTree::iterator iterator;
	public:
		map()
			:_t()
		{}

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		bool empty() const
		{
			return _t.empty();
		}

		size_t size() const
		{
			return _t.size();
		}

		V& operator[](const K& x)
		{
			return (*((this->insert(make_pair(x, V()))).first)).second;
		}

		pair<iterator, bool> insert(const ValueType& value)
		{
			return _t.Insert(value);
		}

		void swap(map <K, V> & m)
		{
			_t.swap(m._t);
		}

		void clear()
		{
			_t.clear();
		}

		iterator find(const K&key)const
		{
			return _t.find(key);
		}

	private:
		RBTree _t;

	};
}
