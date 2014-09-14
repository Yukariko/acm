int res[11];
char a[11][11];
int n;
sum(i,j)
{
  int s;
  for(s=0;i<=j;i++)s+=res[i];
  return s;
}
f(p)
{
  int i,j;
  for(i=0;i<p;i++)
  {
    for(j=i;j<p;j++)
    {
      if(a[i][j]=='-'&&sum(i,j)>=0)return;
      else if(a[i][j]=='0'&&sum(i,j))return;
      else if(a[i][j]=='+'&&sum(i,j)<=0)return;
    }
  }
  if(p==n)
  {
    for(i=0;i<n;i++)printf("%d ",res[i]);
    exit(0);
  }
  if(a[p][p]=='-')
  {
    for(i=1;i<=10;i++)
    {
      res[p]=-i;
      f(p+1);
    }
  }
  else if(a[p][p]=='0'){res[p]=0;f(p+1);}
  else
  {
    for(i=1;i<=10;i++)
    {
      res[p]=i;
      f(p+1);
    }
  }
}
main()
{
  scanf("%d",&n);
  int i,j;
  for(i=0;i<n;i++)
  {
    for(j=i;j<n;j++)
    {
      scanf(" %c",&a[i][j]);
    }
  }
  f(0);
}
