f(a,b){return b?f(b,a%b):a;}
main()
{
  int n,m,k;
  scanf("%d%d",&n,&m);
  k=f(n,m);
  int a,b;
  a=n/k;
  b=m/k;
  printf("%d",n*(b-1)/a);
  
}
