#include <bits/stdc++.h>

using namespace std;

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};

char a[12][7];
bool visit[12][7];

int check(int y, int x)
{
	if(visit[y][x])
		return 0;
	visit[y][x] = true;

	int ans = 1;
	for(int d=0; d < 4; d++)
	{
		int ny = y + dy[d];
		int nx = x + dx[d];
		if(ny < 0 || ny >= 12 || nx < 0 || nx >= 6 || a[y][x] != a[ny][nx])
			continue;

		ans += check(ny, nx);
	}
	return ans;
}

void clear(int y, int x)
{
	char t = a[y][x];
	a[y][x] = '.';
	for(int d=0; d < 4; d++)
	{
		int ny = y + dy[d];
		int nx = x + dx[d];
		if(ny < 0 || ny >= 12 || nx < 0 || nx >= 6 || t != a[ny][nx])
			continue;

		clear(ny, nx);
	}
}

bool down()
{
	bool moved = false;
	for(int i=0; i < 6; i++)
	{
		int ground = 11;
		for(int j=11; j >= 0; j--)
		{
			if(a[j][i] != '.')
			{
				if(j < ground)
				{
					moved = true;
					a[ground][i] = a[j][i];
					a[j][i] = '.';
				}
				ground--;
			}
		}
	}
	return moved;
}

int main()
{
	for(int i=0; i < 12; i++)
		scanf("%s", a[i]);

	int ans = 0;
	while(true)
	{
		memset(visit, false, sizeof(visit));

		bool find = false;
		for(int i=0; i < 12; i++)
			for(int j=0; j < 6; j++)
				if(a[i][j] != '.' && check(i, j) >= 4)
					clear(i, j), find = true;
		ans += find;
		if(!down())
			break;

	}

	printf("%d", ans);
	return 0;
}