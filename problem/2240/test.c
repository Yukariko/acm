#define MAX(a,b) (a>b?a:b)
int a[1001];
int k;
int dp[1001][31];
f(i,w)
{
  if(i>k)return 0;
  if(dp[i][w])return dp[i][w];
  if(w==0)return dp[i][w]=a[i]+f(i+2,w);
  return dp[i][w]=a[i]+MAX(f(i+1,w-1),f(i+2,w));
}
main()
{
  int t,w;
  scanf("%d%d",&t,&w);
  int i,j,s,sel;
  scanf("%d",&j);
  sel=j;
  s=j;
  k=0;
  a[0]=1;
  for(i=1;i<t;i++)
  {
    scanf("%d",&j);
    if(s==j)
    {
      a[k]++;
    }
    else
    {
      s=j;
      a[++k]=1;
    }
  }
  printf("%d",MAX(sel==1?f(0,w):f(1,w),f(0,w-1)));
}
