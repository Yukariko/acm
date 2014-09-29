main()
{
  int n,k;
  int dp[501];
  scanf("%d%d",&n,&k);
  int i,j;
  for(i=0;i<=n;i++)dp[i]=50000;
  dp[0]=0;
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=k;j++)
    {
      if(i-j>=0)dp[i]=dp[i]>(j?j:1)+dp[i-j]?(j?j:1)+dp[i-j]:dp[i];
    }
  }
  printf("%d",dp[n]);
}
