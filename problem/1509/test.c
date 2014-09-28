#define MIN(a,b) (a>b?b:a)
char a[2501];
int len;
isPalin(p,q)
{
  int l=q-p;
  int i,j;
  if(l%2==0)
  {
    i=p+l/2-1;
    j=p+l/2;
    for(;i>=p&&j<q;i--,j++)if(a[i]!=a[j])return 0;
  }
  else
  {
    i=p+l/2;
    j=i;
    for(;i>=p&&j<q;i--,j++)if(a[i]!=a[j])return 0;    
  }
  return 1;
}
int dp[2501];
main()
{
  len=strlen(gets(a));
  int i,j,k;
  for(i=1;i<=len;i++)
  {
    for(j=0;j<i;j++)
    {
      if(isPalin(j,i))
      {
        if(dp[i])dp[i]=MIN(dp[j]+1,dp[i]);
        else dp[i]=dp[j]+1;
      }
    }
  }
  printf("%d",dp[len]);
}
