int m[101],c[101];
int N,M;

main()
{
  int i,j,t;
  int dp[10001]={0};
  scanf("%d%d",&N,&M);
  for(i=0;i<N;scanf("%d",m+i++));
  for(i=0;i<N;scanf("%d",c+i++));
  for(t=i=0;i<N;i++)t+=c[i];
  for(i=0;i<N;i++)
  {
    for(j=t;j>=c[i];j--)
    {
      if(dp[j]<dp[j-c[i]]+m[i])
      {
        dp[j]=dp[j-c[i]]+m[i];
      }
    }
  }
  for(i=0;i<=t;i++)
  {
    if(dp[i] >= M)break;
  }
  printf("%d",i);
}
