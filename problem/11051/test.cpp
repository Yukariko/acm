#include <bits/stdc++.h>

using namespace std;

const int MOD = 10007;

long long nCm(int N, int K)
{
	if(K == 0)
		return 1;
	return (N * nCm(N-1, K-1)) % MOD;
}

long long factorial(int N)
{
	if(N <= 1)
		return 1;
	return (N * factorial(N-1)) % MOD;
}

long long mod_exp(long long a,long long b,long long c)
{
	a%=c;
	if(b==0)return 1;
	if(b==1)return a;
	if(b&1) return (a*mod_exp((a*a)%c,(b-1)/2,c))%c;
	return mod_exp((a*a)%c,b/2,c);
}

int main()
{
	int N, K;
	scanf("%d%d",&N,&K);

	long long a = nCm(N, K);
	long long b = factorial(K);

	long long mul = mod_exp(b, MOD-2, MOD);
	printf("%lld", (a * mul) % MOD);
	return 0;
}