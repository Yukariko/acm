#include <bits/stdc++.h>

using namespace std;

const int INF = -150000001;

const int dy[] = {1, 0, 0};
const int dx[] = {0, 1, -1};

int N, M;
int a[1001][1001];

int cache[1001][1001][3];

int solve(int y, int x, int dir)
{
	if(y == N-1 && x == M-1)
		return a[y][x];

	int& ans = cache[y][x][dir];
	if(ans != INF)
		return ans;

	for(int d=0; d < 3; d++)
	{
		if(dir * d == 2)
			continue;
		int ny = y + dy[d];
		int nx = x + dx[d];
		if(ny >= N || nx < 0 || nx >= M)
			continue;
		ans = max(ans, a[y][x] + solve(ny, nx, d));
	}
	return ans;
}

int main()
{
	fill(&cache[0][0][0], &cache[1001][0][0], INF);
	scanf("%d%d", &N, &M);
	for(int i=0; i < N; i++)
		for(int j=0; j < M; j++)
			scanf("%d", &a[i][j]);

	printf("%d", solve(0, 0, 0));
	return 0;
}