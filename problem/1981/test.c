#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
main()
{
  int n;
  int i,j;
  int a[101][101];
  int dp[101][101][2];
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      scanf("%d",&a[i][j]);
    }
  }
  int min,max;
  min=max=a[0][0];
  for(i=0;i<n;i++){min=MIN(min,a[0][i]);max=MAX(max,a[0][i]);dp[0][i][0]=min;dp[0][i][1]=max;}
  min=max=a[0][0];
  for(i=0;i<n;i++){min=MIN(min,a[i][0]);max=MAX(max,a[i][0]);dp[i][0][0]=min;dp[i][0][1]=max;}
  for(i=1;i<n;i++)
  {
    for(j=1;j<n;j++)
    {
      if(MAX(a[i][j],dp[i-1][j][1])-MIN(a[i][j],dp[i-1][j][0])<MAX(a[i][j],dp[i][j-1][1])-MIN(a[i][j],dp[i][j-1][0]))
      {
        dp[i][j][0]=MIN(a[i][j],dp[i-1][j][0]);
        dp[i][j][1]=MAX(a[i][j],dp[i-1][j][1]);
      }
      else
      {
        dp[i][j][0]=MIN(a[i][j],dp[i][j-1][0]);
        dp[i][j][1]=MAX(a[i][j],dp[i][j-1][1]);
      }
    }
  }
  printf("%d",dp[n-1][n-1][1]-dp[n-1][n-1][0]);
}
