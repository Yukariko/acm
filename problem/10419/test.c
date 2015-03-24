main()
{
	int T;
	scanf("%d",&T);
	for(;T--;)
	{
		int D;
		scanf("%d",&D);
		int ret;
		for(ret=0;ret+ret*ret<=D;ret++);
		printf("%d\n",ret-1);
	}
}