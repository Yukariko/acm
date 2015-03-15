const int INF = 987654321;
int N;
int S[10001];
int A,B;

int dp[10001];

int min(int a, int b){return a>b?b:a;}

int solve(int pos)
{
  if(pos == B) return 0;
  if(abs(pos-B) % S[pos] == 0) return 1;
  
  int *ret = &dp[pos];
  if(*ret != -1) return *ret;
  *ret = INF;
  for(int i=pos; i <= N; i+=S[pos])
  {
    *ret = min(*ret, 1 + solve(i));
  }
  for(int i=pos; i > 0; i-=S[pos])
  {
    *ret = min(*ret, 1 + solve(i));
  }
  return *ret;
}

main()
{
  memset(dp,-1,sizeof(dp));
  scanf("%d",&N);
  for(int i=1;i<=N;i++)scanf("%d",&S[i]);
  scanf("%d%d",&A,&B);
  int ret = solve(A);
  printf("%d",ret == INF? -1: ret);
}