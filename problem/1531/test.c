main()
{
  char map[101][101]={};
  int n,m;
  for(scanf("%d%d",&n,&m);n--;)
  {
    int x1,y1,x2,y2,t;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    for(;x1<=x2;x1++)
    {
      for(t=y1;t<=y2;t++)
      {
        map[x1][t]++;
      }
    }
  }
  int i,j,s=0;
  for(i=1;i<=100;i++)for(j=1;j<=100;j++)s+=map[i][j]>m;
  printf("%d",s);
}
