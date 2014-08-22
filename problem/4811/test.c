long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
main()
{
  long long n;
  for(;scanf("%lld",&n),n;)
  {
    long long i,j=2*n,t=1,k=(n+1)/2,p=k,q;
    for(i=n+2;i<=j;i++)
    {
      t*=i/(i%2?1LL:i/2);
      q=gcd(t,p);
      t/=q;
      p/=q;
      if(p==1&&k>1)p=--k;
    }
    printf("%lld\n",t);
  }
}

