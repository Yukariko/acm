int a[101];
int N;
char visit[101];

int start;
int dfs(int pos,int count)
{
	if(visit[pos]) return pos == start? count : 0;
	visit[pos] = -1;
	int ret = dfs(a[pos],count+1);
	if(ret)
		visit[pos] = 1;
	else
		visit[pos] = 0;
	return ret;
}

main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%d",a+i);

	int ret=0;
	for(int i=1;i<=N;i++)
	{
		if(!visit[i])
		{
			start = i;
			ret += dfs(i,0);
		}
	}
	printf("%d\n",ret);

	for(int i=1;i<=N;i++)
		if(visit[i] == 1)
			printf("%d\n",i);
}