main()
{
  int t;
  for(scanf("%d",&t);t--;)
  {
    int n;
    scanf("%d",&n);
    int i;
    long long s=0,k;
    for(i=0;i<n;i++)
    {
      scanf("%lld",&k);
      s=(s+k)%n;
    }
    puts(s?"NO":"YES");
  }
}
