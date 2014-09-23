cmp(int *a,int *b){return *a>*b?1:*a<*b?-1:0;}
int n;
int a[15];
int visit[15];
int zero;
long long min;
f(int p,long long s)
{
  int i,j;
  long long k,t;
  for(k=i=j=0;i<n;i++)
  {
    if(visit[i]==0)
    {
      k=k*10+a[i];
      if(zero&&k&&j==0)
      {
        for(j=0;j<zero-zero/2;j++)k*=10;
        j=1;
      }
    }
  }
  if(k&&s)min=min>s+k?s+k:min;
  for(i=p;i<n;i++)
  {
    visit[i]=1;
    t=a[i];
    if(zero&&s==0)
    {
      for(j=0;j<zero/2;j++)t*=10;
      f(i+1,t);
    }
    else f(i+1,s*10+a[i]);
    visit[i]=0;
  }
}
main()
{
  for(;scanf("%d",&n),n;)
  {
    int i;
    for(i=0;i<n;i++)scanf("%d",a+i);
    qsort(a,n,4,cmp);
    for(zero=i=0;i<n;i++){if(a[i]==0)zero++;else break;}
    min=987654321;
    f(i,0);
    printf("%lld\n",min);
  }
}
