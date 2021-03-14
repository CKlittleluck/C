#include <iostream>
using namespace std;



//只能在堆上创建对象
class A
{
private:
	A(int a = 0)
		:_a(a)
	{}

public:
	static A* GetInstance(int a)
	{
		return new A(a);
	}


	static void ReleaseInstance(A* pa)
	{
		if (pa)
			delete pa;
	}

private:
	A(const A&);


private:
	int _a;
};

int main()
{
	A* pa = A::GetInstance(100);
	A::ReleaseInstance(pa);
	return 0;
}