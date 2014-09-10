main()
{
  int t;
  for(t=3;t--;)
  {
    int n;
    int i;
    long double s=0,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
      scanf("%Lf",&k);
      s+=k;
    }
    puts(s>0?"+":s<0?"-":"0");
  }
}
