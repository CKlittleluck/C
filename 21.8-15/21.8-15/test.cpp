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
	// �����Լ����շת���
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
		// ����Ǹ�������Ҫ��()������
		if (r.negetive)
		{
			_cout << "(-";
		}

		// ��������������� + ����
		// ����: ���ܴ���Ҳ���ܲ�����
		if (r.integer)
		{
			_cout << abs(r.integer);
			// ����������ִ��ڣ������ͷ���֮����һ���ո�
			if (r.numerator)
			{
				_cout << " ";
			}
		}

		// ����: ���ܴ���Ҳ���ܲ�����
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
	int64 numerator; // ����
	int64 denominator; // ��ĸ
	int64 integer; // ��������
	bool negetive; // ����
	bool isZero; // ��ĸ�Ƿ�Ϊ0
	int64 totalnumerator; // ��������ķ��ӣ�ԭ���� + ��������
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