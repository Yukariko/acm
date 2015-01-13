int R,C;
char mem[301][301];

int find(int y,int x,int size)
{
	if(y + size > R || x + size > C) return 0;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(mem[y+i][x+j] != mem[y + size - i - 1][x + size - j - 1])
				return 0;
		}
	}
	return 1;
}

main()
{
	scanf("%d%d ",&R,&C);
	for(int i=0;i<R;i++)
	{
		gets(mem[i]);
	}
	int res=1;
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
            for(int k=res+1;k<300;k++)
            {
                if(find(i,j,k))res = k;
            }
		}
	}
	
	printf("%d",res == 1? -1: res);
}
