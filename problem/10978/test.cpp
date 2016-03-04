#include <bits/stdc++.h>

using namespace std;

/*
long long cache[21][1<<20];
long long solve(int pos, int mask)
{
	if(pos == N)
		return 1;

	long long& ans = cache[pos][mask];
	if(ans != -1)
		return ans;

	ans = 0;
	for(int i=0; i < N; i++)
		if(i != pos && (mask & (1 << i)) == 0)
			ans += solve(pos + 1, mask | (1 << i));
	return ans;
}
*/
int main()
{
	int T;
	scanf("%d", &T);

	long long ans[21] = {0,0,1,2,9,44,265,1854,14833,133496,1334961,14684570,176214841,2290792932,32071101049,481066515734,7697064251745,130850092279664,2355301661033953,44750731559645106,895014631192902121};
	while(T--)
	{
		int N;
		scanf("%d", &N);
		printf("%lld\n", ans[N]);
	}
	return 0;
}