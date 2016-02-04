#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};

int N, M;
char a[51][51];
int mark[51][51];

bool cache[51][51][5][4];

struct point 
{
	int y, x, d, m;
};

int main()
{
	scanf("%d%d", &N, &M);
	for(int i=0; i < N; i++)
		scanf("%s", a[i]);


	int sy = -1;
	int sx = -1;
	int C = 0;
	for(int i=0; i < N; i++)
	{
		for(int j=0; j < M; j++)
		{
			if(a[i][j] == 'S')
				sy = i, sx = j;
			else if (a[i][j] == 'C')
				mark[i][j] = 1 << C++;
		}
	}

	queue<point> bfs;
	bfs.push({sy, sx, 4, 0});

	for(int t=1; !bfs.empty(); t++)
	{
		int size = bfs.size();
		while(size--)
		{
			point p = bfs.front();
			bfs.pop();

			for(int i=0; i < 4; i++)
			{
				if(p.d == i)
					continue;

				int ny = p.y + dy[i];
				int nx = p.x + dx[i];
				int nm = p.m;

				if(ny < 0 || ny >= N || nx < 0 || nx >= M || a[ny][nx] == '#')
					continue;

				if(a[ny][nx] == 'C')
					nm |= mark[ny][nx];

				else if(cache[ny][nx][i][nm])
					continue;

				cache[ny][nx][i][nm] = true;

				if(nm == 3)
				{
					printf("%d", t);
					return 0;
				}

				bfs.push({ny, nx, i, nm});
			}

		}
	}

	puts("-1");
	return 0;
}