#include <bits/stdc++.h>

using namespace std;

int main()
{
	char a[1001];
	while(gets(a))
	{
		for(int i=0; a[i]; i+=2)
		{
			int c;
			sscanf(a + i, "%2x", &c);
			printf("%c", c);
		}
		puts("");
	}
	return 0;
}