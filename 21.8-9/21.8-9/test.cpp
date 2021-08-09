#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

void DivNum(int N, vector<int>& div_num)
{
	for (int i = 2; i <= sqrt(N); i++)
	{
		if (N % i == 0)
		{
			div_num.push_back(i);
			if (N / i != i)
				div_num.push_back(N / i);
		}
	}
}

int jump(int N, int M)
{
	vector<int> Jump(M + 1, 0);
	Jump[N] = 1;
	for (int i = N; i < M; i++)
	{
		vector<int> div_num;
		if (Jump[i] == 0)
			continue;
		DivNum(i, div_num);
		for (int j = 0; j < div_num.size(); j++)
		{
			if ((div_num[j] + i) <= M && Jump[div_num[j] + i] != 0)
			{
				Jump[div_num[j] + i] = min(Jump[div_num[j] + i], Jump[i] + 1);
			}
			else if ((div_num[j] + i) <= M)
			{
				Jump[div_num[j] + i] = Jump[i] + 1;
			}
		}
	}
	if (Jump[M] == 0)
		return -1;
	else
		return Jump[M] - 1;
}

int main()
{
	int N, M;
	cin >> N >> M;
	int ret = jump(N, M);
	cout << ret << endl;
	return 0;
}