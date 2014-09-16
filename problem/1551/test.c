main()
{
  int n,k;
  scanf("%d%d",&n,&k);
  int i;
  int a[21];
  for(i=0;i<n;i++)scanf("%d%*c",a+i);
  for(;k--;)
  {
    for(i=1;i<n;i++)
    {
      a[i-1]=a[i]-a[i-1];
    }
    n--;
  }
  for(i=0;i<n;i++)
  {
    printf("%d",a[i]);
    if(i!=n-1)putchar(',');
  }
}
