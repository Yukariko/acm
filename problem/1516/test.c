int build[501][501];
int time[501];
int dp[501];
int n;
f(p)
{
  int i,j,sum,max=0;
  if(dp[p])return dp[p];
  for(i=1;i<=n;i++)
  {
    if(build[p][i])
    {
      sum=f(i);
      max=max<sum?sum:max;
    }
  }
  return dp[p]=max+time[p];
}
main()
{
  scanf("%d",&n);
  int i,j,k;
  for(i=1;i<=n;i++)
  {
    scanf("%d",&time[i]);
    for(;scanf("%d",&j),j!=-1;)build[i][j]=1;
  }
  for(i=1;i<=n;i++)
  {
    printf("%d\n",f(i));
  }
}
