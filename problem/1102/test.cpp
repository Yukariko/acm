#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int N, P;
int a[16][16];
char b[17];

int cache[1<<16];

int solve(int mask, int cnt)
{
	if(cnt >= P)
		return 0;

	int& ans = cache[mask];
	if(ans != -1)
		return ans;

	ans = INF;
	for(int i=0; i < N; i++)
	{
		if((mask & (1 << i)) == 0)
		{
			int sel = 101;
			for(int j=0; j < N; j++)
				if(i != j && (mask & (1 << j)))
					sel = min(sel, a[j][i]);

			ans = min(ans, sel + solve(mask | (1 << i), cnt+1));
		}
	}
	return ans;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	for(int i=0; i < N; i++)
		for(int j=0; j < N; j++)
			scanf("%d", &a[i][j]);
	scanf("%s", b);
	scanf("%d", &P);

	int mask = 0, cnt = 0;
	for(int i=0; i < N; i++)
		if(b[i] == 'Y')
			mask |= 1 << i, cnt++;

	int ans = solve(mask, cnt);
	printf("%d", ans == INF? -1: ans);
	return 0;
}