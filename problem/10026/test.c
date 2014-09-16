char map[101][101];
int n;
f(i,j,c)
{
  if(i<0||i>=n||j<0||j>=n||map[i][j]!=c)return;
  map[i][j]=c=='B'?2:c>'B'?1:0;
  f(i-1,j,c);f(i+1,j,c);f(i,j-1,c);f(i,j+1,c);
}
main()
{
  scanf("%d ",&n);
  int i,j;
  int s,r;
  s=r=0;
  for(i=0;i<n;i++)gets(map[i]);
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(map[i][j]>='B')
      {
        f(i,j,map[i][j]);
        s++;
      }
    }
  }
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(map[i][j]!=0)
      {
        f(i,j,map[i][j]);
        r++;
      }
    }
  }
  printf("%d %d",s,r);
}
