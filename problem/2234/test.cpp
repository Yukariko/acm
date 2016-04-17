#include <bits/stdc++.h>

using namespace std;

const int WEST = 1;
const int NORTH = 2;
const int EAST = 4;
const int SOUTH = 8;

const int dy[] = {0, -1, 0, 1};
const int dx[] = {-1, 0, 1, 0};

int N, M;
int a[51][51];
int visit[51][51];
int sum[2501];

int check(int y, int x, int idx)
{
	visit[y][x] = idx;
	int ans = 1;
	for(int d=0; d < 4; d++)
	{
		int ny = y + dy[d];
		int nx = x + dx[d];
		if(ny < 0 || ny >= N || nx < 0 || nx >= M || visit[ny][nx] || (a[y][x] & (1 << d)))
			continue;
		ans += check(ny, nx, idx);
	}
	return ans;
}

int main()
{
	scanf("%d%d", &M, &N);
	for(int i=0; i < N; i++)
		for(int j=0; j < M; j++)
			scanf("%d", &a[i][j]);

	int nRoom = 0;
	int maxRoom = 0;
	int sumRoom = 0;
	for(int i=0; i < N; i++)
	{
		for(int j=0; j < M; j++)
		{
			if(visit[i][j])
				continue;
			nRoom++;
			sum[nRoom] = check(i, j, nRoom);
			maxRoom = max(maxRoom, sum[nRoom]);
		}
	}

	for(int i=0; i < N; i++)
	{
		for(int j=0; j < M; j++)
		{
			for(int k=0; k < 4; k++)
			{
				int y = i + dy[k];
				int x = j + dx[k];
				if(y < 0 || y >= N || x < 0 || x >= M || visit[i][j] == visit[y][x])
					continue;

				sumRoom = max(sumRoom, sum[visit[i][j]] + sum[visit[y][x]]);
			}
		}
	}

	printf("%d\n%d\n%d", nRoom, maxRoom, sumRoom);
	return 0;
}