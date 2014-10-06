main()
{
  int sq[182];
  int dp[32769][5]={};
  int i,j,k=0;
  for(i=1;i*i<=32768;i++)sq[i-1]=i*i;
  dp[0][0]=1;
  for(j=0;j<181;j++)
  {
    for(k=sq[j];k<=32768;k++)
    {
      for(i=1;i<=4;i++)
      {
        dp[k][i]+=dp[k-sq[j]][i-1];
      }
    }
  }
  
  int n;
  for(;scanf("%d",&n),n;)
  {
    printf("%d\n",dp[n][1]+dp[n][2]+dp[n][3]+dp[n][4]);
  }
}
