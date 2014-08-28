main()
{
  int n;
  scanf("%d",&n);
  long long i=1,j=0,t;
  for(;n--;)
  {
    t=i%15746;
    i=(i+j)%15746;
    j=t;
  }
  printf("%lld",i);
}
