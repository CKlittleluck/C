#include <iostream>
using namespace std;

int count(size_t value)
{
	int count;
	while (value)
	{

		value &= (value - 1);
		count++;
		//if(value % 2 == 1)
		//{
		//   count++;
		//}
		//value /= 2;
	}
	return count;
}

int main()
{
	size_t value;
	while (cin >> value)
	{
		int one_count = count(value);
		cout << one_count << endl;
	}
	return 0;
}