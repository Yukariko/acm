main()
{
  long long a;
  scanf("%lld",&a);
  long long b=a,i;
  int count=0;
  for(i=1;i<=b;i<<=1)
  {
    if(b&i)count++;
    if((b&i)==0&&b&(i<<1))
    {
      b-=i;
      break;
    }
  }
  if(i>a){puts("0");return;}
  for(;i>>=1;)
  {
    if(b&i)b-=i;
    if(count)
    {
      b+=i;
      count--;
    }
  }
  printf("%lld ",b);
  count=0;
  b=a;
  for(i=1;i<=b;i<<=1)
  {
    if(b&i)
    {
      count++;
      if((b&(i<<1))==0)
      {
        b+=i;
        break;
      }
    }
  }
  b=b-(b&(i-1));
  printf("%lld\n",b+(1LL<<(count-1))-1);
}
