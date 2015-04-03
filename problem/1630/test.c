const int MOD = 987654321;
char che[1000001];
main()
{
	int prime[80001];
	int pnum=0;

	for(long long i=2;i<=1000000;i++)
	{
		if(che[i] == 0)
		{
			prime[pnum++] = i;
			for(long long j = i*i; j <= 1000000; j += i)
				che[j] = 1;
		}
	}

	prime[pnum] = MOD;

	int N;
	scanf("%d",&N);

	long long ret = 1;
	for(int i=0;prime[i]<=N;i++)
	{
		for(long long j=prime[i];j<=N;j*=prime[i])
		{
			ret *= prime[i];
			ret %= MOD;
		}
	}

	printf("%lld",ret);
}