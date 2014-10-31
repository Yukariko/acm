long long MAX(long long a,long long b){return a>b?a:b;}
long long MIN(long long a,long long b){return a>b?b:a;}
 
main()
{
  int N,K,i;
  long long a[10001];
  long long hmax=0,hmin=0,lmax=0,lmin=0;
  long long res=0;
  scanf("%d%d",&N,&K);
  for(i=0;i<K;i++)
  {
    scanf("%lld",&a[i]);
    if(i==0)lmax=lmin=a[i];
    else
    {
      lmax = MAX(lmax,a[i]);
      lmin = MIN(lmin,a[i]);
      res += a[i] > a[i-1]? a[i]-a[i-1] : a[i-1] - a[i];
    }
  }
  for(;i<N;i++)
  {
    scanf("%lld",&a[i]);
    if(i==K) hmax=hmin=a[i];
    else
    {
      hmax = MAX(hmax,a[i]);
      hmin = MIN(hmin,a[i]);
    }
  }
   
  if(K == 0)
  {
    res = hmax-hmin;
  }
  else if (N!=K)
  {
    long long tmp;
    if(hmin < lmin)
    {
      tmp = (lmin - hmin) * (a[0] == lmin || a[K-1] == lmin ? 1: 2);
      tmp = MIN(MIN(tmp,llabs(a[0]-hmin)),llabs(a[K-1]-hmin));
      res+=tmp;
    }
    if(hmax > lmax)
    {
      tmp = (hmax - lmax) * (a[0] == lmax || a[K-1] == lmax ? 1: 2);
      tmp = MIN(MIN(tmp,llabs(a[0]-hmax)),llabs(a[K-1]-hmax));
      res+=tmp;
    }
  }
  printf("%lld",res);
}
