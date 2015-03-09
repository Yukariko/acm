int N,K;

int dp[201][40001];

int solve(int count,int sum)
{
	if(count == 0) return sum == N;
	
	
	int *ret = &dp[count][sum];
	
	if(*ret != -1) return *ret;
	
	*ret = 0;
	
	for(int i=0;i<=N;i++)
	{
		if(sum+i <= N)
		{
			*ret = (*ret + solve(count-1,sum+i)) % 1000000000;
		}
	}
	
	return *ret;	
}

main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%d%d",&N,&K);
	printf("%d",solve(K,0));
}
