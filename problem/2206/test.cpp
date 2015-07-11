#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char map[1001][1001];
int visit[1001][1001][2];

struct point {
	short y,x,dist;
	bool chance;
	point(int y, int x, bool chance, int dist)
	{
		this->y = y;
		this->x = x;
		this->chance = chance;
		this->dist = dist;
	} 
};

const int d[2][4] = {
	{0,0,1,-1},
	{1,-1,0,0}
};

int main()
{
	memset(visit,1,sizeof(visit));

	int N, M;
	cin >> N >> M;
	for(int i=0; i < N; i++)
		cin >> map[i];


	queue<point> q;

	q.push(point(0,0,true,1));

	while(!q.empty())
	{
		point p = q.front();
		q.pop();

		if(p.y == N-1 && p.x == M-1)
		{
			cout << p.dist;
			return 0;
		}

		for(int i=0; i < 4; i++)
		{
			int ny = p.y + d[0][i];
			int nx = p.x + d[1][i];

			if(ny < 0 || ny >= N || nx < 0 || nx >= M || (!p.chance && map[ny][nx]=='1'))
				continue;

			if(visit[ny][nx][p.chance] <= p.dist+1)
				continue;

			visit[ny][nx][p.chance] = p.dist+1;

			if(map[ny][nx] == '1')
				q.push(point(ny,nx,false,p.dist+1));
			else
				q.push(point(ny,nx,p.chance,p.dist+1));
		}
	}
	cout << -1;

	return 0;
}