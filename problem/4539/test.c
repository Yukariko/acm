main()
{
  int t;
  for(scanf("%d",&t);t--;)
  {
    int n;
    scanf("%d",&n);
    int i,j=0,k;
    for(i=10;i<n;i*=10)
    {
      if(n/(i/10)%10+j>=5)j=1;
      n=n/i*i+j*i;
      j=0;
    }
    printf("%d\n",n);
  }
}
