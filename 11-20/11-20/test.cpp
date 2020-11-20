#include<iostream>
using namespace std;

#include<string>

//字符串最后一个单词的长度
int main()
{
	string line;
	while (getline(cin, line))
	{
		size_t pos = line.rfind(' ');
		cout << line.size() - pos - 1 << endl;
	}
	return 0;
}

//

