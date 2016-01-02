#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d ",&T);

	while(T--)
	{
		char a[1001];
		char b[27];
		gets(a);
		gets(b);

		for(int i=0; a[i]; i++)
			if(isalpha(a[i]))
				putchar(b[a[i]-'A']);
			else
				putchar(a[i]);

		puts("");
	}
	return 0;
}