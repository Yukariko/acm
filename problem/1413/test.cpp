#include <bits/stdc++.h>

using namespace std;

int N, M;
long long cache[21][21];
long long factorial[21];

long long gcd(long long a, long long b)
{
	return b? gcd(b, a % b): a;
}

long long nPm(int n, int m)
{
	return factorial[n] / factorial[n - m];
}

long long solve(int key, int bomb)
{
	if(key == 0)
		return 1;
	if(bomb == 0)
		return 0;

	long long& ans = cache[key][bomb];
	if(ans != -1)
		return ans;

	ans = 0;
	for(int i=1; i <= key; i++)
		ans += nPm(key-1, i-1) * solve(key - i, bomb - 1);

	return ans;
}

int main()
{
	factorial[0] = 1;
	for(int i=1; i <= 20; i++)
		factorial[i] = factorial[i-1] * i;

	memset(cache, -1,  sizeof(cache));
	scanf("%d%d",&N,&M);

	long long ans = solve(N, M);
	long long total = factorial[N];
	long long g = gcd(ans, total);
	ans /= g;
	total /= g;

	printf("%lld/%lld", ans, total);
	return 0;
}