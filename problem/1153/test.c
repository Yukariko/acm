main()
{
  char che[1000001];
  int prime[78353];
  long long i,j,k=0,l;
  for(i=2;i<=1000000;i++)
  {
    if(che[i]==0)
    {
      prime[k++]=i;
      for(j=i*i;j<=1000000;j+=i)che[j]=1;
    }
  }
  int n,s;
  scanf("%d",&n);
  if(n<8)puts("-1");
  else if(n%2==0)
  {
    printf("2 2 ");
    n-=4;
  }
  else
  {
    printf("2 3 ");
    n-=5;
  }
  for(i=0;prime[i]<n;i++)
  {
    for(j=0;prime[j]<n;j++)
    {
      if(prime[i]+prime[j]==n)
      {
        printf("%d %d",prime[i],prime[j]);
        return 0;
      }
    }
  }  
}
