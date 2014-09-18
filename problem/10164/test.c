main()
{
  int n,m,k;
  scanf("%d%d%d",&n,&m,&k);
  int dp[16][16]={};
  int i,j;
  for(i=0;i<m;i++)dp[0][i]=1;
  for(i=0;i<n;i++)dp[i][0]=1;
  int x,y;
  if(k)k--;
  else k=n*m-1;
  x=k%m;
  y=k/m;
  for(i=1;i<=y;i++)
  {
    for(j=1;j<=x;j++)
    {
      dp[i][j]=dp[i-1][j]+dp[i][j-1];
    }
  }
  for(i=0;i<m;i++)dp[y][i]=dp[y][x];
  for(i=0;i<n;i++)dp[i][x]=dp[y][x];
  for(i=y+1;i<n;i++)
  {
    for(j=x+1;j<m;j++)
    {
      dp[i][j]=dp[i-1][j]+dp[i][j-1];
    }
  }
  printf("%d",dp[n-1][m-1]);
}
