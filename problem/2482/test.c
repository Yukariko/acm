const int MOD = 1000000003;
int N,K;

int sel[1001];
int dp[2][1001][1001];

int isOK(int pos,int zero)
{
	return !(sel[pos==0?N-1:pos-1] || pos==N-1?zero:sel[pos+1]);
}

int solve(int pos,int count, int zero)
{
	if(count == 0)return 1;
	if(pos >= N) return 0;
	if(pos == N-1) return count==1?!zero:0;
	int *ret = &dp[zero][pos][count];
	if(*ret != -1) return *ret;
	
	return *ret = (solve(pos+2,count-1,zero) + solve(pos+1,count,zero)) % MOD;
}

main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%d%d",&N,&K);
	printf("%d",(solve(2,K-1,1)+solve(1,K,0))%MOD);
}
