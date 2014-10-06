int n;
int chess[11][11];
int max;
isOK(p,q)
{
  int i,j;
  for(i=p,j=q;i>=0&&j>=0;i--,j--)if(chess[i][j]==2)return 0;
  for(i=p,j=q;i<n&&j<n;i++,j++)if(chess[i][j]==2)return 0;
  for(i=p,j=q;i>=0&&j<n;i--,j++)if(chess[i][j]==2)return 0;
  for(i=p,j=q;i<n&&j>=0;i++,j--)if(chess[i][j]==2)return 0;
  return 1;
}
check(p,q,c)
{
  int i,j;
  if(c==0)
  {
    for(i=p,j=q;i>=0&&j>=0;i--,j--)chess[i][j]+=2;
    for(i=p,j=q;i<n&&j<n;i++,j++)chess[i][j]+=2;
    for(i=p,j=q;i>=0&&j<n;i--,j++)chess[i][j]+=2;
    for(i=p,j=q;i<n&&j>=0;i++,j--)chess[i][j]+=2;
  }
  else
  {
    for(i=p,j=q;i>=0&&j>=0;i--,j--)chess[i][j]-=2;
    for(i=p,j=q;i<n&&j<n;i++,j++)chess[i][j]-=2;
    for(i=p,j=q;i>=0&&j<n;i--,j++)chess[i][j]-=2;
    for(i=p,j=q;i<n&&j>=0;i++,j--)chess[i][j]-=2;    
  }

  return 1;
}
f(p,q,c)
{
  if(p>=n)
  {
    max=max<c?c:max;
    return;
  }
  int i;
  for(i=q;i<n;i++)
  {
    if(chess[p][i]==1)
    {
      f(p,i+1,c);
      check(p,i,0);
      f(p,i+1,c+1);
      check(p,i,1);
      return;
    }
  }
  f(p+1,0,c);
}
main()
{
  int i,j;
  
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      scanf("%d",&chess[i][j]);
    }
  }
  f(0,0,0);
  printf("%d",max);
}
