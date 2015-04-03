const int C[] = {6,2,5,5,4,5,6,3,7,6};
const long long INF = 1LL<<50;

char res[102];
long long dp[101];

long long min(long long p,long long q){return p>q?q:p;}

long long minSolve(int n)
{
	if(n < 0) return INF;
	if(n == 0) return 0;

	long long *ret = &dp[n];
	if(*ret != INF) return *ret;

	for(int i=9;i>=0;i--)
		*ret = min(*ret, i + minSolve(n-C[i]) * 10);

	return *ret = *ret?*ret:6;
}

char *maxSolve(int n)
{
	int i;
	for(i=100;n;i--)
	{
		if(n == 3)
		{
			res[i] = '7';
			n-=3;
		}
		else
		{
			res[i] = '1';
			n-=2;
		}
	}
	return res+i+1;
}

main()
{
	for(int i=0;i<=100;i++)
		dp[i]=INF;

	int T;
	scanf("%d",&T);
	for(;T--;)
	{
		int N;
		scanf("%d",&N);
		printf("%lld %s\n",minSolve(N),maxSolve(N));
	}
}