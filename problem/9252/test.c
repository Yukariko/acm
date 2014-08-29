#define MAX(a,b) (a>b?a:b)
LCS(char *p,char *q)
{
  int i,j;
  int dp[2][1001]={};
  char stk[2][1001][1001]={};
  for(i=1;p[i-1];i++)
  {
    for(j=1;q[j-1];j++)
    {
      if(p[i-1]==q[j-1])
      {
        dp[i&1][j]=dp[i&1^1][j-1]+1;
        strcpy(stk[i&1][j],stk[i&1^1][j-1]);
        stk[i&1][j][dp[i&1^1][j-1]]=p[i-1];
      }
      else
      {
        if(dp[i&1^1][j]>dp[i&1][j-1])
        {
          dp[i&1][j]=dp[i&1^1][j];
          strcpy(stk[i&1][j],stk[i&1^1][j]);
        }
        else
        {
          dp[i&1][j]=dp[i&1][j-1];
          strcpy(stk[i&1][j],stk[i&1][j-1]);
        }
      }
    }
  }
  printf("%d\n",dp[i&1^1][j-1]);
  puts(stk[i&1^1][j-1]);
}
main()
{
  char a[1001];
  char b[1001];
  gets(a);gets(b);
  LCS(a,b);
}
