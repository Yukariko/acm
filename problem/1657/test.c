#include <stdio.h>

int N,M;
char a[15][15];

const int score[6][6] = {
	{10,8,7,5,0,1},
	{8,6,4,3,0,1},
	{7,4,3,2,0,1},
	{5,3,2,2,0,1},
	{0,0,0,0,0,0},
	{1,1,1,1,0,0}
};

char visit[15][15];

short dp[15][15][16385];

int max(int p, int q){return p>q?p:q;}

short solve(int y, int x)
{
	if(y == N)
		return 0;
	if(x == M)
		return solve(y+1,0);
	if(visit[y][x])
		return solve(y,x+1);

	int check = 0;
	for(int i=x+1; i < M; i++)
	{
		check <<= 1;
		check += visit[y][i];
	}
	for(int i=0; i < x; i++)
	{
		check <<= 1;
		check += visit[y+1][i];
	}

	short *ret = &dp[y][x][check];
	if(*ret != -1)
		return *ret;

	*ret = 0;
	visit[y][x] = 1;

	if(x < M-1 && !visit[y][x+1])
	{
		visit[y][x+1] = 1;
		*ret = max(*ret, score[a[y][x]-'A'][a[y][x+1]-'A'] + solve(y,x+2));
		visit[y][x+1] = 0;
	}

	if(y < N-1)
	{
		visit[y+1][x] = 1;
		*ret = max(*ret, score[a[y][x]-'A'][a[y+1][x]-'A'] + solve(y,x+1));
		visit[y+1][x] = 0;
	}

	visit[y][x] = 0;
	*ret = max(*ret, solve(y,x+1));

	return *ret;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%d%d ",&N,&M);
	for(int i=0; i < N; i++)
		gets(a[i]);
	printf("%d",solve(0,0));
	return 0;
}