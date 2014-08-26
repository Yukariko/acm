int dp[31];
f(n)
{
  if(n<0)return 0;
  if(dp[n])return dp[n];
  return dp[n]=f(n-1)+2*f(n-2);
}
main()
{
  dp[1]=1;
  dp[0]=1;
  int n;
  scanf("%d",&n);
  int s;
  s=f(n/2+!(n%2));
  printf("%d",f(n)-(f(n)-s)/2);
}
