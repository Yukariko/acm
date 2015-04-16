main()
{
	int R,C;
	char ret[201][201];

	scanf("%d%d ",&R,&C);

	for(int i=0;i<R;i++)
		gets(ret[i]);

	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
			ret[i][j+C] = ret[i][C-j-1];
		ret[i][2*C] = 0;
	}
	for(int i=0;i<R;i++)
		strcpy(ret[i+R],ret[R-i-1]);

	int A,B;

	scanf("%d%d",&A,&B);
	ret[A-1][B-1] = ret[A-1][B-1] == '.'? '#': '.';

	for(int i=0;i<2*R;i++)
		puts(ret[i]);
}