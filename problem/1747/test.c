isPrime(p)
{
  int i;
  for(i=2;i*i<=p;i++)
  {
    if(p%i==0)return 0;
  }
  return 1;
}
char a[10];
isPalin(int len)
{
  int i=len/2;
  int p,q;
  if(len%2==0)
  {
    p=i-1;q=i;
    for(;p>=0&&q<len;p--,q++)if(a[p]!=a[q])return 0;
  }
  else
  {
    p=i;q=p;    
    for(;p>=0&&q<len;p--,q++)if(a[p]!=a[q])return 0;
  }
  return 1;
}
main()
{
  int n;
  scanf("%d",&n);
  for(;;n++)
  {
    if(isPalin(sprintf(a,"%d",n)))
    {
      if(isPrime(n))break;
    }
  }
  puts(a);
}
