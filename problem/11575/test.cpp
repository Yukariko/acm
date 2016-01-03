#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);

	while(T--)
	{
		int a, b;
		scanf("%d%d",&a,&b);

		char s[1000001];
		scanf("%s", s);

		for(int i=0; s[i]; i++)
			putchar(((s[i] - 'A') * a + b) % 26 + 'A');
		puts("");
	}
	return 0;
}