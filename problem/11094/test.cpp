#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d ",&T);

	while(T--)
	{
		char a[101];
		gets(a);
		if(strncmp(a, "Simon says", 10) == 0)
			puts(a+10);
	}
	return 0;
}