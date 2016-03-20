#include <bits/stdc++.h>

using namespace std;

char a[10001], b[101];

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		scanf("%s%s", a, b);
		
		int blen = strlen(b);
		int ans = 0;
		for(int i=0; a[i]; i++)
		{
			if(strncmp(a + i, b, blen) == 0)
				i += blen-1;
			ans++;
		}

		printf("%d\n", ans);
	}
	return 0;
}