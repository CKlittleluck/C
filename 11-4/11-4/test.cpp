#include<iostream>
using namespace std;
#include<vector>

//class solution{
//public:
//	int strtoint(string str)
//	{
//		if (str.empty())
//			return 0;
//
//		int symbol = 1;
//		if (str[0] == '-')
//		{
//			symbol = -1;
//			str[0] = '0';
//		}
//		else if (str[0] == '+')
//		{
//			symbol = 1;
//			str[0] = '0';
//		}
//
//		int sum = 0;
//		for (int i = 0; i < str.size(); ++i)
//		{
//			if (str[i] < '0' || str[i] > '9')
//			{
//				sum = 0;
//				break;
//			}
//
//			sum = sum * 10 + str[i] - '0';
//		}
//		return symbol * sum;
//	}
//
//};



class Board {
public:
	bool checkWon(vector<vector<int> > board) {
		int size = board.size();
		int count;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (board[i][j] == 1)
					count++;
			}
			if (count == size)
			{
				return true;
			}
		}

		count = 0;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (board[j][i] == 1)
					count++;
			}
			if (count == size)
			{
				return true;
			}
		}

		count = 0;
		for (int i = 0; i < size; i++)
		{
			if (board[i][i] == 1)
				count++;
			if (count == size)
			{
				return true;
			}
		}

			count = 0;
			for (int i = 0; i < size; i++)
			{
				if (board[i][size - 1 - i] == 1)
					count++;
				if (count == size)
				{
					return true;
				}
			}
			return false;
		}
	};