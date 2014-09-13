main()
{
  int n;
  char map[101][101]={};
  int x,y,w,h;
  int i,j,k;
  for(k=scanf("%d",&n);k<=n;k++)
  {
    scanf("%d%d%d%d",&x,&y,&w,&h);
    for(i=x;i<x+w;i++)
    {
      for(j=y;j<y+h;j++)
      {
        map[i][j]=k;
      }
    }
  }
  int s;
  for(k=1;k<=n;k++)
  {
    s=0;
    for(i=0;i<=100;i++)
    {
      for(j=0;j<=100;j++)
      {
        s+=map[i][j]==k;
      }
    }
    printf("%d\n",s);
  }
}
