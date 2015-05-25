#include <stdio.h>
#include <stdlib.h>

int dp[5001][5001];

int solve(int pos,int left)
{
  if(left < 0)
    return 0;
  if(pos == 0)
    return !left;
    
  int *ret = &dp[pos][left];
  if(*ret != -1) return *ret;
  *ret = 0;
  return *ret = (solve(pos-1,left+1) + solve(pos-1,left-1)) % 1000000007;
}


int main()
{
  memset(dp,-1,sizeof(dp));
  for(int L=1;L<=5000;L++)
    solve(L,0);
  
  int T;
  scanf("%d",&T);
  for(;T--;)
  {
    int L;
    scanf("%d",&L);
    printf("%d\n",dp[L][0]);
  }
  return 0;
}
