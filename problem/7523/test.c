int t;
long long n,m;
long long s;

main()
{
  int i;
  scanf("%d",&t);
  for(i=1;i<=t;i++)
  {
    scanf("%lld%lld",&n,&m);
    printf("Scenario #%d:\n",i);
    if(n*m>=0)
    {
      if(n>m)s=n*(n+1)/2-m*(m-1)/2;
      else s=m*(m+1)/2-n*(n-1)/2;
    }
    else
    {
      if(n<0)s=-n*(n-1)/2 + m*(m+1)/2;
      else s=n*(n+1)/2 - m*(m-1)/2;
    }
    printf("%lld\n\n",s);
  }
}
