#include <stdio.h>
#include <string.h>

int N;
int dp[1001][3][4];
char a[1001];

int solve(int pos, int late, int absent)
{
	if(late == 2 || absent == 3)
		return 0;
	if(pos == N)
	{
		return 1;	
	}
	
	int *ret = &dp[pos][late][absent];
	
	if(*ret != -1) return *ret;
	
	*ret = 0;	
	*ret += solve(pos+1,late,0);
	*ret += solve(pos+1,late+1,0);
	*ret += solve(pos+1,late,absent+1);
	
	return *ret % 1000000;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%d",&N);
	printf("%d",solve(0,0,0));
	return 0;	
}
