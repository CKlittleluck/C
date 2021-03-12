#pragma once

#include "BitSet.hpp"

template<class T, size_t N, class HF1, class HF2, class HF3, class HF4, class HF5>

class BloomFilter
{
public:
	BloomFilter()
		:_size(0)
	{}

	bool Insert(const T & data)
	{
		szie_t index1 = HF1()(data) % _bst.szie();
		szie_t index2 = HF2()(data) % _bst.szie();
		szie_t index3 = HF3()(data) % _bst.szie();
		szie_t index4 = HF4()(data) % _bst.szie();
		szie_t index5 = HF5()(data) % _bst.szie();

		_bst.set(index1);
		_bst.set(index2);
		_bst.set(index3);
		_bst.set(index4);
		_bst.set(index5);

		_size++;
		return true;
	}

	bool IsIn(const T& data)
	{
		size_t index = HF1()(data) % _bst.size();
		if (!_bst.test(index))
			return false;

		index = HF2()(data) % _bst.size();
		if (!_bst.test(index))
			return false;


		index = HF3()(data) % _bst.szie();
		if (!_bst.test(index))
			return false;

		index = HF4()(data) % _bst.szie();
		if (!_bst.test(index))
			return false;

		index = HF5()(data) % _bst.szie();
		if (!_bst.test(index))
			return false;

		return true;


	}


private:
	bite::bitset<N * 10> _bst;
	size_t _size;
};