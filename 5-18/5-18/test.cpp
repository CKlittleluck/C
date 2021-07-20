#include <iostream>
using namespace std;

bool leapyear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getdays(int year, int month)
{
	int days[13] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 & leapyear(year))
	{
		month = 0;
	}
	return days[month];
}


int getday(int year, int month, int day)
{
	int days = 0;
	for (int i = 1; i < month; ++i)
	{
		days += getdays(year, i);
	}
	days += day;
	return days;
}

int main()
{
	int year, month, day;
	int days = 0;
	while (cin >> year >> month >> day)
	{
		days = getday(year, month, day);
		cout << days << endl;
	}

	return 0;
}