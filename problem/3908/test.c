isPrime(n){int i;for(i=2;i*i<=n;i++)if(n%i==0)return 0;return 1;}
int dp[1121][15];
main()
{
  int prime[188];
  int i,j,k=0,l;
  for(i=2;i<=1120;i++)if(isPrime(i))prime[k++]=i;
  dp[0][0]=1;
  for(i=0;i<187;i++)
  {
    for(j=1120;j>=prime[i];j--)
    {
      for(k=1;k<=14;k++)
      {
        dp[j][k]+=dp[j-prime[i]][k-1];
      }
    }
  }
  int t,n,p;
  for(scanf("%d",&t);t--;)
  {
    scanf("%d%d",&n,&p);
    printf("%d\n",dp[n][p]);
  }
}
