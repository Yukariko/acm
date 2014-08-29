unsigned long long fact[10000];
unsigned long long n;
int k;
f(int i,unsigned long long s)
{
  int p;
  unsigned long long t;
  if(s==n){puts("YES");exit(0);}
  for(p=i;p<k;p++)
  {
    if(fact[p])
    {
      t=fact[p];
      fact[p]=0;
      f(p,s+t);
      fact[p]=t;
    }
  }
}
main()
{
  scanf("%llu",&n);
  fact[k++]=1;
  unsigned long long i,j;
  for(i=j=1;i>=1&&i<=n;i*=++j)fact[k++]=i;
  if(n)f(0,0LL);
  puts("NO");
}
