#include "RBTree.hpp"

namespace bite
{
	template<class K>
	class set
	{
		typedef pair K ValueType;

		class KOFV
		{
		public:
			const K& operator()(const ValueType& data) const
			{
				return data;
			}
		};



		typedef RBTree<ValueType, KOFV> RBTree;

		typename typedef RBTree::iterator iterator;
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


		pair<iterator, bool> insert(const ValueType& value)
		{
			return _t.Insert(value);
		}

		void swap(set<K>& s)
		{
			_t.swap(s._t);
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
