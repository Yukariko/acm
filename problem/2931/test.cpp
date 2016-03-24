#include <bits/stdc++.h>

using namespace std;

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};

const int D = 0;
const int U = 1;
const int R = 2;
const int L = 3;

const char *block = "|-1234+";
bool dir[7][4][4];
int findBlock[127];


void init()
{
	dir[0][U][U] = true;
	dir[0][D][D] = true;
	dir[1][R][R] = true;
	dir[1][L][L] = true;
	dir[2][U][R] = true;
	dir[2][L][D] = true;
	dir[3][D][R] = true;
	dir[3][L][U] = true;
	dir[4][R][U] = true;
	dir[4][D][L] = true;
	dir[5][R][D] = true;
	dir[5][U][L] = true;
	dir[6][U][U] = true;
	dir[6][D][D] = true;
	dir[6][R][R] = true;
	dir[6][L][L] = true;
	for(int i=0; block[i]; i++)
		findBlock[block[i]] = i;
}

int N, M;
char a[25][26];

int nblocks;
int sy, sx;
int ey, ex;

bool solve(int y, int x, int cnt, int direction)
{
	if(y == ey && x == ex)
		return cnt == nblocks+1;

	for(int d=0; d < 4; d++)
	{
		if(a[y][x] != 'M' && !dir[findBlock[a[y][x]]][direction][d])
			continue;
		int ny = y + dy[d];
		int nx = x + dx[d];
		if(ny < 0 || ny >= N || nx < 0 || nx >= M || a[ny][nx] == '.')
			continue;
		
		return solve(ny, nx, cnt+1, d);
	}

	return false;
}


int main()
{
	setbuf(stdout,NULL);
	init();
	scanf("%d%d", &N, &M);
	for(int i=0; i < N; i++)
		scanf("%s", a[i]);

	for(int i=0; i < N; i++)
		for(int j=0; j < M; j++)
			if(a[i][j] == 'M')
				sy = i, sx = j;
			else if(a[i][j] == 'Z')
				ey = i, ex = j;
			else if(a[i][j] != '.')
				nblocks += a[i][j] == '+'? 2: 1;

	for(int i=0; i < N; i++)
		for(int j=0; j < M; j++)
			if(a[i][j] == '.')
				for(int k=0; k < 7; k++)
				{
					a[i][j] = block[k];
					nblocks += a[i][j] == '+'? 2: 1;
					if(solve(sy, sx, 0, 0))
					{
						printf("%d %d %c", i+1, j+1, block[k]);
						return 0;
					}
					nblocks -= a[i][j] == '+'? 2: 1;
					a[i][j] = '.';
					
				}
	return 0;
}