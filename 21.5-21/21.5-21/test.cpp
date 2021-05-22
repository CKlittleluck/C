#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


string FoundMax(const string &line)
{
	if (line.find("joker JOKER") != string::npos)
		return "joker JOKER";

	int dash = line.find("-");
	string car1 = line.substr(0, dash);
	string car2 = line.substr(dash + 1);

	int car1_cnt = count(car1.begin(), car1.end(), ' ') + 1;
	int car2_cnt = count(car2.begin(), car2.end(), ' ') + 1;

	string car1_first = car1.substr(0, car1.find(" "));
	string car2_first = car2.substr(0, car2.find(" "));

	if (car1_cnt == car2_cnt)
	{
		string str = "345678910JQKA2jokerJOKER";
		if (str.find(car1_first) > str.find(car2_first))
			return car1;
		return car2;
	}

	if (car1_cnt == 4)
		return car1;
	else if (car2_cnt == 4)
		return car2;
	return "ERROR";
}

int main()
{
	string line, res;
	while (getline(cin, line))
	{
		res = FoundMax(line);
		cout << res << endl;
	}

	return 0;
}