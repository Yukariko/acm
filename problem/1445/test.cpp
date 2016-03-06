#include <bits/stdc++.h>

using namespace std;

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};
const int INF = 987654321;

struct point
{
	int y, x, g, gs;

	bool operator< (const point& q) const
	{
		return make_pair(g, gs) > make_pair(q.g, q.gs);
	}
};

char a[51][51];

pair<int, int> visit[51][51];

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);

	for(int i=0; i < N; i++)
		scanf("%s", a[i]);

	for(int i=0; i < N; i++)
	{
		for(int j=0; j < M; j++)
		{
			if(a[i][j] != 'g')
				continue;

			for(int d=0; d < 4; d++)
			{
				int ny = i + dy[d];
				int nx = j + dx[d];
				if(ny < 0 || ny >= N || nx < 0 || nx >= M || a[ny][nx] != '.')
					continue;

				a[ny][nx] = 's';
			}
		}
	}

	int sy=-1, sx=-1;
	for(int i=0; i < N && sy == -1; i++)
		for(int j=0; j < M && sy == -1; j++)
			if(a[i][j] == 'S')
				sy = i, sx = j;

	int ey=-1, ex=-1;
	for(int i=0; i < N && ey == -1; i++)
		for(int j=0; j < M && ey == -1; j++)
			if(a[i][j] == 'F')
				ey = i, ex = j;

	fill(&visit[0][0], &visit[51][0], make_pair(INF, INF));

	priority_queue<point> bfs;
	visit[sy][sx] = {0, 0};
	bfs.push({sy, sx, 0, 0});

	pair<int, int> minG = {N*M, N*M};

	while(!bfs.empty())
	{
		point here = bfs.top();
		bfs.pop();

		if(a[here.y][here.x] == 'F' || visit[here.y][here.x] < make_pair(here.g, here.gs))
			continue;

		for(int d=0; d < 4; d++)
		{
			int ny = here.y + dy[d];
			int nx = here.x + dx[d];
			if(ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;

			int ng = here.g + (a[ny][nx] == 'g');
			int ngs = here.gs + (a[ny][nx] == 's');
			if(ng >= 100 || visit[ny][nx] <= make_pair(ng, ngs))
				continue;

			visit[ny][nx] = {ng, ngs};
			bfs.push({ny, nx, ng, ngs});
		}
	}

	printf("%d %d", visit[ey][ex].first, visit[ey][ex].second);
	return 0;
}