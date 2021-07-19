#include <iostream>
#include <string>
#include <stack>

using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		stack<int> st;
		string str;
		for (int i = 0; i < n; ++i)
		{
			cin >> str;
			if (!(str == "+" || str == "-" || str == "*" || str == "/"))
			{
				st.push(atoi(str.c_str()));
			}
			else
			{
				int right = st.top();
				st.pop();
				int left = st.top();
				st.pop();

				switch (str[0])
				{
				  case '+':
					st.push(left + right);
					break;
				  case '-':
					st.push(left - right);
					break;
				  case '*':
					st.push(left * right);
					break;
				  case '/':
					st.push(left / right);
					break;
				}
			}
		}
		cout << st.top() << endl;
	}
	return 0;
}