main()
{
  int n;
  int a[14144]={0};
  int prime[1001];
  int i,j,k=0,s=0;
  scanf("%d",&n);
  for(i=2;i<=n;i++)
  {
    if(a[i]==0)
    {
      prime[k++]=i;
      for(j=i*i;j<=n;j+=i)
      {
        a[j]=1;
      }
    }
  }
  for(i=0;i<k;i++)
  {
    int t;
    for(j=prime[i];j<=n;j*=prime[i])
    {
      t=j/prime[i];
      s=(s+(n/t - 1)*t)%1000000;
    }
  }
  printf("%d",s);
}
/*
main()
{
  int n;
  int i,j,s=0,k;
  int a[14144]={0};
  scanf("%d",&n);
  j=1;
  for(;j<=n;j++)
  {
    k=0;
    for(i=2;i*i<=j;i++)
    {
      if(j%i==0)
      {
        if(i!=j/i)k=(k+i+j/i)%1000000;
        else k=(k+i)%1000000;
      }
    }
    s=(s+k)%1000000;
    printf("%d %d\n",j,s);
  }
  
}
*/
