main()
{
  double n,b,m;
  for(;~scanf("%lf%lf%lf",&n,&b,&m);)
  {
    int s=0;
    for(;n<=m;n+=n*b/100)s++;
    printf("%d\n",s);
  }
}
