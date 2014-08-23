struct DP{int cha,x,y;}dp[10001];
main()
{
  char che[10001]={0};
  int prime[1230];
  int i,j,k=0,q;
  for(i=2;i<=10000;i++)
  {
    dp[i].cha=10001;
    if(che[i]==0)
    {
      prime[k++]=i;
      for(j=i*i;j<=10000;j+=i)che[j]=1;
    }
  }
  for(i=0;i<k;i++)
  {
    for(j=i;j<k;j++)
    {
      q=prime[i]+prime[j];
      if(q>10000)break;
      if(prime[j]-prime[i]<dp[q].cha)
      {
        dp[q].cha=prime[j]-prime[i];
        dp[q].x=prime[i];
        dp[q].y=prime[j];
      }
      else break;
    }
  }
  int n;
  int t;
  for(scanf("%d",&t);t--;)
  {
    scanf("%d",&n);
    printf("%d %d\n",dp[n].x,dp[n].y);
  }
}
