#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int N, K;
int cache[1001][10001];

int solve(int pos, int cnt)
{
	if(cnt < 0)
		return 0;
	if(pos == 0)
		return cnt == 0;

	int& ans = cache[pos][cnt];
	if(ans != -1)
		return ans;

	ans = (solve(pos, cnt - 1) + solve(pos - 1, cnt)) % MOD;
	ans = (ans - solve(pos - 1, cnt - pos) + MOD) % MOD;
	return ans;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%d%d", &N, &K);
	printf("%d", solve(N, K));
	return 0;
}