long long f(long long n)
{
  long long res=0;
  long long i,count;
  for(i=2;i<=n*2;i<<=1)
  {
    count=n/i+(n%i?1:0);
    count*=i/2;
    if(n%i)
    {
      if(n%i<i/2)count-=i/2;
      else count-=count*2-n-1;
    }
    res+=count;
  }  
  return res;
}
main()
{
  long long a,b;
  scanf("%lld%lld",&a,&b);
  printf("%lld",f(b)-f(a-1));
}
