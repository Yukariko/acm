long long f(long long n,int i)
{
  long long res,j,k,t;
  res=0;
  for(t=0,j=1;j<=n;j*=10,t++)
  {
    k=(n/j)%10;
    if(i==0)
    {
      if(!k)
      {
        res-=j-1;
        res+=n%j;
      }
    }
    else if(i<k)res+=j;
    else if(i==k)res+=n%j+1;
    res+=k*t*(j/10);
  }
  return res;
}
main()
{
  int t;
  for(scanf("%d",&t);t--;)
  {
    long long a,b;
    scanf("%lld%lld",&a,&b);
    long long i,s=0;
    for(i=1;i<=9;i++)
    {
      s+=(f(b,i)-f(a,i))*i;
    }
    for(;a;a/=10)s+=a%10;
    printf("%lld\n",s);
  }
}
