#include <iostream>
using namespace std;

class UnusualAdd {
public: int addAB(int A, int B) 
{
			int sum = 0, carry = 0; 
			while (B != 0)
			{ 
				carry = (A&B)<<1;
				A=sum; 
				B=carry; 
			}
			return sum; 
}
}


int gcd(int a, int b) 
{
	int r; 
	while(r = a%b)
	{ 
		a = b; b = r; 
	}
	return b; 
}
int main() 
{
	int a,b; 
	while(cin >> a >> b)
	{ 
		cout << a*b/gcd(a,b) <<endl; 
	}
	return 0;
}



int main()
{
	return 0;
}
