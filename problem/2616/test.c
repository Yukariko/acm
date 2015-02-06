int N,K;
int a[50001],sum[50001];
int dp[3][50001];

int max(int a,int b){return a>b?a:b;}

int solve(int aPos, int dPos)
{
  if(dPos == 3) return 0;
  if(aPos > N-K) return 0;
  int *ret = &dp[dPos][aPos];
  if(*ret != -1) return *ret;
  return *ret = max(solve(aPos+1,dPos) , sum[aPos] + solve(aPos+K,dPos+1));
}

main()
{
  memset(dp,-1,sizeof(dp));
  scanf("%d",&N);
  for(int i=0;i<N;i++)scanf("%d",&a[i]);
  scanf("%d",&K);
  int t=0;
  for(int i=0;i<K;i++)t+=a[i];
  for(int i=K;i<N;i++)
  {
    sum[i-K]=t;
    t+=a[i] - a[i-K];
  }
  sum[N-K] = t;
  
  printf("%d",solve(0,0));
}
