int N,K;
char a[1001][31];
int start,end;

char v[1001][1001];
char visit[1001];

short temp[1001];
short res[1001];

int minLen = 1001;

short dp[1001][1001];

int min(int p,int q){return p>q?q:p;}

int isHamming(int p,int q)
{
	int count = 0;
	for(int i=0;i<K;i++)
		if(a[p][i] != a[q][i])
		{
			count++;
			if(count == 2) return 0;
		}
	return 1;
}

short solve(int depth, int pos)
{
	if(pos == end)
	{
		if(minLen > depth)
		{
			minLen = depth;
			for(int i=0;i<depth;i++)
				res[i] = temp[i];
		}
		return depth;
	}

	short *ret = &dp[depth][pos];
	if(*ret != -1) return *ret;

	*ret = 1001;
	for(int i=0;i<N;i++)
	{
		if(!visit[i] && v[pos][i])
		{
			temp[depth] = i;
			visit[i] = 1;
			*ret = min(*ret, solve(depth+1,i));
			visit[i] = 0;
		}
	}
	return *ret;
}


main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%d%d ",&N,&K);
	for(int i=0;i<N;i++)
		gets(a[i]);
	scanf("%d%d",&start,&end);
	start--;
	end--;

	for(int i=0;i<N;i++)
	{
		for(int j=i+1;j<N;j++)
		{
			if(isHamming(i,j))
				v[i][j] = v[j][i] = 1;
		}
	}

	visit[start] = 1;
	temp[0] = start;

	if(solve(1,start) == 1001)
		puts("-1");
	else
	{
		for(int i=0;i<minLen;i++)
			printf("%d ",res[i]+1);
	}
}