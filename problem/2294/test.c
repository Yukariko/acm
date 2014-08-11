main()
{
  int n,p;
  int i,j,k;
  int price[101],dp[10001];
  scanf("%d%d",&n,&p);
  for(i=0;i<n;scanf("%d",price+i++));
  for(i=0;i<=p;dp[i++]=10001);
  for(i=0;i<n;i++)
  {
    if(price[i]<=p)dp[price[i]]=1;
    for(k=0;k<=p;k++)
    {
      int t=k+price[i];
      if(t<=p&&dp[k]+1<dp[t])
        dp[t]=dp[k]+1;
    }
  }
  printf("%d",dp[p]==10001?-1:dp[p]);
}
