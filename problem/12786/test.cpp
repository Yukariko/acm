#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int N, K;
bool a[101][21];

int cache[101][21][51];

int solve(int pos, int height, int cnt)
{
	if(cnt < 0)
		return INF;
	if(pos == N)
		return 0;

	int& ans = cache[pos][height][cnt];
	if(ans != -1)
		return ans;

	ans = INF;
	if(a[pos][height])
		ans = min(ans, solve(pos + 1, height, cnt));
	if(height + 1 <= 20 && a[pos][height + 1])
		ans = min(ans, solve(pos + 1, height + 1, cnt));
	if(height - 1 >= 1 && a[pos][height - 1])
		ans = min(ans, solve(pos + 1, height - 1, cnt));
	if(a[pos][min(20, height * 2)])
		ans = min(ans, solve(pos + 1, min(20, height * 2), cnt));

	for(int i=1; i <= 20; i++)
		if(a[pos][i])
			ans = min(ans, 1 + solve(pos + 1, i, cnt - 1));
	return ans;
}

int main()
{
	scanf("%d%d", &N, &K);
	for(int i=0; i < N; i++)
	{
		int l;
		scanf("%d", &l);

		while(l--)
		{
			int n;
			scanf("%d", &n);
			a[i][n] = true;
		}
	}

	memset(cache, -1, sizeof(cache));

	int ans = solve(0, 1, K);
	printf("%d", ans == INF? -1: ans);
	return 0;
}