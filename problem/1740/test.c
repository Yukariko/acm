main()
{
  long long n;
  scanf("%lld",&n);
  long long i,j,k,s=0;
  for(;n>0;)
  {
    j=0;
    for(i=1;i*2<=n;i<<=1)j++;
    for(k=1;j--;k*=3);
    s+=k;
    n-=i;
  }
  printf("%lld",s);
}
