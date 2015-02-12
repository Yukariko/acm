const int d[2][4] = {
	{0,0,1,1},
	{0,1,0,1}
};
main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	int first = ((N-1)/2) % 3;
	for(;K--;)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int mid = N / 2 + N % 2;
		int m = abs(mid-a) > abs(mid-b)? abs(mid-a): abs(mid-b);
		if(N % 2 == 0)
		{
			for(int i=0;i<4;i++)
			{
				int t=abs(mid + d[0][i] -a) > abs(mid + d[1][i] -b)? abs(mid + d[0][i] -a): abs(mid + d[1][i] -b);
				m = m < t? m: t;
			}
		}
		m %= 3;
		int ret= first;
		for(;m--;)
		{
			ret--;
			if(ret < 0) ret = 2;
		}
		printf("%d\n",ret + 1);
	}
}
