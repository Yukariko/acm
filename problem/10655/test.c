#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int N;
int a[100001][2];
int dp[100001][2];

int dist(int p, int q)
{
	return abs(a[p][0]-a[q][0]) + abs(a[p][1]-a[q][1]);
}

int min(int p,int q){return p>q?q:p;}

int solve(int pos, int chance)
{
	if(pos == N-1)
		return 0;

	int *ret = &dp[pos][chance];
	if(*ret != -1)
		return *ret;

	*ret = dist(pos,pos+1) + solve(pos+1, chance);
	if(chance && pos < N-2)
		*ret = min(*ret,dist(pos,pos+2) + solve(pos+2, 0));

	return *ret;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d%d",&a[i][0],&a[i][1]);
	printf("%d",solve(0,1));
	return 0;
}