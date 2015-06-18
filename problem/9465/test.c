#include <stdio.h>

#define MAX(a,b) (a>b?a:b)

int main()
{
	int t;
	int a[2][100001];
	int dp[2][100001];
	
	for(scanf("%d",&t);t--;)
	{
		int n;
		scanf("%d",&n);
	
		for(int j=0;j<2;j++)
			for(int i=0;i<n;i++)
				scanf("%d",&a[j][i]);
		
		dp[0][0]=a[0][0];
		dp[1][0]=a[1][0];
		
		for(int i=1;i<n;i++)
		{
			dp[0][i]=MAX(dp[0][i-1],a[0][i]+dp[1][i-1]);
			dp[1][i]=MAX(dp[1][i-1],a[1][i]+dp[0][i-1]);
		}
		printf("%d\n",MAX(dp[1][n-1],dp[0][n-1]));
	}
	return 0;
}
