#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;

long long factorial(long long a)
{
	long long ans = 1;
	while(a)
	{
		ans = ans * a % MOD;
		a--;
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

long long solve(long long N)
{
	long long a = factorial(N * 2);
	long long b = factorial(N);
	long long c = mod_exp(b, MOD-2, MOD);
	a = a * c % MOD;
	a = a * c % MOD;
	b = mod_exp(2, MOD-2, MOD);
	return a * b % MOD;
}

int main()
{
	long long N;
	scanf("%lld", &N);

	long long ans = solve(N);
	if(N % 2 == 0)
		ans = (ans + MOD - solve(N / 2)) % MOD;

	printf("%lld", ans);
	return 0;
}