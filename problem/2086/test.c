//a^b mod c
double p,q;
double mod(double a,long long c)
{
  double t=a>0?a:-a;
  for(;t>=c;)t-=c;
  return a>0?t:-t;
}
double mod_exp(double a,long long b,long long c)
{
  puts("!");
  a=mod(a,c);
  if(b==0)return 1;
  if(b==1)return a;
  if(b&1) return mod((a*mod_exp(mod(a*a,c),(b-1)/2,c)),c);
  return mod_exp(mod(a*a,c),b/2,c);
}
main()
{
  long long a,b,c=1000000000;
  scanf("%lld%lld",&a,&b);
  p=(1.0+sqrt(5.0))/2.0;
  q=(1.0-sqrt(5.0))/2.0;
  a=(mod_exp(p,a+1,c)-mod_exp(q,a+1,c))/sqrt(5.0)+1e-6 - 2;
  puts("!");
  b=(mod_exp(p,b+2,c)-mod_exp(q,b+2,c))/sqrt(5.0)+1e-6 - 2;
  printf("%lld",b-a);
}
