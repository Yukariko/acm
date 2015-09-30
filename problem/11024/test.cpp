#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d ",&T);

	while(T--)
	{
		char a[1001];
		gets(a);
		int ans = atoi(strtok(a, " "));

		char *tok;
		while(tok = strtok(NULL, " "))
			ans += atoi(tok);
		printf("%d\n",ans);		
	}

	return 0;
}