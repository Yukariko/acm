char a[2001];
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
int dp[2001];
f(p)
{
  int i,j=p,t,min=2001;
  if(p==len)return 0;
  for(i=len;i>=j;i--)
  {
    if(isPalin(j,i+1))
    {
      if(dp[i+1])t=dp[i+1];
      else dp[i+1]=t=1+f(i+1);
      min=min>t?t:min;
    }
  }
  return min;
}
main()
{
  len=strlen(gets(a));
  printf("%d",f(0));
}
