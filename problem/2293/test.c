int a[101];
int dp[10001];
int n,k;
main(i,j,p)
{
  scanf("%d%d",&n,&k);
  for(i=0;i<n;)scanf("%d",&a[i++]);
  for(i=0;i<=k;i+=a[0])dp[i]++;
  for(i=1;i<n;i++)
  {
    for(j=a[i];j<=k;j++)
    {
      dp[j]+=dp[j-a[i]];
    }
  }
  printf("%d",dp[k]);
}
