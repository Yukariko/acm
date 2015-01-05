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

	for(;count--;)
	{
		int sum = 20000;
		j=k=-1;
		for(i=0;i<N;i++)
		{
			if(a[i] != b[i])
			{
				if(b[i] == a[Index[a[i]]] && a[i] == b[Index[a[i]]])
				{
					sum = a[i] + a[Index[a[i]]];
					j = i;
					k = Index[a[i]];
					count--;
					break;
				}
				else if(sum > a[i] + a[Index[a[i]]])
				{
					sum = a[i] + a[Index[a[i]]];
					j = i;
					k = Index[a[i]];
				}
			}
		}
		int t = a[j];
		a[j] = a[k];
		a[k] = t;
		res += sum;
		printf("%d\n",sum);
	}	
	printf("%d",res);
}
