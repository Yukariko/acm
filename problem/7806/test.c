main()
{
  int p;
  int a,b;
  long long i,j,k,s,t;
  for(;~scanf("%d%d",&a,&b);)
  {
    t=b;
    s=1;
    for(i=2;i*i<=t;i++)
    {
      p=0;
      for(;b%i==0;)
      {
        b/=i;
        p+=1;
      }
      if(p)
      {
        k=0;for(j=i;j<=a;j*=i)k+=a/j;
        for(j=p<k?p:k;j--;)s*=i;
      }
      if(b<2)break;
    }
    if(b>1&&b<=a)s*=b;
    printf("%d\n",s);
  }
}


