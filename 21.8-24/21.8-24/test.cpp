#include <iostream>
using namespace std;

class A {
public:
	friend void set_show(int x, A &a); //�ú�������Ԫ����������
private:
	int data;
};
void set_show(int x, A &a) //��Ԫ�������壬Ϊ�˷�����A�еĳ�Ա
{
	a.data = x;
	cout << a.data << endl;
}
int main(void) {
	class A a;
	set_show(1, a);
	return 0;
}


class A {
public:
	friend class C; //������Ԫ�������
private:
	int data;
};
class C //��Ԫ�ඨ�壬Ϊ�˷�����A�еĳ�Ա
{
public:
	void set_show(int x, A &a) { a.data = x; cout << a.data << endl; }
};
int main(void) {
	class A a;
	class C c;
	c.set_show(1, a);
	return 0;
}
