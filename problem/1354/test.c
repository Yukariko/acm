int P,Q,X,Y;
long long dp[10000001];
long long f(long long N)
{
  if(N <= 0) return 1;
  if(N < 10000001)
  {
    if(dp[N])return dp[N];
    return dp[N]=f(N/P-X)+f(N/Q-Y);
  }
  return f(N/P-X)+f(N/Q-Y);
}
main()
{
  long long N;
  scanf("%lld%d%d%d%d",&N,&P,&Q,&X,&Y);
  printf("%lld",f(N));
}

