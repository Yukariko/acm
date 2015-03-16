int N,K;
char a[8];

int dp[11][1000001];

#define SWAP(p,q) {\
	char c = a[p];\
	a[p] = a[q];\
	a[q] = c;\
}

int max(int a,int b){return a>b?a:b;}

int solve(int count, int num)
{
	if(count == 0) return num;
	if(dp[count][num] != -1) return dp[count][num];
	
	int *ret=&dp[count][num];
	*ret = 0;
	for(int i=0;a[i];i++)
	{
		for(int j=i+1;a[j];j++)
		{
			if(i==0 && a[j] == '0') continue;
			SWAP(i,j);
			*ret = max(*ret,solve(count-1, atoi(a)));
			SWAP(i,j);
		}
	}
	return *ret==0?-1:*ret;
}

main()
{
	scanf("%s%d",a,&K);
	memset(dp,-1,sizeof(dp));
	printf("%d",solve(K,atoi(a)));
}