#include <bits/stdc++.h>

using namespace std;

const int dy[][3] = {
	{0,1,1},
	{0,1,1},
	{-1,0,-1},
	{1,0,1}
};
const int dx[][3] = {
	{1,0,1},
	{-1,0,-1},
	{0,1,1},
	{0,-1,-1}
};

int N, M;
char a[1001][1001];
bool b[1001][1001][4];

bool isOK(int y, int x, int d)
{
	return !(y < 0 || y >= N || x < 0 || x >= M || b[y][x][d]);
}

int main()
{

	scanf("%d%d ",&N,&M);
	for(int i=0; i < N; i++)
		gets(a[i]);

	int ans = 0;

	for(int i=0; i < N; i++)
	{
		for(int j=0; j < M; j++)
		{
			if(a[i][j] == '.')
				continue;

			for(int d=0; d < 4; d++)
			{
				if(!isOK(i,j,d))
					continue;

				bool find = true;

				for(int k=0; k < 3; k++)
				{
					int ny = i + dy[d][k];
					int nx = j + dx[d][k];
					if(!isOK(ny, nx, d) || a[ny][nx] != (k%2?'X':'.'))
					{
						find = false;
						break;
					}

				}
				if(find)
				{
					b[i][j][d] = true;
					b[i + dy[d][1]][j + dx[d][1]][d] = true;
					ans++;
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}