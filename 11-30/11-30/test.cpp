#include<iostream>
using namespace std;
#include<algorithm>
#include<string>

//A,B,C是三个人手里的糖果数量，我们不知道A,B,C是多少？
//但是我们知道A - B, B - C, A + B, B + C的结果
int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int A = (a + c) / 2;
	int C = (d - b) / 2;
	int b1 = (c - a) / 2;
	int b2 = (b + d) / 2;
	if (b1 != b2)
	{
		cout << "NO";
	}
	else
		cout << A << " " << b1 << " " << C;
	return 0;
}



int main()
{
	string s, table = "0123456789ABCDEF";
	int m, n;
	cin >> m >> n;
	bool flag = false;
	if (m < 0)
	{
		m = 0 - m;
		flag = true;
	}
	while (m)
	{
		s += table[m%n];
		m /= n;
	}

	if (flag)
		s += '-';
	reverse(s.begin(), s.end());
	cout << s << endl;
	return 0;

}