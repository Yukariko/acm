#include <bits/stdc++.h>

using namespace std;

const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};

int N, M, K;
char a[101][101];
char b[81];

int cache[101][101][81];

int solve(int y, int x, int pos)
{
	if(!b[pos])
		return 1;

	int& ans = cache[y][x][pos];
	if(ans != -1)
		return ans;

	ans = 0;
	for(int d=0; d < 4; d++)
	{
		for(int k=1; k <= K; k++)
		{
			int ny = y + dy[d] * k;
			int nx = x + dx[d] * k;

			if(ny < 0 || ny >= N || nx < 0 || nx >= M || a[ny][nx] != b[pos])
				continue;

			ans += solve(ny, nx, pos+1);
		}
	}
	return ans;
}

int main()
{
	scanf("%d%d%d", &N, &M, &K);
	for(int i=0; i < N; i++)
		scanf("%s", a[i]);
	scanf("%s", b);

	memset(cache, -1, sizeof(cache));

	int ans = 0;
	for(int i=0; i < N; i++)
		for(int j=0; j < M; j++)
			if(a[i][j] == b[0])
				ans += solve(i, j, 1);

	printf("%d", ans);
	return 0;
}