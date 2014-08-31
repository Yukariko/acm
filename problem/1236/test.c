main()
{
  int n,m;
  scanf("%d%d ",&n,&m);
  char a[51][51];
  int cX[51]={};
  int cY[51]={};
  int i,j,k,s=0;
  for(i=0;i<n;i++)gets(a[i]);
  for(i=0;i<n;i++)
  {
    for(j=0;j<m;j++)
    {
      if(a[i][j]=='X')
      {
        cX[j]++;
        cY[i]++;
        for(k=0;k<m;k++)
        {
          if(a[i][k]=='.')a[i][k]=0;
        }
        for(k=0;k<m;k++)
        {
          if(a[k][j]=='.')a[k][j]=0;
        }
      }
    }
  }
  for(i=0;i<n;i++)
  {
    for(j=0;j<m;j++)
    {
      if(a[i][j]=='.')
      {
        s++;
        cY[i]++;
        cX[j]++;
        a[i][j]='X';
        for(k=0;k<m;k++)
        {
          if(a[i][k]=='.')a[i][k]=0;
        }
        for(k=0;k<m;k++)
        {
          if(a[k][j]=='.')a[k][j]=0;
        }
      }
    }
  }
  j=0;
  for(i=0;i<n;i++)j+=!cY[i];
  k=0;
  for(i=0;i<m;i++)k+=!cX[i];
  printf("%d",s+(j>k?j:k));
}
