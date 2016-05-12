#include <bits/stdc++.h>

using namespace std;

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};

const int tok = 500;
bool visit[1001][1001];

int main()
{
	int X, Y, N;
	scanf("%d%d%d", &X, &Y, &N);

	for(int i=0; i < N; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		visit[x+tok][y+tok] = true;
	}

	int ans = 0;

	queue<pair<int, int>> q;
	q.push({0, 0});

	while(!q.empty())
	{
		int size = q.size();
		while(size--)
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if(x == X && y == Y)
			{
				printf("%d", ans);
				return 0;
			}

			for(int d=0; d < 4; d++)
			{
				int nx = x + dx[d];
				int ny = y + dy[d];
				if(nx < -500 || nx > 500 || ny < -500 || ny > 500 || visit[nx+tok][ny+tok])
					continue;

				visit[nx+tok][ny+tok] = true;
				q.push({nx, ny});
			}
		}
		ans++;
	}

	return 0;
}