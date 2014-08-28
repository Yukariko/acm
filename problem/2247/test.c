#define M 1000001
int comp[M];
main()
{
  long long i,j,k;
  for(i=2;i<M;i++)
  {
    for(j=i*2;j<M;j+=i)
    {
      comp[j]+=i;
    }
  }
  int n;
  scanf("%d",&n);
  j=0;
  for(i=1;i<=n;i++)
  {
    j+=comp[i]+1+i;
    printf("%d %lld %lld\n",i,j,comp[i]+1+i);
  }
  printf("%lld %lld",j-n-n*(n+1)/2,n*(n+1)/2);
}
