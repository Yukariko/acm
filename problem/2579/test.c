#define MAX(a,b) (a>b?a:b)
int chain[301];
int n;
int dp[301][2];
f(i,sum,count)
{
  if(i>=n)return;
  if(dp[i][count]<sum)dp[i][count]=sum;
  else return;
  if(count==1)
  {
    f(i+2,sum+chain[i+2],0);
  }
  else
  {
    f(i+1,sum+chain[i+1],count+1);
    f(i+2,sum+chain[i+2],0);
  }
}
main()
{
  scanf("%d",&n);
  int i;
  for(i=0;i<n;scanf("%d",chain+i++));
  f(0,chain[0],0);
  f(1,chain[1],0);
  printf("%d",MAX(dp[n-1][0],dp[n-1][1]));
}

