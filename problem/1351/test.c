int P,Q;
long long dp[10000001];
long long f(long long N)
{
  if(N == 0) return 1;
  if(N < 10000001)
  {
    if(dp[N])return dp[N];
    return dp[N]=f(N/P)+f(N/Q);
  }
  return f(N/P)+f(N/Q);
}
main()
{
  long long N;
  scanf("%lld%d%d",&N,&P,&Q);
  printf("%lld",f(N));
}
