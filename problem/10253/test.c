long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
main()
{
  int t;
  for(scanf("%d",&t);t--;)
  {
    int i,k;
    long long a,b;
    scanf("%lld%lld",&a,&b);
    for(;a>1;)
    {
      i = (b/a)+1;
      k = b*i/gcd(b,i);
      if(a*k/b >= k/i)
      {
        a = a*k/b - k/i;
        b = k;
        k = gcd(a,b);
        a /= k;
        b /= k;
      }
    }
    printf("%lld\n",a==1?b:i);
  }
}
