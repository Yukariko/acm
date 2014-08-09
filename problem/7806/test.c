main()
{
  int p[31623];
  int a,b;
  long long i,j,k,s,t;
  for(;~scanf("%d%d",&a,&b);)
  {
    t=sqrt(b)+1e-6;
    k=0;
    for(i=2;i<=t;i++)
    {
      p[i]=0;
      for(;b%i==0;)
      {
        b/=i;
        p[i]+=1;
        k=i;
      }
      if(b<2)break;
    }
    t=k;
    s=1;
    for(i=2;i<=t;i++)
    {
      if(p[i])
      {
        k=0;for(j=i;j<=a;j*=i)k+=a/j;
        for(j=p[i]<k?p[i]:k;j--;)s*=i;
      }
    }
    if(b>1&&b<=a)s*=b;
    printf("%d\n",s);
  }
}


