f(a,b){return b?f(b,a%b):a;}
char dp[1001*1001];
main()
{
  int T;
  int res[1001];
  int i,j,k;
  res[1]=3;
  dp[1002]=1;
  for(i=2;i<=1000;i++)
  {
    k=0;
    for(j=1;j<=i;j++)
    {
      int p,r;
      r = f(i,j);
      p = i/r * 1001 + j/r;
      if(!dp[p]){dp[p]=1;k++;}
    }
    res[i]=res[i-1]+k*2;
  }
  for(scanf("%d",&T);T--;)
  {
	int N;
    scanf("%d",&N);
    printf("%d\n",res[N]);
  }
}
