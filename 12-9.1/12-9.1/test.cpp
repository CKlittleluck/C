#include<iostream>
using namespace std;


//������������ĸ���
int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		while (n)
		{
			int a = n % 2;
			if (a == 1)
				count++;
		}
		cout << count << endl;
	}
	return 0;
}

//25083 ����ӷ�

class unusualAdd
{
public:
	int addAB(int A, int B)
	{
		int sum = 0, carry = 0;
		while (B != 0)
		{
			//��򣬶�Ӧλ�ĺ�
			sum = A^B;
			//��Ӧλ�͵Ľ�λ�����ǽ�λ����Ҫ���� ����һλ
			carry = (A & B) << 1;
			A = sum;
			B = carry;
		}
		return sum;
	}
};
