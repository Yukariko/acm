main()
{
  int t;
  for(scanf("%d",&t);t--;)
  {
    int n,s=1;
    scanf("%d",&n);
    int i,j;
    for(i=2;i*i<=n;i++)
    {
      if(n%i==0)
      {
        for(j=n;j%i==0;j/=i)s++;
        if(i!=n/i)for(j=n;j%(n/i)==0;j/=n/i)s++;
      }
    }
    printf("%d\n",n==1?0:s);
  }
}
