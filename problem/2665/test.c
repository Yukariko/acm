char map[51][51];
int n;
#define min(a,b) (a>b?b:a)
f(i,j)
{
  if(map[i][j]==2)return;
  map[i][j]=2;
  if(i<n&&map[i+1][j])f(i+1,j);
  if(i>1&&map[i-1][j])f(i-1,j);
  if(j<n&&map[i][j+1])f(i,j+1);
  if(j>1&&map[i][j-1])f(i,j-1);
}
main()
{
  int i,j;
  unsigned char point[51][51];
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      scanf(" %c",&map[i][j]);
      map[i][j]-=48;
    }
  }
  f(1,1);
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      point[i][j]=map[i][j]==2?0:255;
    }
  }
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      if(j>1)point[i][j]=min(point[i][j],point[i][j-1]);
      if(i>1)point[i][j]=min(point[i][j],point[i-1][j]);
      point[i][j]+=!map[i][j];
    }
  }
  printf("%d",point[n][n]);
}
