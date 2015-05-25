#include <stdio.h>
#include <stdlib.h>

int N,M;
int v2[201][202];

int sel[4];
int dp[201][201];
int solve(int pos,int count)
{
	if(count == 0)
	{
		char visit[201] = {};
		for(int i=1; i <= 3; i++)
			visit[sel[i]] = 1;
		for(int i=1; i <= 3; i++)
		{
			for(int j=1; j <= v2[sel[i]][0]; j++)
			{
				if(visit[v2[sel[i]][j]])
				{
					return 0;
				}
			}
		}
		return 1;
	}
		
	int *ret = &dp[sel[3]][sel[2]];
	if(*ret != -1) return *ret;
	*ret = 0;
	for(int i=pos; i <= N; i++)
	{
		sel[count] = i;
		*ret += solve(i+1, count-1);
		sel[count] = 0;
	}
	return *ret;
}

int main()
{	
	memset(dp,-1,sizeof(dp));
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v2[x][++v2[x][0]] = y;
		v2[y][++v2[y][0]] = x;
	}
	printf("%d",solve(1,3));
	return 0;
}
