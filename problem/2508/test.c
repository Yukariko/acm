int r,c;
isOK(i,j){return i<0||j<0||i>=r||j>=c?0:1;}
main()
{
  int t;
  char map[401][401];
  for(scanf("%d",&t);t--;)
  {
    scanf("%d%d ",&r,&c);
    int i,j,s=0;
    for(i=0;i<r;i++)gets(map[i]);
    for(i=0;i<r;i++)
    {
      for(j=0;j<c;j++)
      {
        if(map[i][j]=='o')
        {
          if(isOK(i-1,j)&&isOK(i+1,j)&&map[i-1][j]=='v'&&map[i+1][j]=='^')s++;
          if(isOK(i,j-1)&&isOK(i,j+1)&&map[i][j-1]=='>'&&map[i][j+1]=='<')s++;
        }
      }
    }
    printf("%d\n",s);
  }
}
