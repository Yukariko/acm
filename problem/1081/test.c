long long f(n,i)
{
  long long x,j,k,t;
  x=0;
  for(t=0,j=1;j<=n;j*=10,t++)
  {
    k=(n/j)%10;
    if(i<k)x+=j;
    else if(i==k)x+=n%j+1;
    x+=k*t*(j/10);
  }
  return x;
}
main()
{
  int L,U;
  scanf("%d%d",&L,&U);
  long long i,s=0;
  for(i=1;i<=9;i++)
  {
    s+=(f(U,i)-f(L,i))*i;
  }
  for(;L;L/=10)s+=L%10;
  printf("%lld",s);
}

