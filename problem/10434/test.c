isPrime(int n)
{
	if(n == 1) return 0;
	for(int i=2;i*i<=n;i++)if(n % i == 0)return 0;
	return 1;
}

main()
{
	int T;
	int dp[10001];
	memset(dp,-1,sizeof(dp));
	for(scanf("%d",&T);T--;)
	{
		int tc,N;
		scanf("%d%d",&tc,&N);
		
		int ret;
		if(isPrime(N))
		{
			char check[10001]={};
			ret = N;
			for(;ret > 1;)
			{
				int t = 0;
				if(check[ret]){ret=0;break;}
				check[ret] = 1;
				if(dp[ret] != -1) t = dp[ret];
				else
				{
					for(int i=ret;i;i/=10)t+=(i%10)*(i%10);
					dp[ret] = t;
				}
				ret = t;
				printf("%d\n",ret);
			}
		}
		else ret=0;
		printf("%d %d %s\n",tc,N,ret?"YES":"NO");
	}
}
