#include <bits/stdc++.h>

using namespace std;

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};

int main()
{
	int N, M;
	scanf("%d%d",&N,&M);
    
	char map[51][51];

	int sy, sx;
	for(int i=0; i < N; i++)
	{
		scanf("%s",map[i]);
		for(int j=0; j < M; j++)
			if(map[i][j] == '0')
				sy = i, sx = j;
	}

	bool visit[65][51][51] = {};
	queue<int> bfs;

	visit[0][sy][sx] = true;
	bfs.push(sy * 50 + sx);

	int ans = 0;
	while(!bfs.empty())
	{
		int size = bfs.size();
		while(size--)
		{
			int key = bfs.front() / 2500;
			int y = bfs.front() % 2500 / 50;
			int x = bfs.front() % 50;
			bfs.pop();

			if(map[y][x] == '1')
			{
				printf("%d", ans);
				return 0;
			}

			for(int d=0; d < 4; d++)
			{
				int ny = y + dy[d];
				int nx = x + dx[d];
				if(ny < 0 || ny >= N || nx < 0 || nx >= M || map[ny][nx] == '#')
					continue;

				int nkey = key;
				if(islower(map[ny][nx]))
					nkey |= 1 << (map[ny][nx] - 'a');
				else if(isupper(map[ny][nx]))
					if(!(nkey & (1 << (map[ny][nx] - 'A'))))
						continue;

				if(visit[nkey][ny][nx])
					continue;

				visit[nkey][ny][nx] = true;
				bfs.push(nkey * 2500 + ny * 50 + nx);
			}
		}
		ans++;
	}

	puts("-1");
	return 0;
}