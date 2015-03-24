int cmp(int *p,int *q){return *p-*q;}
main()
{
	int N,L;
	scanf("%d%d",&N,&L);
	int a[1001];
	for(int i=0;i<N;i++)scanf("%d",a+i);
	qsort(a,N,4,cmp);
	
	int ret=1;
	int curTape=a[0];
	for(int i=1;i<N;i++)
	{
		if(curTape + L - 1 < a[i])
		{
			ret++;
			curTape = a[i];
		}
	}
	printf("%d",ret);
}