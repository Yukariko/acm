int N,S,M;
int max = -1;
int vol[101];
char visit[101][1001];
f(pos,score)
{
	if(pos == N)
	{
		max = max < score? score: max;
		return;	
	}
	if(visit[pos][score])return;
	visit[pos][score]=1;
	if(score + vol[pos] <= M) f(pos+1,score + vol[pos]);
	if(score - vol[pos] >= 0) f(pos+1,score - vol[pos]);
}
main()
{
	int i;
	scanf("%d%d%d",&N,&S,&M);
	for(i=0;i<N;i++)scanf("%d",vol+i);
	f(0,S);
	printf("%d",max);
}
