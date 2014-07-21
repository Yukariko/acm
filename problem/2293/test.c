int a[101];
int dp[10001];
int n,k;
main(i,j,p)
{
  scanf("%d%d",&n,&k);
  for(i=0;i<n;)scanf("%d",&a[i++]);
  dp[0]++;
  for(i=0;i<n;i++)
  {
    for(j=a[i];j<=k;j++)
    {
      dp[j]+=dp[j-a[i]];
    }
  }
  printf("%d",dp[k]);
}
