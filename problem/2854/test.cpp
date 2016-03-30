#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int N;
int a[100001];
int b[100001];
int cache[100001][2];

int solve(int pos, int before)
{
	if(pos == N)
		return 1;

	int& ans = cache[pos][before];
	if(ans != -1)
		return ans;

	if(pos == 0)
	{
		ans = 1LL * a[pos] * solve(pos + 1, false) % MOD;
		ans = (ans + 1LL * b[pos] * solve(pos + 1, true)) % MOD;
	}
	else
	{
		ans = 1LL * (a[pos] + b[pos-1] - before) * solve(pos + 1, false) % MOD;
		ans = (ans + (1LL * b[pos] * solve(pos + 1, true))) % MOD;
	}
	return ans;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	for(int i=0; i < N; i++)
		scanf("%d", &a[i]);
	for(int i=0; i < N-1; i++)
		scanf("%d", &b[i]);
	printf("%d", solve(0, false));
	return 0;
}