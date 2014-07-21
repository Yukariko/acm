int a[101],b[2];
int dp[10001];
int n,k;
f(i,j)
{
  int p,q;
  if(i==k)b[0]++;
  if(i<k)
  {
    for(;j<n;j++)
    {
      for(p=a[j];i+p<=k;p+=a[j])
      {
        dp[i+p]++;
        f(i+p,j+1);
      }
    }
  }
}
main(i,j)
{
  scanf("%d%d",&n,&k);
  for(i=0;i<n;)scanf("%d",&a[i++]);
  f(0,0);
  printf("%d %d",b[0],dp[k]);
}
