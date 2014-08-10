long long a,b;
long long t,s,k,p;
main()
{
  scanf("%lld%lld",&a,&b);
  for(t=1;t<=b;t<<=1)
  {
    k=t*ceil((double)a/t);
    if(k<=b)
    {
      s+=((b-k)/t+1)*(t-p);
      p=t;
    }
  }
  printf("%lld",s);
}
