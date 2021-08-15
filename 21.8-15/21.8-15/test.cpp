#include <iostream>
using namespace std;
typedef long long int64;
class Rational
{
public:
	Rational(int64 n, int64 d)
	{
		negetive = false;
		isZero = false;

		if (0 == d)
		{
			isZero = true;
			return;
		}

		if (n < 0)
		{
			negetive = !negetive;
		}

		if (d < 0)
		{
			negetive = !negetive;
		}

		integer = n / d;
		numerator = n - integer*d;
		denominator = abs(d);


		if (numerator < -1 || numerator > 1)
		{
			int gcd = CalcGCD(abs(numerator), denominator);
			if (gcd)
			{
				numerator /= gcd;
				denominator /= gcd;
			}
		}

		totalnumerator = integer*denominator + numerator;
	}

	Rational operator+(const Rational& r)const
	{
		int64 n = totalnumerator*r.denominator + r.totalnumerator*denominator;
		int64 d = denominator * r.denominator;
		return Rational(n, d);
	}

	Rational operator-(const Rational& r)const
	{
		int64 n = totalnumerator*r.denominator - r.totalnumerator*denominator;
		int64 d = denominator * r.denominator;
		return Rational(n, d);
	}

	Rational operator*(const Rational& r)const
	{
		int64 n = totalnumerator*r.totalnumerator;
		int64 d = denominator * r.denominator;
		return Rational(n, d);
	}

	Rational operator/(const Rational& r)const
	{
		int64 n = totalnumerator*r.denominator;
		int64 d = denominator * r.totalnumerator;
		return Rational(n, d);
	}


private:
	// 求最大公约数：辗转相除
	int64 CalcGCD(int64 a, int64 b)
	{
		if (0 == b)
		{
			return a;
		}
		return CalcGCD(b, a%b);
	}


	friend ostream& operator<<(ostream& _cout, const Rational& r)
	{
		if (r.isZero)
		{
			_cout << "Inf";
			return _cout;
		}

		if (0 == r.integer && 0 == r.numerator)
		{
			_cout << "0";
			return _cout;
		}
		// 如果是负数，需要用()括起来
		if (r.negetive)
		{
			_cout << "(-";
		}

		// 输出有理数：整数 + 分数
		// 整数: 可能存在也可能不存在
		if (r.integer)
		{
			_cout << abs(r.integer);
			// 如果分数部分存在，整数和分数之间有一个空格
			if (r.numerator)
			{
				_cout << " ";
			}
		}

		// 分数: 可能存在也可能不存在
		if (r.numerator)
		{
			_cout << abs(r.numerator) << "/" << r.denominator;
		}

		if (r.negetive)
		{
			_cout << ")";
		}
		return _cout;
	}

private:
	int64 numerator; // 分子
	int64 denominator; // 分母
	int64 integer; // 整数部分
	bool negetive; // 负数
	bool isZero; // 分母是否为0
	int64 totalnumerator; // 参与运算的分子：原分子 + 整数部分
};

int main()
{
	int64 n1, d1, n2, d2;
	while (scanf("%lld/%lld %lld/%lld", &n1, &d1, &n2, &d2) != EOF)
	{
		Rational r1(n1, d1);
		Rational r2(n2, d2);
		cout << r1 << " + " << r2 << " = " << r1 + r2 << endl;
		cout << r1 << " - " << r2 << " = " << r1 - r2 << endl;
		cout << r1 << " * " << r2 << " = " << r1 * r2 << endl;
		cout << r1 << " / " << r2 << " = " << r1 / r2 << endl;
	}
	return 0;
}