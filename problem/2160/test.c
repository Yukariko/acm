char map[51][6][7];
cmp(p,q)
{
  int i,j,s=0;
  for(i=0;i<5;i++)
  {
    for(j=0;j<7;j++)
    {
      s+=map[p][i][j]!=map[q][i][j];
    }
  }
  return s;
}
main()
{
  int n;
  scanf("%d ",&n);
  int i,j,k;
  for(i=0;i<n;i++)
  {
    for(j=0;j<5;j++)gets(map[i][j]);
  }
  int m=36;
  int p,q;
  for(i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
      k=cmp(i,j);
      if(m>k)
      {
        m=k;
        p=i;
        q=j;
      }
    }
  }
  printf("%d %d",p+1,q+1);
}
