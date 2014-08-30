main()
{
  int t;
  for(scanf("%d",&t);t--;)
  {
    int a,b;
    int sa=0,sb=0;
    int i;
    for(i=0;i<9;i++)
    {
      scanf("%d%d",&a,&b);
      sa+=a;sb+=b;
    }
    puts(sa>sb?"Yonsei":sa<sb?"Korea":"Draw");
  }
}
