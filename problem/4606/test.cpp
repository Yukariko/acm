#include <bits/stdc++.h>

using namespace std;

const char *encode = " !$%()*";

int main()
{
	char a[80];
	while(gets(a), *a != '#')
	{
		for(int i=0; a[i]; i++)
		{
			bool check = false;
			for(int j=0; encode[j]; j++)
				if(a[i] == encode[j])
					check = true;

			if(check)
				printf("%%%x", a[i]);
			else
				putchar(a[i]);
		}
		puts("");
	}
	return 0;
}