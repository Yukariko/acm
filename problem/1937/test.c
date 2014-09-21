int map[501][501];
int dp[501][501];
int n;
int m;
isOK(i,j)
{
  return i<0||j<0||i>=n||j>=n?0:1;
}
f(p,q)
{
  int max=0;
  int k;
  if(dp[p][q])return dp[p][q];
  if(isOK(p-1,q)&&map[p-1][q]>map[p][q])
  {
    k=1+f(p-1,q);
    max=max<k?k:max;
  }
  if(isOK(p+1,q)&&map[p+1][q]>map[p][q])
  {
    k=1+f(p+1,q);
    max=max<k?k:max;
  }
  if(isOK(p,q-1)&&map[p][q-1]>map[p][q])
  {
    k=1+f(p,q-1);
    max=max<k?k:max;
  }
  if(isOK(p,q+1)&&map[p][q+1]>map[p][q])
  {
    k=1+f(p,q+1);
    max=max<k?k:max;
  }
  return dp[p][q]=max;
}
main()
{
  scanf("%d",&n);
  int i,j,k;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      scanf("%d",&map[i][j]);
    }
  }
  int max=0;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      k=f(i,j);
      max=max<k?k:max;
    }
  }
  printf("%d",max+1);
}
