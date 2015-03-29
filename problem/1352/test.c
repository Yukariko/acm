int N;
int a[101];
char dp[101][101];

void solve(int depth, int pos, int count)
{
	if(pos == N)
	{
		if(count) return;
		
		char res[101];
		int stok[26]={};
		int rPos=0;
		int order=0;
		for(int i=0;i<depth;i++)
		{
			if(a[i] == 0)
			{
				stok[order] = rPos;
				res[rPos++] = 'A' + order;
				order++;
			}
			else
			{
				for(int j=0;j < order && a[i];j++)
				{
					if(stok[j])
					{
						for(;stok[j] && a[i];stok[j]--,a[i]--)
							res[rPos++] = 'A' + j;
					}
				}
			}
		}
		res[rPos] = 0;
		puts(res);
		exit(1);
	}

	if(dp[pos][count])return;
	dp[pos][count] = 1;

	for(int i=1;i<=count;i++)
	{
		if(pos+i <= N)
		{
			a[depth] = i;
			solve(depth+1,pos+i,count - i);
		}
	}

	if(count + pos <= N)
	{
		a[depth] = 0;
		solve(depth+1,pos+1,count+pos);
	}
}

main()
{
	scanf("%d",&N);
	solve(0,0,0);
	puts("-1");
}