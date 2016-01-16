#include <bits/stdc++.h>

using namespace std;

const int MOD = 10007;

int cache[1001];

int solve(int pos)
{
	if(pos < 0)
		return 0;
	if(pos == 0)
		return 1;

	int& ans = cache[pos];
	if(ans != -1)
		return ans;
	return ans = (solve(pos - 1) + 2 * solve(pos - 2)) % MOD;
}

int main()
{
	int N;
	scanf("%d",&N);

	memset(cache, -1, sizeof(cache));
	printf("%d", solve(N));
	return 0;
}