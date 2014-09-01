main()
{
  int n;
  int a[10001];
  scanf("%d",&n);
  long long s=0;
  int i,j;
  for(i=0;i<n;scanf("%d",a+i++));
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      s+=abs(a[i]-a[j]);
    }
  }
  printf("%lld",s);
}
