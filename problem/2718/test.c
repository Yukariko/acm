const int next[16][16] = {
  {0,12,9,3,15,-1},
  {8,2,15,-1},
  {1,14,-1},
  {0,12,-1},
  {8,11,-1},
  {10,-1},
  {9,-1},
  {8,-1},
  {1,7,4,-1},
  {0,6,-1},
  {5,-1},
  {4,-1},
  {0,3,-1},
  {2,-1},
  {1,-1},
  {0,-1},
};
int dp[21][16];
int solve(int n, int state)
{
  if(n == -1)return state==15;
  int *ret = &dp[n][state];
  if(*ret != -1) return *ret;
  *ret=0;
  for(int i=0;next[state][i]!=-1;i++)
  {
    *ret += solve(n-1,next[state][i]);
  }  
  return *ret;
}
main()
{
  int T;
  memset(dp,-1,sizeof(dp));
  for(scanf("%d",&T);T--;)
  {
    int N;
    scanf("%d",&N);
    printf("%d\n",solve(N,0));
  }
}
