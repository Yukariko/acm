int a[51][51];
int b[51][51];
int n,m;
cmp()
{
  int i,j;
  for(i=0;i<n;i++)
  {
    for(j=0;j<m;j++)
    {
      if(a[i][j]!=b[i][j])return 0;
    }
  }
  return 1;
}

main()
{
  scanf("%d%d",&n,&m);
  int i,j;
  for(i=0;i<n;i++)
  {
    for(j=0;j<m;j++)
    {
      scanf("%d",&a[i][j]);
    }
  }
  for(i=0;i<n;i++)
  {
    for(j=0;j<m;j++)
    {
      scanf("%d",&b[i][j]);
    }
  }
}
