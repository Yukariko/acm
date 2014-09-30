main()
{
  int n,m;
  int a[100001][2];
  
  int i;
  scanf("%d%d",&n,&m);
  for(i=0;i<n;i++)
  {
    int x,y;
    scanf("%d%d",&x,&y);
    if(x!=-y)
    {
      a[abs(x)][x<0]++;
      a[abs(y)][y<0]++;
    }
  }
  for(i=1;i<=m;i++)if(a[i][0]&&a[i][1])return puts("OTL"),0;
  puts("^_^");
}
