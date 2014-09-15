main()
{
  int t;
  char a[1000001]={};
  for(scanf("%d",&t);t;t--)
  {
    int k,p;
    for(scanf("%d",&k);k--;a[p]=t)scanf("%d",&p);
    int n,no,h,m,min=3000,s=0;
    for(scanf("%d",&n);n--;)
    {
      scanf("%d%d%d",&no,&h,&m);
      if(a[no]==t&&h!=-1)
      {
        h=h*60+m;
        if(h<=360)s++;
        if(h<min)
        {
          min=h;
          p=no;
        }
      }
    }
    printf("%d %d\n",p,s);
  }
}
