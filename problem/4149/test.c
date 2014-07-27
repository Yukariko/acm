typedef long long ll;
ll arr[10000];
ll n;
//a^b mod c
unsigned long long mod_exp(unsigned long long a,unsigned long long b,unsigned long long c)
{
  a%=c;
  if(b==0)return 1;
  if(b==1)return a;
  if(b&1) return (a*mod_exp((a*a)%c,(b-1)/2,c))%c;
  return mod_exp((a*a)%c,b/2,c);
}

ll gcd(ll a,ll b)
{
  return b?gcd(b,a%b):a;
}
ll f(ll x,ll n,int a)
{
  return ((x%n)*(x%n)+a)%n;
}
ll absl(long long a)
{
  return a>=0?a:-a;
}
ll pollard_rho(ll n)
{
  ll x,y,d;
  int a;
  for(a=-1;a<2;a+=2)
  {
    x=y=2;
    for(d=1;d==1;d=gcd(n,absl(x-y)))
    {
      x=f(x,n,a);
      y=f(f(y,n,a),n,a);
    }
    if(d!=n)return d;
  }
  return d==n?0:d;
}
int cmp(ll *a,ll *b)
{
  return *a>*b?1:*a<*b?-1:0;
}
main()
{
  long long i,j,a,index=0;
  scanf("%lld",&n);
  for(;n>1;)
  {
    i=pollard_rho(n);
    if(i>1)
    {
      n/=i;
      arr[index++]=i;
    }
    else 
    {
      break;
    }
  }
  if(n>1)arr[index++]=n;
  qsort(arr,index,8,cmp);
  for(i=0;i<index;i++)printf("%lld\n",arr[i]);
}
