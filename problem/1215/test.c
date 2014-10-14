main()
{
  int n,k;
  int i,j;
  long long r;
  scanf("%d%d",&n,&k);
  
  r=0;
  for(i=1;i<=n;)
  {
    j=(i-1)/k;
    if(j)
    {
      if(i+j>n)j=n-i;
      r=r+k*j;
      i+=j;
    }
    if(j==0)
    {
      r=r+(k%i);
      i++;
    }
  }
  printf("%lld",r);
}
