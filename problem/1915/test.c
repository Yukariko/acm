#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a>b?b:a)
char map[1001][1001];
int dp[1001][1001];
int max;
main()
{
  int n,m;
  
  scanf("%d%d ",&n,&m);
  int i,j,s;
  for(i=0;i<n;i++)gets(map[i]);
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
  printf("%d",max*max);
}
