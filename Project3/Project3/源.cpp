#include <iostream>
#include <vector>
using namespace std;

int getDistance(int N, int ary[])
{
	int Max = ary[0];
	int Min = ary[0];
	for (int i = 1; i<N; i++)
	{
		if (Max<ary[i])
		{
			Max = ary[i];
		}
		if (Min>ary[i])
		{
			Min = ary[i];
		}
	}

	if (Max>0 && Min>0)
	{
		return 2 * Max;
	}
	else if (Max<0 && Min<0)
	{
		return -2 * Min;
	}
	else
	{
		return 2 * (Max - Min);
	}
}


int main()
{
	vector<int> v;
	int ret = getDistance(4, );
}