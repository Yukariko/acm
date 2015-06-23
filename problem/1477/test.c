#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *p,const void *q)
{
	return *(int *)p-*(int *)q;
}

int min(int p,int q){return p>q?q:p;}
int max(int p,int q){return p>q?p:q;}

int N,M,L;
int a[103];

const int INF = 987654321;

short dp[103][101];

int solve(int pos, int cnt)
{
	if(pos == N-1)
		return cnt? INF : 0;

	short *ret = &dp[pos][cnt];
	if(*ret != -1)
		return *ret;
	*ret = INF;
	for(int i=1; i <= cnt+1; i++)
	{
		int diff = a[pos+1]-a[pos];
		if(diff >= i)
			*ret = min(*ret, max((diff+i-1)/i, solve(pos+1,cnt-i+1)));
	}
	return *ret;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%d%d%d",&N,&M,&L);
	
	a[0] = 0;
	for(int i=1;i<=N;i++)
		scanf("%d",&a[i]);
	a[N+1] = L;
	N+=2;
	
	qsort(a,N,4,cmp);

	printf("%d",solve(0,M));
	return 0;
}