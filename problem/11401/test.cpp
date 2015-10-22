#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007LL;

long long nCm(int N, int K)
{
	if(K == 0)
		return 1;
		long long ans = 1;
		while(K--)
		{
				ans = (ans * N) % MOD;
				N--;
		}
	return ans;
}

long long factorial(int N)
{
	if(N <= 1)
		return 1;
		long long ans = 1;
		while(N)
		{
				ans = (ans * N) % MOD;
				N--;
		}
	return ans;
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