int n;
long long i,j,s,t=100000;
main()
{
  
  for(;~scanf("%d",&n);)
  {
    for(s=i=1;i<=n;i++)
    {
      for(j=1;j<=s*i&&s*i/j%10==0;j*=10);
      s=s*i/j%t;
    }
    printf("%5d -> %lld\n",n,s%10);
  }
}
