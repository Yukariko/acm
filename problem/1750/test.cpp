#include <bits/stdc++.h>

using namespace std;

const int MOD = 10000003;

int gcd(int p, int q)
{
	return q? gcd(q, p % q): p;
}

int N;
int a[101];

int cache[101][100001];
int solve(int pos, int g)
{
	if(pos == N)
		return g == 1;

	int& ans = cache[pos][g];
	if(ans != -1)
		return ans;

	ans = solve(pos + 1, g);
	ans = (ans + solve(pos + 1, g? gcd(g, a[pos]): a[pos])) % MOD;
	return ans;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	for(int i=0; i < N; i++)
		scanf("%d", &a[i]);

	printf("%d", solve(0, 0));
	return 0;
}