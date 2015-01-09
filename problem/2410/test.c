const int MOD = 1000000000;

int N;
int dp[1000001][21];
f(pos,order)
{
	if(pos == 0 || order == 0)return 1;
	if(pos < 0)return 0;
	if(dp[pos][order] != -1) return dp[pos][order];
	return dp[pos][order]= (f(pos,order-1) + f(pos-(1<<order),order)) % MOD;
}
main()
{
	scanf("%d",&N);
	memset(dp,-1,sizeof(dp));
	printf("%d",f(N,20));
}
