main()
{
  int n,m,k;
  int a[101][101];
  int b[101][101];
  scanf("%d%d",&n,&m);
  int i,j;
  for(i=0;i<n;i++)
  {
    for(j=0;j<m;j++)scanf("%d",&a[i][j]);
  }
  scanf("%d%d",&m,&k);
  for(i=0;i<m;i++)
  {
    for(j=0;j<k;j++)scanf("%d",&b[i][j]);
  }
  for(i=0;i<n;i++)
  {
    for(j=0;j<k;j++)
    {
      int p,r=0;
      for(p=0;p<m;p++)
      {
        r+=a[i][p]*b[p][j];
      }
      printf("%d ",r);
    }
    puts("");
  }
}
