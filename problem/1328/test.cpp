#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int cache[101][101][101];

int solve(int N, int L, int R)
{
	if(N == 0 || L == 0 || R == 0)
		return 0;
	
	if(N == 1 && L == 1 && R == 1)
		return 1;

	int& ret = cache[N][L][R];
	if(ret != -1)
		return ret;
	return ret = (1LL * solve(N-1, L, R) * (N-2) + solve(N-1, L-1, R) + solve(N-1, L, R-1)) % MOD;
}

int main()
{
	int N, L, R;
	scanf("%d%d%d",&N,&L,&R);
	memset(cache, -1, sizeof(cache));
	printf("%d\n",solve(N, L, R));
	return 0;
}