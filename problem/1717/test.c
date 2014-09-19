int jump[1000001];
int r[1000001];
find(n)
{
  if(n==jump[n])return n;
  return jump[n]=find(jump[n]);
}
merge(x,y)
{
  x=find(x);
  y=find(y);
  if(r[x]<r[y])jump[x]=y;
  else
  {
    jump[y]=x;
    if(r[x]==r[y])r[x]++;
  }
}
main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  int c,a,b;
  int i;
  for(i=0;i<=n;i++)jump[i]=i;
  for(;m--;)
  {
    scanf("%d%d%d",&c,&a,&b);
    if(c==0)
    {
      merge(a,b);
    }
    else
    {
      puts(find(a>b?a:b,a>b?b:a)?"YES":"NO");
    }
  }
}
