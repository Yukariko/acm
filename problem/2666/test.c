#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int N,M;
int a[21];
int dp[21][21][21];

int min(int p,int q){return p>q?q:p;}

int solve(int pos, int p, int q)
{
	if(pos == M)
		return 0;

	if(dp[pos][p][q] != -1)
		return dp[pos][p][q];

	return dp[pos][p][q] = min(abs(a[pos] - p) + solve(pos+1,a[pos],q), abs(a[pos] - q) + solve(pos+1,p,a[pos]));
}

int main()
{
	memset(dp,-1,sizeof(dp));

	int P,Q;
	scanf("%d%d%d%d",&N,&P,&Q,&M);

	for(int i=0;i<M;i++)
		scanf("%d",&a[i]);

	printf("%d",solve(0,P,Q));
	return 0;
}