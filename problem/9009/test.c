main()
{
  int fib[43];
  int i=1,j=0,k=0;
  for(;i<=1000000000;i++)
  {
    fib[k++]=i;
    i+=j;
    j=i-j;
  }
  int t;
  int a[43];
  for(scanf("%d",&t);t--;)
  {
    int n;
    scanf("%d",&n);
    j=0;
    for(i=k-1;i>=0;i--)
    {
      if(fib[i]>=n)
      {
        n-=fib[i];
        a[j++]=fib[i];
      }
    }
    for(i=0;i<j;i++)printf("%d ",a[i]);
    puts("");
  }
}
