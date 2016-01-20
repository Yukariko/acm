#include <bits/stdc++.h>

using namespace std;

int main()
{
	char a[256];
	while(gets(a), *a != '#')
	{
		int ans = 0;
		for(int i=0; a[i]; i++)
			if(a[i] >= 'A')
				ans += (i + 1) * (a[i] - 'A' + 1);

		printf("%d\n", ans);
	}
	return 0;
}