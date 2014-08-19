main()
{
  char che[246913]={0};
  int prime[123456];
  long long i,j,k=0;
  for(i=2;i<=246912;i++)
  {
    if(che[i]==0)
    {
      prime[k++]=i;
      for(j=i*i;j<=246912;j+=i)che[j]=1;
    }
  }
  prime[k++]=987654;
  int n;
  for(;scanf("%d",&n),n;)
  {
    int s=0,t=2*n;
    for(i=0;prime[i]<=n;i++);
    for(;prime[i]<=t;i++)s++;
    printf("%d\n",s);
  }
}
