main()
{
  int n;
  scanf("%d",&n);
  int i;
  double t,s=1.0,max=0.0;
  for(i=0;i<n;i++)
  {
    scanf("%lf",&t);
    s*=t;
    max=max<s?s:max;
    if(s<1.0)s=1.0;
  }
  printf("%.3lf",max);
}
