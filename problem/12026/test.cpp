#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
const char *mark = "BOJ";

int N;
char a[1001];

int cache[1001][3];

int solve(int pos, int idx)
{
	if(pos == N-1)
		return 0;

	int& ans = cache[pos][idx];
	if(ans != -1)
		return ans;

	ans = INF;
	for(int i=pos+1; i < N; i++)
		if(a[i] == mark[idx])
			ans = min(ans, (i - pos) * (i - pos) + solve(i, (idx + 1) % 3));
	return ans;
}

int main()
{
	scanf("%d %s", &N, a);
	memset(cache, -1, sizeof(cache));

	int ans = solve(0, 1);
	printf("%d", ans == INF? -1: ans);
	return 0;
}