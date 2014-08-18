main()
{
  int t,tt,n,k;
  long long s,p;
  for(scanf("%d",&t);t--;)
  {
    scanf("%d%d%d",&tt,&n,&k);
    p=n;
    for(s=p=1;p<=n;p++)s*=p;
    p=1;for(n-=k;n;p*=n--);
    printf("%d %lld %lld\n",tt,s,p);
  }
}
