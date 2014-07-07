a[101][101];x;y;n;
f(p,i,c)
{
  for(;i<=n;i++)
    if(a[i][p] || a[p][i])
    {
      a[i][p]=a[p][i]=0;
      f(i,1,c+1);
    }
  if (p == y){printf("%d",c);exit(1);}
}
main(p,q)
{
  for(scanf("%d%d%d%d",&n,&x,&y,&p);~scanf("%d%d",&p,&q);a[p][q]++);
  f(x,1,0);
  printf("-1");
}
