#define MAX(a,b) (a>b?a:b)
int a[1001][2];
int k;
int dp[1001][2][31];
f(i,s,w)
{
  if(i>k)return 0;
  if(dp[i][s][w])return dp[i][s][w];
  if(w==0)return dp[i][s][w]=a[i][1]+f(i+2,s,w);
  return dp[i][s][w]=a[i][1]+MAX(f(i+1,a[i+1][0],w-1),f(i+2,s,w));
}
main()
{
  int t,w;

  scanf("%d%d",&t,&w);
  int i,j,s;
  scanf("%d",&j);
  s=j;
  k=0;
  a[0][0]=j;
  a[0][1]=1;
  for(i=1;i<t;i++)
  {
    scanf("%d",&j);
    if(s==j)
    {
      a[k][1]++;
    }
    else
    {
      s=j;
      a[++k][0]=j;
      a[k][1]=1;
    }
  }
  printf("%d",MAX(a[0][0]==1?f(0,1,w):f(1,1,w),f(0,2,w-1)));
}
