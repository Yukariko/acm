int a[1000001];
long long stok[32][2];
main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d",a+i);


	int max=0;
	for(int i=0;i<N;i++)
		max = max < a[i]? a[i]: max;

	int mbit=0;
	for(;max;max>>=1)mbit++;

	for(int i=0;i<N;i++)
	{
		int k = a[i];
		for(int j=0;j<mbit;j++)
		{
			stok[j][k & 1]++;
			k>>=1;
		}
	}

	long long ret=0;
	for(int i=0;i<N;i++)
	{
		int k = a[i];
		for(int j=0;j<mbit;j++)
		{
			ret += stok[j][!(k & 1)] << j;
			k>>=1;
		}
	}
	printf("%lld",ret>>1);
}