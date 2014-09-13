main()
{
  char map[51][51];
  int r,c;
  scanf("%d%d ",&r,&c);
  int i,j;
  for(i=0;i<r;i++)
  {
    gets(map[i]);
  }
  int a[5]={};
  for(i=0;i<r-1;i++)
  {
    for(j=0;j<c-1;j++)
    {
      if(map[i][j]!='#'&&map[i+1][j]!='#'&&map[i][j+1]!='#'&&map[i+1][j+1]!='#')
      {
        a[(map[i][j]=='X')+(map[i+1][j]=='X')+(map[i][j+1]=='X')+(map[i+1][j+1]=='X')]++;
      }
    }
  }
  for(i=0;i<=4;i++)printf("%d\n",a[i]);
}
