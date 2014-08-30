long long a[1000000];
int b[1000000];
main()
{
  int t;
  for(scanf("%d",&t);t--;)
  {
    long long n,k;
    scanf("%lld%lld",&n,&k);
    long long i,j=0,t;
    t=k;
    for(i=2;i*i<=t;i++)
    {
      if(t%i==0)
      {
        a[j]=i;
        b[j]=0;
        for(;t%i==0;t/=i)b[j]++;
        j++;
      }
    }
    b[j]++;
    a[j++]=t;
    long long max=0,s=0;
    for(i=0;i<j;i++)max=a[max]<a[i]?i:max;
    for(t=a[max];t>0&&t<=n;t*=a[max])s+=n/t/b[max];
    printf("%lld\n",s);
  }
}
