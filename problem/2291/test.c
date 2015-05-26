#include <stdio.h>

int N,M,K;
int val;
int res[11];
int dp[11][221][221];

int solve(int pos, int count, int next, int cur)
{
	if(pos == N && count == 0)
	{
        val++;
		if(val == K)
		{
			for(int i=0;i<N;i++)
				printf("%d ",res[i]);
			exit(1);
		}
		return 1;
	}
	if(pos == N || count <= 0)
	{
		return 0;
	}
	
	int *ret = &dp[pos][count][next];
	
	if(*ret != -1 && val + *ret < K)
	{
		val += *ret;
		return *ret;
	}
    
	*ret = 0;
	
	for(int i=next; i <= count; i++)
	{
		res[pos] = i;
		*ret += solve(pos+1, count - i, i, cur + *ret);
	}
	return *ret;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%d%d%d",&N,&M,&K);	
	printf("%d",solve(0,M,1,0));
	return 0;	
}

