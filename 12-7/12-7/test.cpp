#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int N, f, l = 0, r = 0, f0 = 0, f1 = 1, f = 0;
	cin >> N;
	while (1)
	{
		f = f0 + f1;
		f0 = f1;
		f1 = f;
		if (f < N)
			l = N - f;
		else
		{
			r = f - N;
			break;
		}
	}
	cout << min(l, r) << endl;
	return 0;
}


class Parenthesis {
public:
	bool chkParenthesis(string A, int n)
	{
		stack<char> sc;
		for (auto ele : A)
		{
			switch (ele)
			{
			case '(':
				sc.push(ele);
				break;
			case ')':
			{
						if (sc.empty() || sc.top() != '(')
							return false;
						else
							sc.pop();
			}
				break;
			default:
				return false;
			}
		}
		return true;
	}
};