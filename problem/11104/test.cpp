#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d ",&T);

	while(T--)
	{
		char a[25];
		gets(a);
		printf("%d\n", strtol(a, NULL, 2));
	}
	return 0;
}