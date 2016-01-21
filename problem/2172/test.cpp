#include <bits/stdc++.h>

using namespace std;

const int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
const int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};

int N, L;
int a[21][21];

int cache[21][21][21][21][21];

int solve(int y1, int x1, int y2, int x2, int len)
{
	if(len == 0)
		return 1;

	int& ans = cache[y1][x1][y2][x2][len];
	if(ans != -1)
		return ans;

	ans = 0;

	for(int d=0; d < 8; d++)
	{
		int ny = y1 + dy[d];
		int nx = x1 + dx[d];
		if(ny < 0 || ny >= N || nx < 0 || nx >= N)
			continue;

		for(int d2=0; d2 < 8; d2++)
		{
			int ny2 = y2 + dy[d2];
			int nx2 = x2 + dx[d2];
			if(ny2 < 0 || ny2 >= N || nx2 < 0 || nx2 >= N || a[ny][nx] != a[ny2][nx2])
				continue;

			ans += solve(ny, nx, ny2, nx2, len-1);
		}
	}

	return ans;
}

int main()
{
	scanf("%d%d", &N, &L);
	for(int i=0; i < N; i++)
		for(int j=0; j < N; j++)
			scanf("%d", &a[i][j]);

	memset(cache, -1, sizeof(cache));

	int ans = 0;
	if(L & 1)
		for(int i=0; i < N; i++)
			for(int j=0; j < N; j++)
				ans += solve(i, j, i, j, L / 2);
	else
		for(int i=0; i < N; i++)
			for(int j=0; j < N; j++)
				for(int d=0; d < 8; d++)
				{
					int ny = i + dy[d];
					int nx = j + dx[d];
					if(ny < 0 || ny >= N || nx < 0 || nx >= N || a[i][j] != a[ny][nx])
						continue;

					ans += solve(i, j, ny, nx, L / 2 - 1);
				}					
	
	printf("%d", ans);

	return 0;
}