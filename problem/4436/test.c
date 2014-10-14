main()
{
  long long n;
  for(;~scanf("%lld",&n);)
  {
    long long s,t;
    int k,count=0;
    char ck[10]={};
    for(k=0,s=n;count<10;k++,s+=n)
    {
      for(t=s;t;t/=10)
      {
        if(ck[t%10]==0)
        {
          ck[t%10]++;
          count++;
        }
      }
    }
    printf("%d\n",k);
  }
}
