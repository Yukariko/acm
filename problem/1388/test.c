main()
{
  int n,m;
  char a[101][101];
  scanf("%d%d ",&n,&m);
  int i,j,k,s=0;
  for(i=0;i<n;i++)gets(a[i]);
  for(k=1;k;)
  {
    k=0;
    int b=0;
    for(i=0;i<n;i++)
    {
      for(j=0;j<m;j++)
      {
        if(a[i][j]=='-'||a[i][j]=='|')
        {
          b=1;
          break;
        }
      }
      if(b)break;
    }
    if(a[i][j]=='-')
    {
      k=1;
      s++;
      for(;j<m&&a[i][j]=='-';j++)a[i][j]=0;
    }
    else if(a[i][j]=='|')
    {
      k=1;
      s++;
      for(;i<n&&a[i][j]=='|';i++)a[i][j]=0;
    }
  }
  printf("%d",s);
}
