cmp(int *a,int *b){return *a-*b;}
main()
{
	int a[1001],b[1001],Index[10001];
	int N,res=0,count=0;
	int i,j,k;
	
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%d",a+i);
		b[i]=a[i];
	}
	qsort(b,N,4,cmp);
	for(i=0;i<N;i++)
	{
		Index[b[i]] = i;
		if(a[i] != b[i]) count++;
	}
	for(;count;)
	{
		
	}
	printf("%d",res);
}
