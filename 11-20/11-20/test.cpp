#include<iostream>
using namespace std;

#include<string>

//�ַ������һ�����ʵĳ���
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

