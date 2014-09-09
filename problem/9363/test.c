long long f(long long a,long long b){return b?f(b,a%b):a;}
cmp(long long *a,long long *b){return *a>*b?1:*a<*b?-1:0;}
main()
{
  int t,tn;
  int n,m;
  long long a[110001];
  long long b[110001];
  long long x,y,k;
  scanf("%d",&t);
  for(tn=1;tn<=t;tn++)
  {
    scanf("%d%d",&n,&m);
    int i,j;
    for(i=0;i<n;i++)scanf("%lld",a+i);
    for(i=0;i<m;i++)scanf("%lld",b+i);
    qsort(a,n,8,cmp);
    qsort(b,m,8,cmp);
    x=a[0];
    y=b[0];
    k=f(x,y);
    x/=k;
    y/=k;
    for(i=j=1;i<n||j<m;)
    {
      if(i<n&&j<m)
      {
        k=f(a[i],b[j]);
        a[i]/=k;
        b[j]/=k;
      }
      if(i<n)x*=a[i];
      if(i<m)y*=b[i];
      k=f(x,y);
      x/=k;
      y/=k;
      i++;j++;
    }
    printf("Case #%d: %lld / %lld\n",tn,x,y);
  }
}
