#define LIMIT 2500000
int a[4001][4];
int sum[4000*4000+1];
int k;
int check[2 * LIMIT + 1];
int cmp(int *p,int *q){return *p>*q?1:*p<*q?-1:0;}

main()
{
	memset(check,-1,sizeof(check));
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
	
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			sum[k++] = a[i][0] + a[j][1];

	qsort(sum,k,4,cmp);

	int ret = 0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			const int num = -a[i][2]-a[j][3];
			if(num < 0 && num > -LIMIT && check[num + LIMIT] != -1)
			{
				ret += check[num + LIMIT];
				continue;
			}
			else if(num >= 0 && num < LIMIT && check[num + LIMIT] != -1)
			{
				ret += check[num + LIMIT];
				continue;
			}
			int start = 0, end = k-1;
			int res = 0;
			while(start <= end)
			{
				int mid = (start + end)/2;
				if(sum[mid] >= num) end = mid - 1;
				else start = mid + 1;
			}
			for(int p=start;p<k && sum[p] == num; ++p)
				res++;
			
			if(num < 0 && num > -LIMIT)
				check[num + LIMIT] = res;
			else if(num >= 0 && num < LIMIT)
				check[num + LIMIT] = res;
			ret += res;
		}
	}
	printf("%d",ret);
}