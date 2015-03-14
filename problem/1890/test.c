int N;
int map[101][101];
long long dp[101][101];
long long solve(int y,int x)
{
	if(y >= N || x >= N) return 0;
	if(y == N-1 && x == N-1) return 1;
	if(map[y][x] == 0) return 0;
	if(dp[y][x]) return dp[y][x];
	return dp[y][x]=solve(y+map[y][x],x) + solve(y,x+map[y][x]);
}

main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%d",&map[i][j]);	
		}	
	}
	printf("%lld",solve(0,0));
}
