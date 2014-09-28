#define MIN(a,b) (a>b?b:a)
int dp[1000001];
main()
{
  int n;
  int a[710];
  int i,j=1,k=5;
  a[0]=1;
  for(i=1;i<707;i++)
  {
    a[i]=j+k;
    j+=k;
    k+=4;
  }
  scanf("%d",&n);
  for(i=1;i<=n;i++)dp[i]=6;
  for(i=0;a[i]<=n&&i<707;i++)
  {
    for(j=a[i];j<=n;j++)
    {
      dp[j]=MIN(dp[j],dp[j-a[i]]+1);
    }
  }
  printf("%d",dp[n]);
}
