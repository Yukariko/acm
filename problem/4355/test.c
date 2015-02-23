int factor[101];
int fp;
int N;
int isPrime(int n)
{
	for(int i=2;i*i<=n;i++)if(n%i==0)return 0;
	return 1;
}
int solve(int pos,int depth, int num)
{
	if(depth == 0)return (N-1) / num;
	int ret=0;
	for(int i=pos; i<fp; i++)
	{
		ret += solve(i+1, depth-1, num*factor[i]);
	}
	return ret;
}

main()
{
	for(;scanf("%d",&N),N;)
	{
		if(N == 1){puts("1");continue;}
		int ret = N-1, T = N;
		fp=0;
		for(int i=2;i*i <= T;i++)
		{
			if(isPrime(i) && T % i == 0)
			{
				factor[fp++] = i;
				while(T%i==0)T/=i;
			}
		}
		if(T>1)factor[fp++] = T;
		for(int i=1;i<=fp;i++)
		{
			ret += (i%2?-1:1) * solve(0,i,1);
		}
		printf("%d\n",ret);
	}
}
