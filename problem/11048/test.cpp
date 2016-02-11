#include <bits/stdc++.h>

using namespace std;

const int dy[] = {0, 1, 1};
const int dx[] = {1, 0, 1};

int N, M;
int a[1001][1001];

int cache[1001][1001];

int solve(int y, int x)
{
	if(y == N-1 && x == M-1)
		return a[y][x];

	int& ans = cache[y][x];
	if(ans != -1)
		return ans;

	ans = a[y][x];
	for(int d=0; d < 3; d++)
	{
		int ny = y + dy[d];
		int nx = x + dx[d];
		if(ny >= N || nx >= M)
			continue;

		ans = max(ans, a[y][x] + solve(ny, nx));
	}

	return ans;
}

int main()
{
	scanf("%d%d", &N, &M);
	for(int i=0; i < N; i++)
		for(int j=0; j < M; j++)
			scanf("%d", &a[i][j]);

	memset(cache, -1, sizeof(cache));
	printf("%d", solve(0, 0));
	return 0;
}