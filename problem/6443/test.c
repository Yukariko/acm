int len;
int count[52];
char res[101];

void solve(int depth)
{
	if(depth == len)
	{
		puts(res);
		return;
	}

	for(int i=0;i<52;i++)
	{
		if(count[i])
		{
			count[i]--;

			res[depth] = i&1? 'a' + (i-1)/2 : 'A' + i/2;
			solve(depth+1);
			
			count[i]++;
		}
	}
}

main()
{
	int N;
	scanf("%d ",&N);
	for(;N--;)
	{
		char a[101];
		len = strlen(gets(a));
		memset(count,0,sizeof(count));

		for(int i=0;a[i];i++)
		{
			if(a[i] < 'a')
				count[(a[i]-'A') * 2]++;
			else
				count[(a[i]-'a') * 2 + 1]++;
		}
		solve(0);
	}
}