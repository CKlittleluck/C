#include<iostream>
using namespace std;


//二进制数中意的个数
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

//25083 另类加法

class unusualAdd
{
public:
	int addAB(int A, int B)
	{
		int sum = 0, carry = 0;
		while (B != 0)
		{
			//异或，对应位的和
			sum = A^B;
			//对应位和的进位，即是进位，就要整体 左移一位
			carry = (A & B) << 1;
			A = sum;
			B = carry;
		}
		return sum;
	}
};
