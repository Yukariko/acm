main()
{
  int t;
  for(scanf("%d",&t);t--;)
  {
    int n,s=0;
    int m=-1001;
    scanf("%d",&n);
    for(;n--;)
    {
      int k;
      scanf("%d",&k);
      s=s<0?k:s+k;
      m=m<s?s:m;
    }
    printf("%d\n",m);
  }
}

