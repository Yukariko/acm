main()
{
  int n,k=0;
  long long s;
  long long i,j;
  char a[1000001]={0};
  int prime[78499];
  for(i=2;i<=1000000;i++)
  {
    if(a[i]==0)
    {
      prime[k++]=i;
      for(j=i*i;j<=1000000;j+=i)a[j]=1;
    }
  }
  for(scanf("%d",&n);n--;)
  {
    scanf("%lld",&s);
    for(i=0;i<k&&s%prime[i];i++);
    puts(i==k?"YES":"NO");
  }
}
