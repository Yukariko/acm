#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int N, M;
int a[11];
int cache[11][1024];

int solve(int pos, int mask)
{
	if(pos == N)
		return mask == (1 << M) - 1? 0: INF;

	int& ans = cache[pos][mask];
	if(ans != -1)
		return ans;

	ans = solve(pos + 1, mask);
	ans = min(ans, 1 + solve(pos + 1, mask | a[pos]));
	return ans;
}

int main()
{
	scanf("%d%d", &M, &N);
	for(int i=0; i < N; i++)
	{
		int l;
		scanf("%d", &l);

		while(l--)
		{
			int n;
			scanf("%d", &n);
			n--;
			a[i] |= 1 << n;
		}
	}

	memset(cache, -1, sizeof(cache));
	int ans = solve(0, 0);
	printf("%d", ans == INF? -1: ans);
	return 0;
}