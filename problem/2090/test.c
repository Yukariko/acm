long long f(long long a,long long b){return b?f(b,a%b):a;}
main()
{
  int n;
  long long a[10];
  long long i,j,k;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%lld",a+i);
  // q/p
  long long p=1,q=0;
  for(i=0;i<n;i++)
  {
    j=p;
    k=f(p,a[i]);
    p*=a[i]/k;
    q=q*(a[i]/k)+(j/k);
  }
  k=f(p,q);
  p/=k;
  q/=k;
  printf("%lld/%lld",p,q);
}

