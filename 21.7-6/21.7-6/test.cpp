#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

inline int leap_year(int year)
{
	return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

inline int profit_of_year(int year)
{
	return 2 * 31
		+ 1 * 28
		+ 1 * 31
		+ 2 * 30
		+ 1 * 31
		+ 2 * 30
		+ 1 * 31
		+ 2 * 31
		+ 2 * 30
		+ 2 * 31
		+ 1 * 30
		+ 2 * 31
		+ leap_year(year);
}

inline bool prime(int n)
{
	return n == 2 || n == 3 || n == 5 || n == 7 || n == 11;
}

int profit_of_this_year(int year, int month, int day)
{
	if (!prime(month))
	{
		day *= 2;
	}

	while (--month)
	{
		switch (month)
		{
		case 1:
		case 8:
		case 10:
		case 12:
			day += 62;
			break;
		case 3:
		case 5:
		case 7:
			day += 31;
			break;

		case 4:
		case 6:
		case 9:
			day += 60;
			break;

		case 11:
			day += 30;
			break;

		case 2:
			day += 28 + leap_year(year);
			break;

		default:;
		}
	}
	return day;

int main()
{
	int year1, month1, day1, year2, month2, day2;
	int count_profit = 0;

	while (cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2)
	{
		count_profit = 0;
		count_profit += profit_of_year(year1) - profit_of_this_year(year1, month1, day1 - 1);
		count_profit += profit_of_this_year(year2, month2, day2);

		if (year1 == year2)
		{
			count_profit -= profit_of_year(year1);
		}

		for (int i = year1 + 1; i < year2; i++)
		{
			count_profit += profit_of_year(i);
		}
		cout << count_profit << endl;
	}
	return 0;
}