const int MOD = 1000007;

int N,M,K;
int map[51][51];

int dp[51][51][51][51];

int max(int a,int b){return a>b?a:b;}

int solve(int x,int y,int c, int limit)
{
	
	if(x > N || y > M) return 0;
	
	int *ret = &dp[x][y][c][limit];
	if(*ret != -1) return *ret;
	*ret = 0;
	
	if(map[x][y])
	{
		if(map[x][y] < c || !limit) return 0;
		c = map[x][y];
		limit--;
	}
  const int end = x == N && y == M && !limit;
	return *ret = (end + solve(x+1,y,c,limit) + solve(x,y+1,c,limit)) % MOD;
}

main()
{
	scanf("%d%d%d",&N,&M,&K);
	for(int i=1;i<=K;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		map[x][y]=i;
	}
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<=K;i++)
	{
		printf("%d ",solve(1,1,0,i));
	}
}
