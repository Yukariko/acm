int N;
int a[101];

long long dp[101][21];

long long solve(int pos, int val)
{
	if(pos == N-1) return val == a[pos];
	if(val < 0 || val > 20) return 0;
	if(dp[pos][val] != -1) return dp[pos][val];
	return dp[pos][val] = solve(pos+1, val + a[pos]) + solve(pos+1, val - a[pos]);
}

main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d",&a[i]);

	printf("%lld",solve(1,a[0]));
}