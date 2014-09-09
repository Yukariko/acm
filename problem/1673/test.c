main()
{
  int n,m;
  long long s,k,c;
  for(;~scanf("%d%d",&n,&m);)
  {
    s=n;
    k=n;
    for(;k/m;)
    {
      s+=k/m;
      k=k/m+k%m;
    }
    printf("%lld\n",s);
  }
}
