#include <bits/stdc++.h>

using namespace std;

long long cache[21][21][21];

long long solve(int N, int L, int R)
{
	if(N == 0 || L == 0 || R == 0)
		return 0;
	
	if(N == 1 && L == 1 && R == 1)
		return 1;

	long long& ret = cache[N][L][R];
	if(ret != -1)
		return ret;
	return ret = solve(N-1, L-1, R) + solve(N-1, L, R-1) + solve(N-1, L, R) * (N-2);
}

int main()
{
	int T;
	scanf("%d",&T);

	memset(cache, -1, sizeof(cache));
	while(T--)
	{
		int N, L, R;
		scanf("%d%d%d",&N,&L,&R);
		printf("%lld\n",solve(N, L, R));
	}
	return 0;
}