#include <stdio.h>
#include <string.h>

int N,M;
int a[101][101];
int dp[101][101];
char visit[101];
void solve(int pos)
{
	if(!visit[pos])
		return;
	
	if(dp[pos][0] != -1)
		return;

	dp[pos][0] = 0;
	
	for(int i=1; i <= N; i++)
	{
		if(a[pos][i])
		{
			if(!visit[i])
				dp[pos][i] += a[pos][i];
			else
			{
				solve(i);
				for(int j=1;j<=N;j++)
					if(!visit[j])
						dp[pos][j] += dp[i][j] * a[pos][i];
			}
		}
	}
}

int main()
{
	scanf("%d%d",&N,&M);
	for(int i=1; i<=N; i++)
		dp[i][0] = -1;

	for(int i=0;i<M;i++)
	{
		int X,Y,K;
		scanf("%d%d%d",&X,&Y,&K);
		a[X][Y] = K;
		visit[X] = 1;
	}

	solve(N);

	for(int i=1; i <= N; i++)
		if(!visit[i])
			printf("%d %d\n",i,dp[N][i]);
	return 0;
}