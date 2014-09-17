main()
{
  int t;
  for(scanf("%d",&t);t--;)
  {
    int h,w;
    scanf("%d%d ",&h,&w);
    char map[12][12]={};
    int i,j;
    for(i=0;i<h;i++)gets(map[i]);
    for(i=h-1;i>=0;i--)
    {
      for(j=0;j<w;j++)
      {
        printf("%c",map[i][j]);
      }
      puts("");
    }
  }
}
