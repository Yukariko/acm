int N,M,K;
char res[201];
int stok;
int len;
int dp[201][101];

int solve(int pos, int n)
{
	if(!n)
	{
		stok++;
		if(stok == K)
		{
			puts(res);
			exit(1);
		}
		return 1;
	}

	if(pos + n == len)
	{
		for(int i=0;i<n;i++)
			res[pos+i] = 'a';
		int ret = solve(pos,0);
		for(int i=0;i<n;i++)
			res[pos+i] = 'z';
		return ret;
	}

	int *ret=&dp[pos][n];

	if(*ret && stok + *ret < K)
	{
		stok += *ret;
		return *ret;
	}
	res[pos] = 'a';
	*ret = solve(pos+1,n-1);
	res[pos] = 'z';
	*ret += solve(pos+1,n);

	return *ret;
}

main()
{
	scanf("%d%d%d",&N,&M,&K);
	memset(res,'z',N+M);
	len = N + M;
	solve(0,N);
	puts("-1");
}