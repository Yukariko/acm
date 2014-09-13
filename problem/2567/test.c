char map[101][101];
f(i,j)
{
  if(i<0||j<0||i>100||j>100||map[i][j]==2)return 0;
  if(map[i][j]==1)return 1;
  map[i][j]=2;
  return f(i-1,j)+f(i+1,j)+f(i,j-1)+f(i,j+1);
}
main()
{
  int n;
  int x,y,w,h;
  int i,j,k;
  for(k=scanf("%d",&n);k<=n;k++)
  {
    scanf("%d%d",&x,&y);
    for(i=x;i<x+10;i++)
    {
      for(j=y;j<y+10;j++)
      {
        map[i][j]=1;
      }
    }
  }
  int s=0;
  for(i=0;i<=100;i++)
  {
    for(j=0;j<=100;j++)
    {
      if(map[i][j]==0)
      {
        s+=f(i,j);
      }
    }
  }
  printf("%d\n",s);
}
