long long f(long long n)
{
  long long x,j,k,t;
  x=0;
  for(t=0,j=1;j<=n;j*=10,t++)
  {
    k=(n/j)%10;
    if(!k){x-=j-1;x+=n%j;}
    x+=k*t*(j/10);
  }
  return x;
}
main()
{
  long long a,b;
  for(;scanf("%lld%lld",&a,&b),a!=-1;)
  {
    long long s=f(b)-f(a);
    if(a==0)s++;
    for(;a;a/=10)s+=a%10==0;
    printf("%lld\n",s);
  }
}
