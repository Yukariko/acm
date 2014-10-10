main()
{
  long long n,i,j,r;
  int k;
  scanf("%lld%d",&n,&k);
  r=0;
  for(i=1;i<=n;)
  {
    j=(i-r-1)/k;
    if(i+j>n)j=n-i;
    if(j==0)j=1;
    r = (r+k*j)%i;
    i+=j;
  }
  printf("%lld",r+1);
}
