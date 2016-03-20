#include <bits/stdc++.h>

using namespace std;

const char *mv = "LRUD";
const int dy[] = {0, 0, -1, 1};
const int dx[] = {-1, 1, 0, 0};

int N, M;
char a[11][11];
pair<int, int> jump[11][11][4];

vector<int> paths;

void solve(int sy, int sx)
{
	queue<pair<int, pair<int, int>>> bfs;

	bfs.push({1, {sy, sx}});

	int dist = 0;
	while(!bfs.empty())
	{
		int size = bfs.size();
		while(size--)
		{
			int mask = bfs.front().first;
			int hy = bfs.front().second.first;
			int hx = bfs.front().second.second;
			bfs.pop();

			if(a[hy][hx] == 'O')
			{
				paths.push_back(mask);
				continue;
			}

			for(int d=0; d < 4; d++)
			{
				int ny = jump[hy][hx][d].first;
				int nx = jump[hy][hx][d].second;
				int nmask = (mask << 2) | d;			
				bfs.push({nmask, {ny, nx}});
			}
		}
		dist++;
		if(dist == 11)
			break;
	}
}

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		scanf("%d%d", &N, &M);
		for(int i=0; i < N; i++)
			scanf("%s", a[i]);

		for(int i=0; i < N; i++)
			for(int j=0; j < M; j++)
				if(a[i][j] == '.')
					for(int d=0; d < 4; d++)
					{
						int y = i, x = j;
						while(y >= 0 && y < N && x >= 0 && x < M && a[y][x] != '#')
							y += dy[d], x += dx[d];
						y -= dy[d];
						x -= dx[d];
						jump[i][j][d] = {y, x};
					}

		paths.clear();

		vector<pair<int, int>> dot;
		for(int i=0; i < N; i++)
			for(int j=0; j < M; j++)
				if(a[i][j] == '.')
					dot.push_back({i, j});

		solve(dot[0].first, dot[0].second);

		bool find = false;
		for(size_t i=0; i < paths.size(); i++)
		{
			bool possible = true;
			string path;

			int mask = paths[i];
			while(mask != 1)
			{
				path += '0' + (mask % 4);
				mask /= 4;
			}

			reverse(path.begin(), path.end());

			for(size_t j=1; j < dot.size(); j++)
			{
				int y = dot[j].first, x = dot[j].second;
				for(int k=0; path[k]; k++)
				{
					int d = path[k] - '0';
					int ny = jump[y][x][d].first;
					int nx = jump[y][x][d].second;
					y = ny, x = nx;

					if(a[y][x] == 'O')
						break;
				}

				if(a[y][x] != 'O')
				{
					possible = false;
					break;
				}
			}

			if(possible)
			{
				for(int j=0; path[j]; j++)
					path[j] = mv[path[j]-'0'];
				puts(path.c_str());
				find = true;
				break;
			}
		}

		if(!find)
			puts("XHAE");
	}
	return 0;
}