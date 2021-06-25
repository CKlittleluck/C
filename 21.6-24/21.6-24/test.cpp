#include <iostream>
#include <cstdio>
using namespace std;

bool isLeapyear(int y)
{
	return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}

int Days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
// ��� y,m,d ��һ����˶�����
int nDays(int y, int m, int d)
{
	int n = d;
	for (int i = 0; i < m - 1; i++)
	{
		n += Days[i];
	}

	if (m > 2 && isLeapyear(y))
	{
		n++;
	}
	return n;
}

// ���� y,m,d ����ӻ�׼���ڣ������������ڹ��˶����� 
// ������������ MOD 7 ��ͬ����
int diff(int y, int m, int d)
{
	return (y - 1) + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400 + nDays(y, m, d);
}


// ���� y,m,d�������ܼ�
int week(int y, int m, int d)
{
	int w = diff(y, m, d) % 7;
	if (w == 0)
	{
		w = 7;
	}
	return w;
}

int m1(int w, int n, int e)
{
	return 1 + (n - 1) * 7 + (7 - w + e) % 7;
}

int m2(int w)
{
	int d = (w == 1 ? 7 : w - 1);
	return 32 - d;
}


int main()
{
	int y;
	while (cin >> y)
	{
		printf("%d -01-01\n", y);
		int w;
		w = week(y, 1, 1);
		printf("%d-01-%02d\n", y, m1(w, 3, 1));

		w = week(y, 2, 1);
		printf("%d-02-%02d\n", y, m1(w, 3, 1));

		w = week(y, 6, 1);
		printf("%d-05-%02d\n", y, m2(w));

		printf("%d-07-04\n", y);

		w = week(y, 9, 1);
		printf("%d-09-%02d\n", y, m1(w, 1, 1));

		w = week(y, 11, 1);
		printf("%d-11-%02d\n", y, m1(w, 4, 4));

		printf("%d-12-25\n\n", y);
	}
}