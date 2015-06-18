#include <stdio.h>
#include <stdlib.h>

int dp[2001][2001];

int solve(int pos,int count)
{
	if(pos >= count)
		return pos==count;
	if(count <= 0)
		return count==0;
	
	int *ret = &dp[pos][count];
	if(*ret != -1)
		return *ret;
	
	return *ret = (solve(pos+1,count) + solve(pos+1,count-pos)) % 100999;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	int T;
	scanf("%d",&T);
	for(;T--;)
	{
		int N;
		scanf("%d",&N);
		printf("%d\n",solve(1,N));
	}
	return 0;	
}
