int n;
int a,b;
int x,y;
f(p)
{
  int i,s;
  for(s=i=1;s<p;s+=++i);
  x=i-(s-p);
  y=1+s-p;
}
g(p,q)
{
  int i,s;
  i=p+q-1;
  s=i*(i+1)/2;
  return 1+s-q;
}
main()
{
  for(scanf("%d",&n);n--;)
  {
    scanf("%d%d",&a,&b);
    int tx,ty;
    f(a);tx=x;ty=y;
    f(b);tx+=x;ty+=y;
    printf("%d\n",g(tx,ty));
  }
}
