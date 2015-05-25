#include <stdio.h>
#include <stdlib.h>

int N;
int a[1001];
int dp[1001];

int max(int p,int q){return p>q?p:q;}
int min(int p,int q){return p>q?q:p;}

int solve(int pos)
{
  if(pos == N)
    return 0;
    
  int *ret = &dp[pos];
  if(*ret != -1) return *ret;
  
  *ret = 0;
  *ret = solve(pos+1);
  int l = a[pos], r = a[pos];
  
  for(int i=pos+1;i<N;i++)
  {
    l = min(l,a[i]);
    r = max(r,a[i]);
    
    *ret = max(*ret, r - l + solve(i+1));
  }
  return *ret;
}

int main()
{
  memset(dp,-1,sizeof(dp));
  scanf("%d",&N);
  for(int i=0;i<N;i++)
    scanf("%d",&a[i]);
    
  printf("%d",solve(0));
  return 0;
}
