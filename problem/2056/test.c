int N;
short task[10001][101];
short doTime[10001];
int dp[10001];

int max(int a,int b){return a>b?a:b;}

int back(int pos)
{
	int *ret = &dp[pos];
	if(*ret) return *ret;
	*ret = doTime[pos];
	for(int i=1;i<=task[pos][0];i++)
	{	
		*ret = max(*ret, doTime[pos] + back(task[pos][i]));
	}
	return *ret;
}

int solve()
{
	int ret = 0;
	for(int i=1;i<=N;i++)
		ret = max(ret, back(i));
	return ret;
}

main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		scanf("%d%d",&doTime[i],&task[i][0]);
		for(int j=1;j<=task[i][0];j++)scanf("%d",&task[i][j]);
	}
	printf("%d",solve());
}
