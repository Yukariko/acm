int n,k;
int a[10];
char visit[99999999];
getMark()
{
  int i,s=0;
  for(i=0;i<n;i++)s=s*10+a[i];
  return s;
}
isSorted()
{
  int i;
  for(i=0;i<n-1;i++)if(a[i]>a[i+1])return 0;
  return 1;
}
reverse(p)
{
  int i;
  int b[10];
  for(i=0;i<k;i++)
  {
    b[i]=a[p+i];
  }
  for(i=k-1;i>=0;i--)
  {
    a[p+i]=b[k-i-1];
  }
}
int min=654321;
f(c)
{
  if(c>min)return;
  if(isSorted())
  {
    min=min>c?c:min;
    return;
  }
  int i,t;
  for(i=0;i<=n-k;i++)
  {
    reverse(i);
    t=getMark();
    if(visit[t]==0)
    {
      visit[t]=1;
      f(c+1);
      visit[t]=0;
    }
    reverse(i);
    t=getMark();
    if(visit[t]==0)
    {
      visit[t]=1;
      f(c+1);
      visit[t]=0;
    }
  }
}
main()
{
  scanf("%d%d",&n,&k);
  int i;
  for(i=0;i<n;i++)scanf("%d",a+i);
  f(0);
  printf("%d",min==654321?-1:min);
}
