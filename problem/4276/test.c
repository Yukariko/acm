long long n,m;
long long f(long long p,long long q)
{
  long long i,k=0,s=q-p;
  for(i=1;i<=s;i*=10)
  {
    k+=s/i*(i/10);
  }
  return k;
}
long long u(long long p,long long q)
{
  long long i,s;
  for(s=p==0;p<=q;p++)
  {
    for(i=1;i<=p;i*=10)s+=p/i%10?0:1;

  }
  return s;
}
long long t(long long q)
{
  long long i,k=0,s=0,j;
  for(j=0,i=1;i<=q;i*=10,j++)
  {
    if(i>=10)s+=9*i/100*(j-1)+1;
  }
  return s;
}
main()
{
  for(;scanf("%lld%lld",&n,&m),n>=0;)
  {
    
    printf("%lld %lld\n",u(n,m),t(m));
  }
}
