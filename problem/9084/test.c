int a[21];
int T,n,k;
main(i,j,p)
{
  for(scanf("%d",&T);T--;)
  {
    int dp[10001]={1};
    scanf("%d",&n);
    for(i=0;i<n;scanf("%d",a+i++));
    scanf("%d",&k);
    for(i=0;i<n;i++)
    {
      for(j=a[i];j<=k;j++)
      {
        dp[j]+=dp[j-a[i]];
      }
    }
    printf("%d\n",dp[k]);
  }
}
