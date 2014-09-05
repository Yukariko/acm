isPrime(p)
{
  int i;
  for(i=2;i*i<=p;i++)
  {
    if(p%i==0)return 0;
  }
  return 1;
}
f(s,n)
{
  int i,t;
  if(n==0)printf("%d\n",s);
  for(i=1;i<10;i+=2)
  {
    t=s*10+i;
    if(isPrime(t))
    {
      f(t,n-1);
    }
  }
}
main()
{
  int n;
  int a[]={2,3,5,7};
  scanf("%d",&n);
  int i,j,k,s;
  for(i=0;i<4;i++)
  {
    f(a[i],n-1);
  }
}
