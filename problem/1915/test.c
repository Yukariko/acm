char map[1001][1001];
int max;
f(i,j)
{
  int p,q,r;
  for(r=max;;r++)
  {
    for(p=0;p<r;p++)
    {
      for(q=0;q<r;q++)
      {
        if(map[i+p][j+q]!='1')
        {
          return r-1;
        }
      }
    }
  }
}
main()
{
  int n,m;
  
  scanf("%d%d ",&n,&m);
  int i,j,s;
  for(i=0;i<n;i++)gets(map[i]);
  for(i=0;i<n;i++)
  {
    for(j=0;j<m;j++)
    {
      if(map[i][j]=='1')
      {
        s=f(i,j);
        max=max<s?s:max;
      }
    }
  }
  printf("%d",max*max);
}
