main()
{
  int m,n,k=0;
  long long i,j;
  char che[1000001]={0};
  int prime[78499];
  scanf("%d%d",&m,&n);
  for(i=2;i<=n;i++)
  {
    if(che[i]==0)
    {
      prime[k++]=i;
      for(j=i*i;j<=n;j+=i)che[j]=1;
    }
  }
  for(i=0;i<k;i++)
  {
    if(prime[i]>=m)printf("%d\n",prime[i]);
  }
}
