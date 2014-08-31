main()
{
  int fibo[23];
  fibo[0]=1;
  fibo[1]=2;
  int i;
  for(i=2;fibo[i-1]<25000;i++)fibo[i]=fibo[i-1]+fibo[i-2];
  int t;
  for(scanf("%d",&t);t--;)
  {
    int j,k,s;
    scanf("%d",&k);
    s=0;
    for(j=i-1;j>=0;j--)
    {
      if(fibo[j]<=k)
      {
        k-=fibo[j];
        s+=1;
      }
      s<<=1;
    }
    s>>=2;
    for(j=0;s;s>>=1,j++)k+=fibo[j]*(s&1);
    printf("%d\n",k);
  }
}
