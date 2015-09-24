#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

const long long MOD = 1000000007LL;

long long mod_exp(long long a,long long b)
{
	a %= MOD;
	if(b==0)return 1;
	if(b==1)return a;
	if(b&1) return (a*mod_exp((a*a) % MOD,(b-1)/2)) % MOD;
	return mod_exp((a*a) % MOD,b/2);
}

long long mod_minus(long long a, long long b)
{
	return (a - b + MOD) % MOD;
}
long long d[52][52] = {};

long long mod_nCm(long long n, long long m)
{
	for(int i=0; i <= n; i++)
		d[i][0] = d[i][i] = 1;
	for(int i=1; i <= n; i++)
		for(int j=1; j < i; j++)
			d[i][j] = (d[i-1][j] + d[i-1][j-1]) % MOD;
	return d[n][m];
}

long long dp[51];

long long Faulhaber(int N, int K)
{
	long long& ans = dp[K];
	if(ans != -1)
		return ans;

	ans = mod_minus(mod_exp(N+1, K+1), 1);

	for(int i=0; i < K; i++)
	{
		long long cache = d[K+1][i] * Faulhaber(N, i) % MOD;
		ans = mod_minus(ans, cache);
	}

	ans = (ans * mod_exp(K+1, MOD-2)) % MOD;
	return ans;
}

int main()
{	
	int N, K;
	scanf("%d%d",&N,&K);
	mod_nCm(K+1,K+1);
	memset(dp, -1, sizeof(dp));
	cout << Faulhaber(N, K);
	return 0;
}