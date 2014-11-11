main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int N,D,res=0;
		
		for(scanf("%d%d",&N,&D);N--;)
		{
			int v,f,c;
			scanf("%d%d%d",&v,&f,&c);
			
			if(f >= (double) D / v * c)res++;
		}
		printf("%d\n",res);
	}
}
