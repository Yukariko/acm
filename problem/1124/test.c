isPrime(n)
{
  int i;
  if(n==1)return 0;
  for(i=2;i*i<=n;i++)if(n%i==0)return 0;
  return 1;
}
main()
{
  int i,j,k;
  char dp[100001]={};
  for(i=2;i<=100000;i++)
  {
    if(dp[i]==0)
    {
      for(j=i;j<=100000;j+=i)
      {
        for(k=j;k%i==0;k/=i)dp[j]++;
      }
    }
  }
  int a,b;
  scanf("%d%d",&a,&b);
  int s=0;
  for(;a<=b;a++)
  {
    s+=isPrime(dp[a]);
  }
  printf("%d",s);
}
