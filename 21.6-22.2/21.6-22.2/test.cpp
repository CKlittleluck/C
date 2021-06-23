#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	char c;
	while ((c = getchar()) != EOF)
	{
		if (c >= 'A' && c <= 'Z')
		{
			if (c > 'E')
			{
				c -= 5;
			}
			else
			{
				c += 21;
			}
		}
		putchar(c);
	}
	return 0;
}