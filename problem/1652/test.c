main()
{
  int n;
  int i,j;
  char map[101][101];
  scanf("%d ",&n);
  for(i=0;i<n;i++)gets(map[i]);
  int w=0,h=0;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(map[i][j]=='.')
      {
        if(i+1<n&&map[i+1][j]=='.')
        {
          if(i+2==n)w++;
          else if(map[i+2][j]=='X')w++;
        }
        if(j+1<n&&map[i][j+1]=='.')
        {
          if(j+2==n)h++;
          else if(map[i][j+2]=='X')h++;
        }
      }
    }
  }
  printf("%d %d",h,w);
}
