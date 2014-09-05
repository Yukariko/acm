#define M 100000000
isPrime(p)
{
  int i;
  for(i=2;i*i<=p;i++)
  {
    if(p%i==0)return 0;
  }
  return 1;
}
isPalin(char *b,int len)
{
  int i=len/2;
  if(len%2==0)
  {
    int p,q;
    p=len/2-1;q=len/2;
    for(;p>=0&&q<len;p--,q++)if(b[p]!=b[q])return 0;
  }
  else
  {
    int p,q;
    p=len/2;q=p;    
    for(;p>=0&&q<len;p--,q++)if(b[p]!=b[q])return 0;
  }
  return 1;
}
f(n)
{
  
}
main()
{
  int a,b;
  scanf("%d%d",&a,&b);
}
