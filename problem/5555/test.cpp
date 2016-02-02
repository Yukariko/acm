#include <bits/stdc++.h>

using namespace std;

int main()
{
	char a[21];
	int len = strlen(gets(a));

	int T;
	scanf("%d", &T);

	int ans = 0;
	while(T--)
	{
		char b[21];
		scanf("%s", b);

		for(int i=0; i < len-1; i++)
			b[10 + i] = b[i];

		for(int i=0; i < 10; i++)
			if(strncmp(b+i, a, len) == 0)
			{
				ans++;
				break;
			}
	}

	printf("%d", ans);
	return 0;
}