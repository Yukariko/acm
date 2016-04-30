#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};

int main()
{
	int N;
	scanf("%d", &N);

	char a[51][51];
	for(int i=0; i < N; i++)
		scanf("%s", a[i]);

	int sy = -1, sx = -1;
	for(int i=0; i < N; i++)
		for(int j=0; j < N; j++)
			if(sy == -1 && a[i][j] == '#')
				sy = i, sx = j;

	vector<vector<int>> d(4, vector<int>(N*N, INF));
	priority_queue<pair<int, pair<int, int>>> pq;

	for(int i=0; i < 4; i++)
	{
		int y = sy + dy[i];
		int x = sx + dx[i];
		if(y < 0 || y >= N || x < 0 || x >= N || a[y][x] == '*')
			continue;
		a[sy][sx] = '*';
		d[i][y * N + x] = 0;
		pq.push({0, {i, y * N + x}});
		break;
	}

	while(!pq.empty())
	{
		int dist = -pq.top().first;
		int dir = pq.top().second.first;
		int hy = pq.top().second.second / N;
		int hx = pq.top().second.second % N;
		pq.pop();

		if(d[dir][hy * N + hx] < dist)
			continue;

		if(a[hy][hx] == '#')
		{
			printf("%d", dist);
			return 0;
		}

		do
		{
			int ny = hy + dy[dir];
			int nx = hx + dx[dir];
			if(ny < 0 || ny >= N || nx < 0 || nx >= N || a[ny][nx] == '*' || d[dir][ny * N + nx] <= dist)
				continue;
			d[dir][ny * N + nx] = dist;
			pq.push({-dist, {dir, ny * N + nx}});
		} while(0);
		
		if(a[hy][hx] == '!')
		{
			for(int i=0; i < 4; i++)
			{
				if((dir < 2 && i < 2) || (dir >= 2 && i >= 2)) 
					continue;

				int ny = hy + dy[i];
				int nx = hx + dx[i];
				if(ny < 0 || ny >= N || nx < 0 || nx >= N || a[ny][nx] == '*' || d[i][ny * N + nx] <= dist + 1)
					continue;
				d[i][ny * N + nx] = dist + 1;
				pq.push({-dist-1, {i, ny * N + nx}});
			}
		}
	}
	return 0;
}