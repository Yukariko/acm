#include <bits/stdc++.h>

using namespace std;

long long factorial[11];

int N, R, G, B;
long long cache[101][101][101];

long long solve(int pos, int r, int g, int b)
{
	if(r < 0 || g < 0 || b < 0)
		return 0;
	if(pos == N)
		return 1;

	long long& ans = cache[r][g][b];
	if(ans != -1)
		return ans;

	int k = pos + 1;
	ans = solve(pos + 1, r - k, g, b);
	ans += solve(pos + 1, r, g - k, b);
	ans += solve(pos + 1, r, g, b - k);
	if(k % 2 == 0)
	{
		long long perm = factorial[k] / factorial[k/2] / factorial[k/2];
		ans += perm * solve(pos + 1, r - k / 2, g - k / 2, b);
		ans += perm * solve(pos + 1, r, g - k / 2, b - k / 2);
		ans += perm * solve(pos + 1, r - k / 2, g, b  - k / 2);
	}
	if(k % 3 == 0)
	{
		long long perm = factorial[k] / factorial[k/3] / factorial[k/3] / factorial[k/3];
		ans += perm * solve(pos + 1, r - k/3, g - k/3, b - k/3);
	}
	return ans;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	factorial[0] = 1;
	for(int i=1; i <= 10; i++)
		factorial[i] = factorial[i-1] * i;
	scanf("%d%d%d%d", &N, &R, &G, &B);
	printf("%lld", solve(0, R, G, B));
	return 0;
}