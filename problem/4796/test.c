main()
{
	int L,P,V;
	int T;
	for(T=1;scanf("%d%d%d",&L,&P,&V),L;T++)
	{
		int ret=0;
		for(;V > 0;V-=P)
			ret += L < V? L: V;
		printf("Case %d: %d\n",T,ret);
	}		
}
