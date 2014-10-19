//a^b mod c
long long mod_exp(long long a,long long b,long long c)
{
  a%=c;
  if(b==0)return 1;
  if(b==1)return a;
  if(b&1) return (a*mod_exp((a*a)%c,(b-1)/2,c))%c;
  return mod_exp((a*a)%c,b/2,c);
}

main()
{
  int N,K;
  long long res;
  long long mod = 1000000009LL;
  scanf("%d%d",&N,&K);
  res = mod_exp(K,N,mod);
  res -= 2 * (N-4) * mod_exp(K,N-5,mod);
  res = res < 0? res + mod : res;
  printf("%lld",res);
}

