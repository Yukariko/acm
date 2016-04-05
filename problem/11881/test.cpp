#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int N;
int a[100001];
int sum[100001];
int cache[100001][4];
int solve(int pos, int cnt)
{
	if(cnt == 0)
		return 1;

	int& ans = cache[pos][cnt];
	if(ans != -1)
		return ans;

	ans = 0;
	if(sum[pos] >= cnt || !a[pos])
		ans = (ans + solve(pos + 1, cnt)) % MOD;
	if(a[pos])
		ans = (ans + 1LL * a[pos] * pos * solve(pos + 1, cnt - 1)) % MOD;
	return ans;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	for(int i=0; i < N; i++)
	{
		int n;
		scanf("%d", &n);
		a[n]++;
	}

	for(int i=99999; i; i--)
		sum[i] = sum[i+1] + !!a[i+1];
	printf("%d", solve(1, 3));
	return 0;
}