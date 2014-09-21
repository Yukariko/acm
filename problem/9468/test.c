int a[16];
f()
{
  int i,j,s=0,k;
  for(i=0;i<15;i++)
  {
    k=-1;
    for(j=0;j<15;j++)
    {
      if(a[j]==0&&k)
      {
        if(k!=-1)s++;
        k=0;
      }
      else if(a[j]&&k==0)
      {
        k=1;
      }
    }
    for(j=0;j<15;j++)
    {
      if(a[j])a[j]--;
    }
  }
  return s;
}
main()
{
  int t;
  int i;
  scanf("%d",&t);
  for(i=1;i<=t;i++)
  {
    int j,k;
    scanf("%d",&j);
    for(j=0;j<15;j++)scanf("%d",a+j);
    printf("%d %d\n",i,f());
  }
}
