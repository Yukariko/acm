#include <bits/stdc++.h>

using namespace std;

int main()
{
	char a[256];
	while(gets(a), a[0] != '#')
	{
		stringstream ss(a);
		string s;
		while(ss >> s)
		{
			putchar(s[0]);
			for(size_t i=1; i < s.length() - 1; i++)
				putchar(s[s.length() - i - 1]);
			if(s.length() > 1)
				putchar(s[s.length()-1]);
			putchar(' ');
		}
		puts("");
	}
	return 0;
}