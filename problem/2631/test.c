int a[201];
int dp[201];
int n;
int max;
f(i,s)
{
  int t=a[i];
  if(dp[i]<=s)dp[i]=s;
  else return;
  max=max<s?s:max;
  for(;i<n;i++)
  {
    if(t<a[i])f(i,s+1);
  }
}
main()
{
  scanf("%d",&n);
  int i;
  for(i=0;i<n;i++)
  {
    scanf("%d",a+i);
  }
  for(i=0;i<n;i++)f(i,0);
  printf("%d",n-max-1);
}
