#include <stdio.h>
#include <string.h>

int N,M;
char a[15][15];

const int score[6][6] = {
	{100,70,40,0,0,0},
	{70,50,30,0,0,0},
	{40,30,20,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0}
};

char visit[12][12];

int dp[12][12][1<<11];

int max(int p, int q){return p>q?p:q;}

int solve(int y, int x)
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

	int *ret = &dp[y][x][check];
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
	scanf("%d ",&N);
	M = N;
	for(int i=0; i < N; i++)
		gets(a[i]);
	printf("%d",solve(0,0));
	return 0;
}