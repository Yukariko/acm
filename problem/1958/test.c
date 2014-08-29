#define MAX(a,b) (a>b?a:b)
int dp[101][101][101]={};
LCS(char *p,char *q,char *r)
{
  int i,j,k;
  
  for(i=1;p[i-1];i++)
  {
    for(j=1;q[j-1];j++)
    {
      for(k=1;r[k-1];k++)
      {
        if(p[i-1]==q[j-1]&&p[i-1]==r[k-1])
        {
          dp[i][j][k]=dp[i-1][j-1][k-1]+1;
        }
        else
        {
          dp[i][j][k]=MAX(MAX(dp[i-1][j][k],dp[i][j-1][k]),dp[i][j][k-1]);
        }
      }
    }
  }
  return dp[i-1][j-1][k-1];
}
main()
{
  char a[101],b[101],c[101];
  gets(a);gets(b);gets(c);
  printf("%d",LCS(a,b,c));
}
