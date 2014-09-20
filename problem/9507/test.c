main()
{
  int t;
  long long a[68];
  a[0]=a[1]=1;
  a[2]=2;
  a[3]=4;
  int i;
  for(i=4;i<=67;i++)
  {
    a[i]=a[i-1]+a[i-2]+a[i-3]+a[i-4];
  }
  for(scanf("%d",&t);t--;)
  {
    int n;
    scanf("%d",&n);
    printf("%lld\n",a[n]);
  }
}
