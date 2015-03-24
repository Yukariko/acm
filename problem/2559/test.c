main()
{
	int N,K;
	int a[100001];
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)
		scanf("%d",&a[i]);
	
	int sum=0;
	for(int i=0;i<K;i++)
		sum+=a[i];

	int ret=sum;
	for(int i=K;i<N;i++)
	{
		sum+=a[i] - a[i-K];
		ret = ret < sum? sum: ret;
	}
	printf("%d",ret);
}