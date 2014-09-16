main()
{
  int n,m;
  for(;~scanf("%d%d",&n,&m);)
  {
    int s=0;
    for(;n<=m;n++)
    {
      int t;
      int a[10]={};
      for(t=n;t;t/=10)
      {
        if(a[t%10])break;
        a[t%10]=1;
      }
      if(t==0)s++;
    }
    printf("%d\n",s);
  }
}
