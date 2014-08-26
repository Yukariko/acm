main()
{
  int a,b,c,d;
  for(;scanf("%d%d%d%d",&a,&b,&c,&d),a;)
  {
    int ta,tb,tc,td,s;
    for(s=0;!(a==b&&c==d&&b==c);s++)
    {
      ta=abs(a-b);
      tb=abs(b-c);
      tc=abs(c-d);
      td=abs(d-a);
      a=ta;
      b=tb;
      c=tc;
      d=td;
    }
    printf("%d\n",s);
  }
}
