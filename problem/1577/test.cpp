#include <bits/stdc++.h>

using namespace std;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int N, M, K;

bool noPass[101][101][4];
long long cache[101][101];

long long solve(int y, int x)
{
	if(y == N && x == M)
		return 1;

	long long& ans = cache[y][x];
	if(ans != -1)
		return ans;

	ans = 0;
	for(int d=0; d < 2; d++)
	{
		int ny = y + dy[d];
		int nx = x + dx[d];
		if(ny > N || nx > M || noPass[y][x][d])
			continue;

		ans += solve(ny, nx);
	}

	return ans;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%d%d%d", &N, &M, &K);

	for(int i=0; i < K; i++)
	{
		int uy, ux, vy, vx;
		scanf("%d%d%d%d", &uy, &ux, &vy, &vx);

		for(int d=0; d < 4; d++)
		{
			int ny = uy + dy[d];
			int nx = ux + dx[d];
			if(vy == ny && vx == nx)
			{
				if(d < 2)
					noPass[uy][ux][d] = true;
				else
					noPass[ny][nx][d - 2] = true;
			}
		}
	}

	printf("%lld", solve(0, 0));
	return 0;
}