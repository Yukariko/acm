#include <bits/stdc++.h>

using namespace std;

int main()
{
	char a[251];
	while(gets(a), a[0] != '#')
	{
		bool visit[127] = {};
		for(int i=0; a[i]; i++)
			visit[a[i] | 32] = true;

		int ans = 0;
		for(int i='a'; i <= 'z'; i++)
			ans += visit[i];

		printf("%d\n", ans);
	}
	return 0;
}