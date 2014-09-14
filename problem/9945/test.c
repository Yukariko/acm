main()
{
  int n;
  int i;
  for(i=1;scanf("%d",&n),n>0;i++)
  {
    int x,y,m;
    int sx,sy;
    float a,b;
    for(a=b=sx=sy=0;n--;)
    {
      scanf("%d%d%d",&x,&y,&m);
      sx+=m*x;
      sy+=m*y;
      a+=m;
      b+=m;
    }
    a=sx/a;
    b=sy/b;
    printf("Case %d: %.2f %.2f\n",i,a,b);
  }
}
