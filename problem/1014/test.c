#define MAX(a,b) (a>b?a:b)
char map[11][11];
int dp[11][11];
int mask[11][11];
int n,m;
f(i,j)
{
  if(i<0||i>n-1||j<0||j>m-1)return 0;
  if(dp[i][j])return dp[i][j];
  if(!map[i][j])return dp[i][j];
  map[i][j]=0;
  return dp[i][j]=MAX(MAX(MAX(MAX(f(i-1,j)+1,f(i,j-1)),f(i-1,j-1)),f(i,j+1)),f(i+1,j+1));
}
v(i,j,s)
{
  return dp[i][j]+(s&&mask[i][j]!=6);
}
main()
{
  
  int t;
  for(scanf("%d",&t);t--;)
  {
    scanf("%d%d ",&n,&m);
    int i,j;
    for(i=0;i<n;i++)for(j=0;j<m;j++)dp[i][j]=0;
    for(i=0;i<n;i++)gets(map[i]);
    int s=0;
    for(i=0;i<n;i++)
    {
      for(j=0;j<m;j++)
      {
        int max=0,k=0,t=(map[i][j]=='.');
        if(t)
        {
          max=1;k=6;
          if(i>0&&j>0&&dp[i-1][j-1]&&mask[i-1][j-1]==6)k=2;
          if(i>0&&j<m-1&&dp[i-1][j+1]&&mask[i-1][j+1]==6)k=4;
        }

        if(j>0)
        {
          if(max<v(i,j-1,t)){max=v(i,j-1,t);k=t?6:1;}
          if(max==v(i,j-1,0)){max=v(i,j-1,0);k=1;}
        }
        dp[i][j]=max;
        mask[i][j]=k;
      }
      s+=dp[i][j-1];
    }
    for(i=0;i<n;i++)
    {
      for(j=0;j<m;j++)
      {
        printf("%2d(%d) ",dp[i][j],mask[i][j]);
      }
      puts("");
    }
    printf("%d\n",s);
  }
}
