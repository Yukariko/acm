int N,K;
int sel[101];
int dp[101][4][3];

int solve(int pos, int choose, int count)
{
	if(count == 3) return 0;
	if(pos == N) return 1;
	if(sel[pos]) return solve(pos+1,sel[pos],choose == sel[pos]? count+1: 1);

	int *ret = &dp[pos][choose][count];
	if(*ret != -1) return *ret;

	*ret = 0;
	for(int i=1;i<=3;i++)
	{
		*ret += solve(pos+1,i,i==choose?count+1:1);
		*ret %= 10000;
	}
	return *ret;
}

main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%d%d",&N,&K);
	for(int i=0;i<K;i++)
	{
		int day,eat;
		scanf("%d%d",&day,&eat);
		sel[day-1] = eat;
	}
	printf("%d",solve(0,0,0));
}