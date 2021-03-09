#pragma once
#include <vector>


namespace bite
{
	template<size_t N>
	class bitset
	{
	public:
		bitset()
			: _bst(N / 8 + 1)
		{}

		//将data 比特位置为1
		void set(unsigned long data)
		{
			assert(data < N);
			size_t whichByte = data / 8;
			size_t whichBite = data % 8;

			_bst[whichByte] |= (1 << whichBite);
		}

		//将data 比特位置为0
		void reset(unsigned long data)
		{
			assert(data < N);
			size_t whichByte = data / 8;
			size_t whichBite = data % 8;

			_bst[whichByte] &= ~(1 << whichBite);
		}


		//检测data在不在集合中
		bool test(unsigned long data)
		{
			assert(data < N);
			size_t whichByte = data / 8;
			size_t whichBite = data % 8;

			return 0 != _bst[whichByte] & (1 << whichBite);
		}

		//返回为1的bite位总数
		size_t count()const
		{
			int countTable[256] = { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3,
				2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 1, 2, 2, 3, 2, 3, 3, 4,
				2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5,
				4, 5, 5, 6, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
				2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4,
				3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6,
				4, 5, 5, 6, 5, 6, 6, 7, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4,
				3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
				2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5,
				4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 2, 3, 3, 4, 3, 4, 4, 5,
				3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6,
				5, 6, 6, 7, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
				4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8 };

			size_t count = 0;
			for (size_t i = 0; i < _bst.size(); ++i)
				count += countTable[_bst[i]];

			return count;
		}

		size_t size() const
		{
			return N;
		}

	private:
		std::vector<unsigned char> _bst;
	};

}