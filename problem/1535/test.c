#include <stdio.h>

int N;
int L[21];
int J[21];
int dp[21][101];
int max(int p,int q){return p>q?p:q;}

int solve(int pos, int hp)
{
	if(hp <= 0)
		return -987654321;

	if(pos == N)
		return 0;

	if(dp[pos][hp])
		return dp[pos][hp];

	return dp[pos][hp] = max(J[pos] + solve(pos+1, hp - L[pos]), solve(pos+1, hp));
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d",&L[i]);
	for(int i=0;i<N;i++)
		scanf("%d",&J[i]);
	
	int ret = solve(0, 100);
	if(ret < 0)
		ret = 0;

	printf("%d",ret);
	return 0;
}