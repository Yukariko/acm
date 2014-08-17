int a[101][101];
int visit[101][101];
int n,m;
int c;
f(x,y,v)
{
  int i,j;
  c++;
  for(i=1;i<=n;i++)
  {
    if(visit[x][i]==0&&a[x][i]==v)
    {
      a[y][i]=v;
      f(i,y,a[x][i]);
    }
  }
}
main()
{
  int x,y;

  for(scanf("%d%d",&n,&m);m--;)
  {
    scanf("%d%d",&x,&y);
    if(!a[x][y])
    {
      a[x][y]=-1;
      a[y][x]=1;
    }
  }
  int i,j,s;
  for(i=1;i<=n;i++)
  {
    f(i,i,1);
    f(i,i,-1);
  }
  for(i=1;i<=n;i++)
  {
    s=n-1;
    for(j=1;j<=n;j++)
    {
      if(a[i][j])s--;
    }
    printf("%d\n",s);
  }
}
