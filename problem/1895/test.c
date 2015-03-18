int cmp(unsigned char *p, unsigned char *q)
{
	return *p > *q? 1: *p < *q? -1: 0;
}

main()
{
	int R,C,T;
	scanf("%d%d",&R,&C);
	unsigned char map[41][41];
	unsigned char temp[9];
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)
			scanf("%d",&map[i][j]);

	scanf("%d",&T);

	int ret=0;
	for(int i=0;i<R-2;i++)
	{
		for(int j=0;j<C-2;j++)
		{
			for(int p=0;p<3;p++)
			{
				for(int q=0;q<3;q++)
				{
					temp[p*3+q] = map[i+p][j+q];
				}
			}
			qsort(temp,9,1,cmp);
			if(temp[4] >= T)
				ret++;
		}
	}

	printf("%d",ret);
}