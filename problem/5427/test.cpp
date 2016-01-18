#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};

int W, H;
char a[1001][1001];
int fire[1001][1001];

void set_fire(int y, int x)
{
	queue<pair<int, int>> bfs;
	bfs.push({y, x});
	fire[y][x] = 0;
	for(int t=1; !bfs.empty(); t++)
	{
		int n = bfs.size();
		while(n--)
		{
			y = bfs.front().first;
			x = bfs.front().second;
			bfs.pop();

			for(int d=0; d < 4; d++)
			{
				int ny = y + dy[d];
				int nx = x + dx[d];

				if(ny < 0 || ny >= H || nx < 0 || nx >= W ||
				 fire[ny][nx] <= t || a[ny][nx] != '.')
					continue;
				fire[ny][nx] = t;
				bfs.push({ny, nx});
			}
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		scanf("%d%d", &W, &H);

		bool visit[1001][1001] = {};

		queue<pair<int, int>> bfs;

		for(int i=0; i < H; i++)
		{
			scanf("%s", a[i]);
			if(bfs.empty())
				for(int j=0; a[i][j]; j++)
					if(a[i][j] == '@')
						bfs.push({i, j});
		}
		
		fill(fire[0], fire[H], INF);
		for(int i=0; i < H; i++)
			for(int j=0; j < W; j++)
				if(a[i][j] == '*')
					set_fire(i, j);

		bool success = false;

		for(int t=1; !bfs.empty(); t++)
		{
			int n = bfs.size();
			while(n--)
			{
				int y = bfs.front().first;
				int x = bfs.front().second;
				bfs.pop();

				if(y == 0 || y == H-1 || x == 0 || x == W-1)
				{
					printf("%d\n", t);
					success = true;
					break;
				}

				for(int d=0; d < 4; d++)
				{
					int ny = y + dy[d];
					int nx = x + dx[d];

					if(ny < 0 || ny >= H || nx < 0 || nx >= W ||
					 fire[ny][nx] <= t || a[ny][nx] != '.' || visit[ny][nx])
						continue;
					visit[ny][nx] = true;
					bfs.push({ny, nx});
				}
			}
			if(success)
				break;
		}

		if(success == false)
			puts("IMPOSSIBLE");
	}
	return 0;
}