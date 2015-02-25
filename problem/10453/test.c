main()
{
	int N;
	scanf("%d",&N);
	for(;N--;)
	{
		char a[100001],b[100001];
		scanf(" %s%s",a,b);
		int ret=0;
		for(int i=0,j;a[i];i++)
		{
			for(j=0;a[i]!=b[i+j];j++)ret++;
			for(;j;j--)b[i+j]=b[i+j-1];
		}
		printf("%d\n",ret);
	}
}
