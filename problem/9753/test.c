main()
{
  char che[100001]={};
  int prime[10000];
  long long i,j,k=0;
  for(i=2;i<=100000;i++)
  {
    if(che[i]==0)
    {
      prime[k++]=i;
      for(j=i*i;j<=100000;j+=i)che[j]=1;
    }
  }
  int t;
  for(scanf("%d",&t);t--;)
  {
    int p;
    for(scanf("%d",&p);;p++)
    {
      for(i=0;i<k;i++)
      {
        if(prime[i]>=p)break;
        if(p%prime[i]==0&&che[p/prime[i]]==0&&prime[i]!=p/prime[i])break;
      }
      if(i<k&&prime[i]<p)break;
    }
    printf("%d\n",p);
  }
}
