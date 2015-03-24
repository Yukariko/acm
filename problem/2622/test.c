main()
{
	int N;
	scanf("%d",&N);
	int ret=0;
	int max = N/3;
	for(int i=1;i<=max;i++)
	{
		for(int j=i;j<N;j++)
		{
			int k = N-i-j;
			if(k < j) break;
			if(k < i+j)
				ret++;
		}
	}
	printf("%d",ret);
}