int N;
int dp[1000][1000];
char che[1000001];
max(p,q)
{
  return p>q?p:q;
}
f(p,q)
{
  if(p > N || q > N) return 0; 
  if (dp[p][q]) return dp[p][q];
  int t = q >= 100? p*1000+q : q >= 10? p *100 + q : p*10 + q;
  return dp[p][q] = (t != 11 && che[t] == 0) + max(f(p+1,q),f(p,q+1));
}
main()
{
  int i,j,k=0;
  for(i=2;i*i<=999999;i++)
  {
    if(che[i]==0)
    {
      for(j=i*i;j<=999999;j+=i)che[j]=1;
    }
  }
  scanf("%d",&N);
  f(1,1,0);
  printf("%d",dp[N][N]);
}
