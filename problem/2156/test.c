#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a>b?b:a)
int n;
int wine[10001];
int dp[10001];
int max;
main()
{
  scanf("%d",&n);
  int i;  
  int sum=0;
  for(i=0;i<n;i++)scanf("%d",&wine[i]);
  dp[0]=wine[0];dp[1]=dp[0]+wine[1];
  max=MAX(dp[0],dp[1]);
  for(i=2;i<n;i++)
  {
    dp[i]=wine[i]+MAX(dp[i-2],dp[i-3]+wine[i-1]);
    dp[i]=MAX(dp[i],dp[i-1]);
    max=MAX(max,dp[i]);
  }
  printf("%d",max);
}

