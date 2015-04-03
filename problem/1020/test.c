const int C[] = {6,2,5,5,4,5,6,3,7,5};
const long long INF=1LL<<50;

int len;
int N;
char a[16];

long long dp[16][110][2][2];

long long min(long long p,long long q){return p<q?p:q;}

long long solve(int pos, int n, int up, int change)
{
	if(pos < 0) return n == N && change? 0:1;

	long long *ret = &dp[pos][n][up][change];

	if(*ret != -1) return *ret;

	*ret = INF;

	for(int i=0;i<10;i++)
	{
		const int set = (a[pos] + up + i - '0') % 10;
		*ret = min(*ret, i + solve(pos-1, n + C[set], set < (a[pos] + up -'0'), change | !!i) * 10);
	}
	return *ret;
}

main()
{
	len = strlen(gets(a));

	memset(dp,-1,sizeof(dp));

	for(int i=0;a[i];i++)
		N += C[a[i]-'0'];
    
	printf("%lld",solve(len-1,0,0,0));
}