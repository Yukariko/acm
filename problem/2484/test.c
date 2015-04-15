int cmp(int *p,int *q){return *p>*q?1:*p<*q?-1:0;}
main()
{
	int N;
	int ret=0;

	scanf("%d",&N);
	
	for(int i=0;i<N;i++)
	{
		int dice[4];
		for(int j=0;j<4;j++)
			scanf("%d",&dice[j]);

		qsort(dice,4,4,cmp);

		int res[5] = {0, };
		int count=1;

		for(int j=1;j<4;j++)
		{
			if(dice[j] == dice[j-1])
			{
				count++;
				res[count] *= 10;
				res[count] += dice[j];
			}
			else
				count = 1;
		}

		int prize;

		if(res[4])
			prize = 50000 + dice[0] * 5000;
		else if(res[3])
			prize = 10000 + dice[1] * 1000;
		else if(res[2] > 10)
			prize = 2000 + dice[1] * 500 + dice[2] * 500;
		else if(res[2])
			prize = 1000 + res[2] * 100;
		else
			prize = dice[3] * 100;

		ret = ret < prize? prize: ret;
	}

	printf("%d",ret);
}