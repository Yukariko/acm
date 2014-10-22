cmp(long long *p,long long *q)
{
  return *p > *q? 1: *p < *q? -1: 0;
}
int N;
int seq[10001];
f(long long div)
{
  int i;
  long long sum;
  for(sum=i=0;i<N;i++)
  {
    sum+=seq[i];
    if(sum == div)
    {
      sum = 0;
    }
    else if(sum > div)
    {
      return 0;
    }
  }
  return 1;
}
main()
{
  int T;
  long long divisor[1001];
  int i,j,k;
  for(scanf("%d",&T);T--;)
  {
    long long n,sum=0;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
      scanf("%d",&seq[i]);
      sum+=seq[i];
    }
    j=0;
    for(n=1;n*n<=sum;n++)
    {
      if(sum%n==0)
      {
        divisor[j++]=n;
        if(n!=sum/n)divisor[j++]=sum/n;
      }
    }
    qsort(divisor,j,8,cmp);
    for(i=0;i<j;i++)
    {
      if(f(divisor[i]))
      {
        printf("%lld\n",divisor[i]);
        break;
      }
    }
    if(i==j)printf("%lld\n",sum);
  }
}

