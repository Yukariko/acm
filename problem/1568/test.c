main()
{
  int n;
  scanf("%d",&n);
  long long i,k=2*n,s=0;
  for(;n>0;)
  {
    for(i=1;i*(i+1)/2 <= n;i++);
    s+=i-1;
    n-=i*(i-1)/2;
  }
  printf("%lld",s);
}
