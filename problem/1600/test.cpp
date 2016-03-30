#include <bits/stdc++.h>

using namespace std;

const int hdy[] = {1, 2, 2, 1, -1, -2, -2, -1};
const int hdx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};

bool visit[31][201][201];
int a[201][201];

int main()
{
	int K;
	int N, M;
	scanf("%d%d%d", &K, &M, &N);

	for(int i=0; i < N; i++)
		for(int j=0; j < M; j++)
			scanf("%d", &a[i][j]);

	queue<pair<int, pair<int, int>>> bfs;
	visit[K][0][0] = true;
	bfs.push({K, {0, 0}});

	int ans = 0;
	while(!bfs.empty())
	{
		int size = bfs.size();
		while(size--)
		{
			int k = bfs.front().first;
			int y = bfs.front().second.first;
			int x = bfs.front().second.second;
			bfs.pop();

			if(y == N-1 && x == M-1)
			{
				printf("%d", ans);
				return 0;
			}

			if(k)
			{
				for(int d=0; d < 8; d++)
				{
					int ny = y + hdy[d];
					int nx = x + hdx[d];
					if(ny < 0 || ny >= N || nx < 0 || nx >= M || visit[k-1][ny][nx] || a[ny][nx] == 1)
						continue;

					visit[k-1][ny][nx] = true;
					bfs.push({k-1, {ny, nx}});
				}
			}
			for(int d=0; d < 4; d++)
			{
				int ny = y + dy[d];
				int nx = x + dx[d];
				if(ny < 0 || ny >= N || nx < 0 || nx >= M || visit[k][ny][nx] || a[ny][nx] == 1)
					continue;

				visit[k][ny][nx] = true;
				bfs.push({k, {ny, nx}});
			}
		}
		ans++;
	}

	puts("-1");
	return 0;
}