#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a>b?b:a)
main()
{
  int n,m;
  char map[1001][1001];
  short dp[1001][1001];
  int i,j,s;
  int max;
  for(;scanf("%d%d",&n,&m),n;)
  {
    max=0;
    for(i=0;i<n;i++)for(j=0;j<m;j++){scanf(" %c",&map[i][j]);dp[i][j]=0;}
    for(i=0;i<m;i++)if(map[0][i]=='1'){dp[0][i]=1;max=1;}
    for(i=0;i<n;i++)if(map[i][0]=='1'){dp[i][0]=1;max=1;}
    for(i=1;i<n;i++)
    {
      for(j=1;j<m;j++)
      {
        if(map[i][j]=='1')
        {
          dp[i][j]=1+MIN(MIN(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
          max=MAX(max,dp[i][j]);
        }
      }
    }
    printf("%d\n",max);
  }
}
