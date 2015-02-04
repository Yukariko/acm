main()
{
	int N;
	scanf("%d ",&N);
	char a[101];
	gets(a);
	
	int ret=0;
	int man=0,woman=0;
	for(int i=0;a[i];i++)
	{
		if(a[i+1] && a[i]!=a[i+1])
		{
			if(man > woman && a[i] == 'M')
			{
				a[i]^=a[i+1]^=a[i]^=a[i+1];
			}
			else if(man < woman && a[i] == 'W')
			{
				a[i]^=a[i+1]^=a[i]^=a[i+1];
			}
		}
		if(a[i] == 'M') man++;
		else woman++;
		if(abs(man-woman) > N) break;
		ret++;
	}
	printf("%d",ret);
}
