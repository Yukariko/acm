#include <bits/stdc++.h>

using namespace std;

long long cache[1001][10];

long long solve(int pos, int last)
{
	if(pos == 0)
		return 1;

	long long& ans = cache[pos][last];
	if(ans != -1)
		return ans;

	ans = 0;
	for(int i=last; i <= 9; i++)
		ans += solve(pos - 1, i);
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);

	memset(cache, -1, sizeof(cache));
	solve(1000, 0);

	while(T--)
	{
		int N;
		scanf("%d", &N);
		printf("%lld\n", cache[N][0]);
	}
	return 0;
}