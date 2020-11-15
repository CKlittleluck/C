#include<iostream>
using namespace std;
#include<string>

void TestString1()
{
	string s1;
	string s2("hello world");
	string s3(s2);
	string s4(10, 'a');
	string s5("hello", 3);

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;

	cin >> s1;
	cout << s1 << endl;
}


//容量
void TestString2()
{
	string s1("hello");
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.capacity << endl;

	//s1 = "";
	s1.clear();
	if (s1.empty())
	{
		cout << "空字符串" << endl;
	}
	else
	{
		cout << "非空" << endl;
	}
	s1 = "";
}

//resize
//void resize(size_t n, char c)
//void resize(size_t n)
void TestString3()
{
	string s1("kangkangjiayou");
	s1.resize(20);
	s1.resize(20, '!');
}


//reserve
void TestString4()
{
	string s1("kangkangjiayou");
	s1.reserve(10);
	s1.reserve(20);
	s1.reserve(30);
	s1.reserve(10);
}

//元素访问
void TestString5()
{
	string s1("kangkangjiayou");

	//用assert检验是否越界
	cout << s1[0] << endl;
	s1[0] = 'h';

	//用异常来检测 很少用
	cout << s1.at(0) << endl;
	s1.at(0) = 'h';
}

//修改
void TestString6()
{
	string s1("kangkangjiayou");
	cout << s1 << endl;

	s1.push_back('!');
	s1 += "haha";

	string s2("@@@@");
	s1 += s2;
	s1 += '#';

	s1.append(1, '$');
	s1.append(s1, 2, 3);
}


void TestString7()
{
	string s1("kangkang jiayou");
	s1.insert(s1.find(' '), "@@@");
}

void TestString8()
{
	string s2;
	//cin >> s2;

	getline(cin, s2);
	cout << s2 << endl;
	cout << s2.substr(s2.rfind(' ') + 1).size() << endl;

}



int main()
{
	TestString1();
	TestString2();
	return 0;
}