#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int dy[] = {1,1,1,-1,-1,-1,0,0};
const int dx[] = {1,-1,0,1,-1,0,1,-1};

int H, W;
char map[1001][1001];
bool visit[1001][1001];

bool isOK(int y, int x)
{
	return !(y < 0 || y >= H || x < 0 || x >= W || visit[y][x]);
}

struct dotPoint
{
	int y, x;
	dotPoint(int y, int x) : y(y), x(x) {}
};

void check(int y, int x)
{
	for(int d=0; d < 8; d++)
	{
		int Y = y + dy[d];
		int X = x + dx[d];
		if(!isOK(Y,X))
			continue;

		if(map[Y][X] != '.' && map[Y][X] > '0')
			map[Y][X]--;
	}
}

int main()
{
	cin >> H >> W;
	for(int i=0; i < H; i++)
		cin >> map[i];

	for(int i=0; i < H; i++)
		for(int j=0; j < W; j++)
			if(map[i][j] == '.')
				check(i,j);

	queue<dotPoint> q;

	for(int i=0; i < H; i++)
	{
		for(int j=0; j < W; j++)
		{
			if(map[i][j] == '0')
			{
				visit[i][j] = true;
				q.push(dotPoint(i,j));
			}
		}
	}

	int ans = 0;
	while(q.size())
	{

		int len = q.size();
		for(int i=0; i < len; i++)
		{
			dotPoint dot = q.front();
			q.pop();

			map[dot.y][dot.x] = '.';
			check(dot.y,dot.x);

			for(int d=0; d < 8; d++)
			{
				int Y = dot.y + dy[d];
				int X = dot.x + dx[d];
				if(!isOK(Y,X))
					continue;

				if(map[Y][X] == '0')
				{
					visit[Y][X] = true;
					q.push(dotPoint(Y,X));
				}
			}
		}
		ans++;
	}

	cout << ans;
	return 0;
}