const int INF = 31;
 
int V,D;
int a[32];
int dp[31][32][1001];
 
int solve(int pos, int money, int min)
{

	if(pos == V) return money==D? 0: a[min] > money;

	int *ret = &dp[pos][min][money];

	if(*ret != -1) return *ret;

	*ret = 0;

	int check = 0;
	for(int i=pos;i<V;i++)
	{
		if(a[i] <= money)
		{
			check = 1;
			*ret += solve(i+1, money - a[i], min);
		}
		if(min == INF)
			min = i;
		else
			min = a[min] > a[i]? i: min;
	}
	if(!check) return *ret = solve(V,money,min);
	return *ret;
}

main()
{
	int T;
	a[INF] = 1001;
	for(scanf("%d",&T);T--;)
	{
		memset(dp,-1,sizeof(dp));
		scanf("%d%d",&V,&D);
		for(int i=0;i<V;i++)
			scanf("%d",a+i);
		printf("%d\n",solve(0,D,INF));
	}
}