#include <iostream>
#include <string>
using namespace std;


/*char FIND(const string str)
{
int i, j;
for(i = 0; i < str.size(); i++)
{
for(j = 0; j < str.size(); j++)
{
if(j == i)
continue;
if(str[i] == str[j])
break;
}
if(j >= str.size())
return str[i];
}
return -1;
}
*/



/*char FIND(const string str)
{
int bush[256] = {0};
for(int i = 0; i < str.size(); i++)
{
bush[str[i]]++;
}

for(int i = 0; i < str.size(); i++)
{
if(bush[str[i]] == 1)
return str[i];
}
return -1;
}*/

char FIND(const string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		int index = str.find(str[i]);
		int index1 = str.rfind(str[i]);
		if (index == index1)
			return str[i];
	}
	return -1;
}


int main()
{
	string str;
	char res;
	while (getline(cin, str))
	{
		res = FIND(str);
		if (res == -1)
			cout << -1 << endl;
		else
			cout << res << endl;
	}
	return 0;
}