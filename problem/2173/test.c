#include <stdio.h>
#include <string.h>

int N,M;
int map[31][31];
char visit[31][31];
const int INF = -987654321;

int getPoint(int y,int x, int p,int q)
{
	int ret = 0;
	for(int i=1; i < p; i++)
	{
		if(visit[y+i][x] || visit[y+i][x+q])
			return INF;
		ret += map[y+i][x];
		ret += map[y+i][x+q];
	}
	for(int i=1; i < q; i++)
	{
		if(visit[y][x+i] || visit[y+p][x+i])
			return INF;
		ret += map[y][x+i];
		ret += map[y+p][x+i];
	}
    if(visit[y][x] || visit[y+p][x] || visit[y][x+q] || visit[y+p][x+q])
        return INF;
	ret += map[y][x];
	ret += map[y+p][x];
	ret += map[y][x+q];
	ret += map[y+p][x+q];
	return ret;
}

void set(int sy,int sx,int ey, int ex)
{
	for(int i=sy; i <= ey; i++)
	{
		visit[i][sx] = 1;
		visit[i][ex] = 1;
	}
	for(int i=sx; i <= ex; i++)
	{
		visit[sy][i] = 1;
		visit[ey][i] = 1;
	}
}

int main()
{
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			scanf("%d",&map[i][j]);

	int res[31][6];
	for(int tc=0;tc < M;tc++)
	{
		int ret = INF;
		int sx,sy,ex,ey;
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
				for(int p=2; i+p <= N; p++)
					for(int q=2; j+q <= N; q++)
					{
						int t = getPoint(i,j,p,q);
						if(ret < t)
						{
							ret = t;
							sy = i;
							sx = j;
							ey = i+p;
							ex = j+q;
						}
					}
		if(ret == INF)
			return puts("0"),0;
		res[tc][0] = ret;
		res[tc][1] = sy;
		res[tc][2] = sx;
		res[tc][3] = ey;
		res[tc][4] = ex;
		set(sy,sx,ey,ex);
	}
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<5;j++)
			printf("%d ",res[i][j]);
		puts("");
	}
	return 0;
}