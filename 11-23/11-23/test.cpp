#include<iostream>
using namespace std;
#include<string>
#include <algorithm>



//��ת�ַ���
//kangkang yao jia you o
//o you jia yao kangkang

int main()
{
	string s;
	getline(cin, s); 
	reverse(s.begin(), s.end());
	auto start = s.begin();
	while (start != s.end())
	{
		auto end = start;
		while (end != s.end() && *end != ' ')
			end++;
		reverse(start, end);
		if (end != s.end())
			start = end + 1;
		else
			start = end;
	}
	cout << s << endl;
	return 0;
}


