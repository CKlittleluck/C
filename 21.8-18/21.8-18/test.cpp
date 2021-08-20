#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int main()
{
	vector<int> v{ 3, 2, 7, 6, 0, 4, 1, 9, 8, 5 };
	priority_queue<int> q1;
	for (auto& e : v)
		q1.push(e);

	for (auto& e : q1)
	{
		cout << q1.top() << endl;
	}
	
	// ���Ҫ����С�ѣ���������ģ���������greater�ȽϷ�ʽ
	priority_queue<int, vector<int>, greater<int>> q2(v.begin(), v.end());
	cout << q2.top() << endl;
	return 0;
}
