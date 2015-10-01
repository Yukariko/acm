#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1, -1, -2, -2, 1, 1, 2, 2};
const int dy[] = {-2, 2, -1, 1, -2, 2, -1, 1};

int main()
{
	int T;
	scanf("%d",&T);

	while(T--)
	{
		int L;
		scanf("%d",&L);

		int sx, sy;
		scanf("%d%d",&sx,&sy);

		int ex, ey;
		scanf("%d%d",&ex,&ey);

		queue< pair<int, int> > bfs;

		bool visit[301][301] = {};

		int ans = 0;
		visit[sx][sy] = true;
		bfs.push(make_pair(sx, sy));
		while(!bfs.empty())
		{
			int N = bfs.size();
			while(N--)
			{
				pair<int, int> here = bfs.front();
				bfs.pop();

				if(here.first == ex && here.second == ey)
				{
					bfs = queue< pair<int, int> >();
					break;
				}

				for(int d=0; d < 8; d++)
				{
					int nx = here.first + dx[d];
					int ny = here.second + dy[d];
					if(nx < 0 || nx >= L || ny < 0 || ny >= L || visit[nx][ny])
						continue;
					visit[nx][ny] = true;
					bfs.push(make_pair(nx, ny));
				}
			}
			ans++;
		}

		printf("%d\n",ans - 1);
	}
	return 0;
}