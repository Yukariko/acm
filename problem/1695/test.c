#define MIN(a,b) (a>b?b:a)
int a[5001];
short dp[5001][5001];
f(i,j)
{
  if(i>=j)return 0;
  if(dp[i][j])return dp[i][j];
  if(a[i]==a[j])return f(i+1,j-1);
  return dp[i][j]=1+MIN(f(i+1,j),f(i,j-1));
}
main()
{
  int n;
  int i;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%d",a+i);
  }
  printf("%d",f(0,n-1));
}
