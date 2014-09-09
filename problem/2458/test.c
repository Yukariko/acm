char tall[501][501];
int visit[2][501];
int n,m;
f(p,c)
{
  int i,t;
  t=c==1;
  if(visit[t][p])return;
  visit[t][p]=1;
  for(i=1;i<=n;i++)
  {
    if(tall[p][i]==c)f(i,c);
  }
}
main()
{
  scanf("%d%d",&n,&m);
  int i,j;
  int x,y;
  for(i=0;i<m;i++)
  {
    scanf("%d%d",&x,&y);
    tall[y][x]=1;
    tall[x][y]=-1;
  }
  int s=0,c;
  for(i=1;i<=n;i++)
  {
    memset(visit,0,sizeof(visit));
    f(i,1);f(i,-1);
    c=0;
    for(j=1;j<=n;j++)c+=visit[0][j]+visit[1][j];
    if(c==n+1)s++;
  }
  printf("%d",s);
}
