#include <stdio.h>
#include <stdlib.h>

int min(int p,int q){return p>q?q:p;}

int w[1001][1001];
int v[1001][1001];
int dp[1001];

char visit[1001];

int src, dst;
int solve(int pos)
{
	if(pos == dst)
		return 0;
	
	int *ret = &dp[pos];
	if(*ret != -1)
		return *ret;
	*ret = 97654321;
	for(int i=1; i <= v[pos][0]; i++)
	{
		*ret = min(*ret, w[pos][v[pos][i]] + solve(v[pos][i]));
	}
	
	visit[pos] = 0;
	return *ret;
}


int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=1; i < N; i++)
	{
		int start,end,weight;
		scanf("%d%d%d",&start,&end,&weight);
		v[start][++v[start][0]] = end;
		v[end][++v[end][0]] = start;
		w[start][end] = w[end][start] = weight;
	}
	
	for(int i=0; i < M; i++)
	{
		memset(dp,-1,sizeof(dp));
		scanf("%d%d",&src,&dst);
		printf("%d\n",solve(src));
	}
	return 0;
}