main()
{
  int sq[100001]={0};
  int dp[100001];
  int n,k;
  scanf("%d",&n);
  for(int i=0;i<=n;i++)dp[i]=987654321;
  k=0;
  for(int i=1;i*i<=n;i++)
  {
    sq[k++]=i*i;
  }
  for(int i=0;i<k;i++)
  {
    dp[sq[i]]=1;
    for(int j=sq[i];j<=n;j++)
    {
      dp[j]=dp[j]>dp[j-sq[i]]+1?dp[j-sq[i]]+1:dp[j];
    }
  }
  printf("%d",dp[n]);
}
