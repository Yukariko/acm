char che[1000001];
main()
{
  int prime[78499];
  long long i,j,k=0;
  for(i=2;i<=1000000;i++)
  {
    if(che[i]==0)
    {
      prime[k++]=i;
      for(j=i*i;j<=1000000;j+=i)che[j]=1;
    }
  }
  int n;
  for(;scanf("%d",&n),n;)
  {
    j=n/2;
    for(i=0;prime[i]<=j;i++)
    {
      if(che[n-prime[i]]==0)
      {
        printf("%d = %d + %d\n",n,prime[i],n-prime[i]);
        break;
      }
    }
  }
}
