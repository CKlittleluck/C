#include <iostream>
#include <map>
#include <string>
#include <queue>
#include <set>

using namespace std;

#if 0
int main()
{
	map<string, string> m1;
	m1.insert(pair<string, string>("apple", "苹果"));
	m1.insert(pair<string, string>("orange", "橘子"));

	m1.insert(make_pair("peach", "桃子"));
	m1.insert(make_pair("watermalon", "西瓜"));

	//范围for打印
	for (auto&  e : m1)
	{
		cout << "<" << e.first << "," << e.second << ">" << endl;
	}

	//迭代器
	cout << m1.size() << endl;
	auto it = m1.begin();
	while (it != m1.end())
	{
		cout << "<" << it->first << "," << (*it).second << ">" << endl;
		++it;
	}

	//反向迭代器

	auto rit = m1.rbegin();
	while (rit != m1.rend())
	{
		cout << "<" << rit->first << "," << (*it).second << ">" << endl;
		++rit;
	}

	cout << m1["peach"] << endl;
	cout << m1["pear"] << endl;

	m1["pear"] = "梨";
	cout << m1["pear"] << endl;



	//删除
	//1
	m1.erase("pear");

	//2
	auto pos = m1.find("pear");
	if (pos != m1.end())
	{
		m1.erase(pos);
	}

	//3
	m1.erase(m1.begin(), m1.end());  //m1.clear()
	return 0;
}
#endif

class Compare
{
	bool operator()(const pair<string, size_t>& left, const pair<string, size_t>& right)
	{
		return left.second < right.second;
	}
};

#if 0
int main()
{
	string fruits[] = { "apple", "apple", "apple", "apple", "bananan",  "pear"};
	map <string, size_t> m;
	for (auto& e : fruits)
		m[e]++;


	priority_queue<pair<string, size_t>, vector<pair<string, size_t>>, Compare> q(m.begin(), m.end());

	vector <string> favourite;
	for (size_t i = 0; i < 3; ++i)
	{
		favourite.push_back(q.top().first);
		q.pop();
	}

	// 水果—按字典方式排序
	sort(favourite.begin(), favourite.end());


	//2
	set<string> s;
	for (size_t i = 0; i < 3; ++i)
	{
		s.insert(q.top().first);
		q.pop();
	}


	return 0;
}
#endif

//set
int main()
{
	string fruits[] = { "apple", "apple", "apple", "apple", "bananan", "pear" };
	set<string> s(fruits, fruits + sizeof(fruits) / sizeof(fruits[0]));
	for (auto & e : s)
	{
		cout << e << "";
	}
	cout << endl;
	return 0;
}