MIN(a,b){return a>b?b:a;}
getPoint(x,p)
{
  if(x==p)return 1;
  if(x==0)return 2;
  if(p==1||p==3)
  {
    if(x==2||x==4)return 3;
    return 4;
  }
  if(p==2||p==4)
  {
    if(x==1||x==3)return 3;
    return 4;
  }
}
main()
{
  int dp[2][5][5];
  int n;
  int i,j;
  for(i=0;i<5;i++)
  {
    for(j=0;j<5;j++)
    {
      dp[0][i][j]=dp[1][i][j]=400000;
    }
  }
  dp[0][0][0]=0;
  int t=0;
  for(;scanf("%d",&n),n;)
  {
    for(i=0;i<5;i++)
    {
      for(j=0;j<5;j++)
      {
        if(n!=j)
        {
          dp[!t][n][j]=MIN(dp[!t][n][j],dp[t][i][j]+getPoint(i,n));
        }
        if(i!=n)
        {
          dp[!t][i][n]=MIN(dp[!t][i][n],dp[t][i][j]+getPoint(j,n));
        }
        dp[t][i][j]=400000;
      }
    }
    t=!t;
  }  
  int min=400000;
  for(i=0;i<5;i++)
  {
    for(j=0;j<5;j++)
    {
      min=MIN(min,dp[t][i][j]);
    }
  }
  printf("%d",min);
}
