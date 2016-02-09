#include <bits/stdc++.h>

using namespace std;

char a[81];

long long cache[81][2][10];

long long solve(int pos, bool eq, int last)
{
	if(!a[pos])
		return !eq;

	long long& ans = cache[pos][eq][last];
	if(ans != -1)
		return ans;

	ans = 0;
	int end = eq? a[pos] - '0': 9;
	for(int i=last; i <= end; i++)
		ans += solve(pos + 1, eq? a[pos]-'0' == i: false, i);

	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		scanf("%s", a);

		bool check = true;
		for(int i=1; a[i]; i++)
			if(a[i-1] > a[i])
				check = false;

		if(check == false)
		{
			puts("-1");
			continue;
		}

		memset(cache, -1, sizeof(cache));
		printf("%lld\n", solve(0, true, 0));
	}
	return 0;
}