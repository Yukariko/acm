#include <stdio.h>
#include <string.h>

int N,M;
int a[301];
short sum[301][301];
char res[301][301];
short dp[301][301];

short max(short p,short q){return p>q?p:q;}
short min(short p,short q){return p>q?q:p;}

short solve(int pos, int count)
{
  if(count == 1) return sum[pos][N-1];
 
  short *ret = &dp[pos][count];
  if(*ret != -1)  return *ret;
  *ret = sum[pos][N-1];
  
  for(int i=pos; i<N; i++)
  {
    const short t = max(sum[pos][i], solve(i+1, count - 1));
    if(t < *ret)
    {
      *ret = t;
      res[pos][count] = i-pos+1;
    }
  }
  return *ret;
}

int main()
{
  memset(dp,-1,sizeof(dp));
  scanf("%d%d",&N,&M);
  
  for(int i=0;i<N;i++)
    scanf("%d",a+i);
  
  for(int i=0;i<N;i++)
  {
    sum[i][i] = a[i];
    for(int j=i+1;j<N;j++)
      sum[i][j] = sum[i][j-1] + a[j];
  }
  
  printf("%d\n",solve(0,M));
  int pos = 0 , count = M;
  for(int i=0;i<M-1;i++)
  {
    printf("%d ",res[pos][count]);
    pos += res[pos][count];
    count--;
  }
  printf("%d",N-pos);
  return 0;
}
