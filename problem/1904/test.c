main()
{
  int n;
  scanf("%d",&n);
  int i=1,j=0,t;
  for(;n--;)
  {
    t=i;
    i=(i+j)%15746;
    j=t;
  }
  printf("%lld",i);
}
