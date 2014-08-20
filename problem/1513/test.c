int point[51];
char map[51][51];
int n,m;
f(i,j,s,p)
{
  if(map[i][j])
  {
    p=map[i][j];
    s++;
  }
  if(i==n&&j==m)
  {
    point[s]=(point[s]+1)%1000007;
    return;
  }
  if(i<n&&(map[i+1][j]==0||map[i+1][j]>p))f(i+1,j,s,p);
  if(j<m&&(map[i][j+1]==0||map[i][j+1]>p))f(i,j+1,s,p);

}
main()
{
  int k;
  scanf("%d%d%d",&n,&m,&k);

  int i,x,y;
  for(i=1;i<=k;i++)
  {
    scanf("%d%d",&x,&y);
    map[x][y]=i;
  }
  f(1,1,0,0);
  for(i=0;i<=k;i++)printf("%d ",point[i]);
}
