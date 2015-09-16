#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

const int dy[] = {0,0,0,1,-1,1,-1,1,-1};
const int dx[] = {0,1,-1,0,0,1,1,-1,-1};

char map[11][12];

bool isput(int y, int x, int n)
{
	if(x + n >= 10)
		return false;
	for(int i=0; i < n; i++)
	{
		bool find = false;
		for(int d=0; d < 9; d++)
		{
			int ny = y + dy[d];
			int nx = x + i + dx[d];
			if(ny < 0 || ny >= 10 || nx < 0 || nx >= 10)
				continue;
			find = true;
			if(map[ny][nx] != '.')
				return false;
		}
		if(!find)
			return false;
	}

	for(int i=0; i < n; i++)
		map[y][x+i] = '#';

	return true;
}

int main()
{
	int a[11][11];
	int lastY = -1;
	int lastX = -1;
	for(int i=0; i < 10; i++)
	{
		for(int j=0; j < 10; j++)
		{
			cin >> a[i][j];
			if(a[i][j] == 100)
			{
				lastY = i;
				lastX = j;
			}
		}
	}

	for(int i=0; i < 10; i++)
		memset(map[i], '.', 10);

	map[lastY][lastX] = '#';

	int four = 1;
	int three = 2;
	int two = 3;
	int one = 3;

	for(int i=0; i < 10; i++)
	{
		for(int j=0; j < 10; j++)
		{
			if(four && isput(i, j, 4))
				four--;
			else if(three && isput(i, j, 3))
				three--;
			else if(two && isput(i, j, 2))
				two--;
			else if(one && isput(i, j, 1))
				one--;
		}
	}


	for(int i=0; i < 10; i++)
		cout << map[i] << '\n';
	return 0;
}