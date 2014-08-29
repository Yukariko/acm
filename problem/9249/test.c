#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a>b?b:a)
char stack[200001];
LCS(char *p,char *q)
{
  int i,j,max=0,k;
  int dp[2][200002]={};
  for(i=1;p[i];i++)
  {
    for(j=1;q[j];j++)
    {
      if(p[i]==q[j])
      {
        dp[i&1][j]=dp[i&1^1][j-1]+1;
      }
      else
      {
        dp[i&1][j]=0;
      }
      if(max<dp[i&1][j])
      {
        max=dp[i&1][j];
      }
    }
  }
  printf("%d\n",max);

}
main()
{
  char a[200002],b[200002];
  int i,j;
  gets(a+1);gets(b+1);
  LCS(a,b);
}
