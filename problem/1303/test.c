char map[101][101];
int n,m;
f(i,j,c)
{
  if(map[i][j]!=c||i<0||j<0||i>=m||j>=n)return 0;
  map[i][j]=0;
  return 1+f(i-1,j,c)+f(i+1,j,c)+f(i,j-1,c)+f(i,j+1,c);
}
main()
{
  scanf("%d%d ",&n,&m);
  int i,j,k;
  for(i=0;i<m;i++)
  {
    gets(map[i]);
  }
  int w=0,b=0;
  for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
    {
      if(map[i][j]=='W')
      {
        k=f(i,j,'W');
        w+=k*k;
      }
      else if(map[i][j]=='B')
      {
        k=f(i,j,'B');
        b+=k*k;
      }
    }
  }
  printf("%d %d",w,b);
}
