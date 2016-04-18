#include <bits/stdc++.h>

using namespace std;

int N;
char a[101][101];

const int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
const int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};

int main()
{
	scanf("%d", &N);
	for(int i=0; i < N; i++)
		scanf("%s", &a[i]);

	vector<pair<int, int>> B, E;
	for(int i=0; i < N; i++)
		for(int j=0; j < N; j++)
			if(a[i][j] == 'B')
				B.push_back({i, j});
			else if(a[i][j] == 'E')
				E.push_back({i, j});

	sort(B.begin(), B.end());
	sort(E.begin(), E.end());

	bool state = B[0].first == B[1].first;
	int sy = B[1].first;
	int sx = B[1].second;

	bool endState = E[0].first == E[1].first;
	int ey = E[1].first;
	int ex = E[1].second;

	bool visit[2][101][101] = {};
	queue<pair<bool, pair<int, int>>> bfs;

	visit[state][sy][sx] = true;
	bfs.push({state, {sy, sx}});

	int ans = 0;
	while(!bfs.empty())
	{
		int size = bfs.size();
		while(size--)
		{
			bool curState = bfs.front().first;
			int y = bfs.front().second.first;
			int x = bfs.front().second.second;
			bfs.pop();

			if(curState == endState && y == ey && x == ex)
			{
				printf("%d", ans);
				return 0;
			}

			bool hasTree = false;
			if(!visit[!curState][y][x])
			{
				for(int d=0; d < 8; d++)
				{
					int ny = y + dy[d];
					int nx = x + dx[d];
					if(ny < 0 || ny >= N || nx < 0 || nx >= N || a[ny][nx] == '1')
					{
						hasTree = true;
						break;
					}
				}

				if(hasTree == false)
				{
					visit[!curState][y][x] = true;
					bfs.push({!curState, {y, x}});
				}
			}

			for(int d=0; d < 4; d++)
			{
				int ny = y + dy[d];
				int nx = x + dx[d];
				if(ny < 0 || ny >= N || nx < 0 || nx >= N || visit[curState][ny][nx] || a[ny][nx] == '1')
					continue;

				bool hasTree = false;
				for(int d2=curState?2: 0; d2 < (curState? 4: 2); d2++)
				{
					int ny2 = ny + dy[d2];
					int nx2 = nx + dx[d2];
					if(ny2 < 0 || ny2 >= N | nx2 < 0 || nx2 >= N || a[ny2][nx2] == '1')
						hasTree = true;
				}
				if(hasTree == true)
					continue;

				visit[curState][ny][nx] = true;
				bfs.push({curState, {ny, nx}});
			}
		}
		ans++;
	}

	printf("0");
	return 0;
}