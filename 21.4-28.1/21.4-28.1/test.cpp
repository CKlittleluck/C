class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here
		stack <char> sc;
		for (auto ch : A)
		{
			switch (ch)
			{
			case '(':
			{
						sc.push(ch);
						break;
			}
			case ')':
			{
						if (sc.empty())
							return false;
						sc.pop();
						break;
			}
			default:
				return false;
			}
		}
		return sc.empty();
	}
};